//
//  servicos.c
//  Projeto 3
//
//  Created by Vinícius Cantuária on 10/05/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#include "servicos.h"

void verificaAlocacaoArquivo(FILE *nomeArquivo) {
    if (nomeArquivo == NULL) {
        printf("Erro na abertura da arquivo!\n");
        exit(1);
    }
}

No *transfereContatosParaLista(FILE *contatos, No *lista) {
    char nomeCompleto[TAMANHONOMECOMPLETO];
    char telefoneCelular[TAMANHOTELEFONECELULAR];
    char endereco[TAMANHOENDERECO];
    int cep = 0;
    char dataDeNascimento[TAMANHODATADENASCIMENTO];
    int cifrao;
    
    while (1) {
        fgets(nomeCompleto, TAMANHONOMECOMPLETO, contatos);
        fscanf(contatos, "%s", telefoneCelular);
        fgetc(contatos);
        fgets(endereco, TAMANHOENDERECO, contatos);
        fscanf(contatos, "%d", &cep);
        fgetc(contatos);
        fscanf(contatos, "%s", dataDeNascimento);
        fgetc(contatos);
        cifrao = fgetc(contatos);

        lista = insereNo(lista, nomeCompleto, telefoneCelular, endereco, cep, dataDeNascimento);
        
        if (fgetc(contatos) == EOF) {
            break;
        }
    }
    
    return lista;
}


void imprimeMenu(int *opcao) {
    printf("Menu");
    printf("\n");
    printf("1 - Inserir novo registro");
    printf("\n");
    printf("2 - Remover registros por nome");
    printf("\n");
    printf("3 - Visualizar registros por nome");
    printf("\n");
    printf("4 - Visualizar todos os registros");
    printf("\n");
    printf("0 - Sair");
    printf("\n");
    printf("Opção: ");
    scanf("%d", opcao);
    getchar();
    printf("\n");
}

void insereNovoRegistro(No *lista) {
    char nomeCompleto[TAMANHONOMECOMPLETO];
    char telefoneCelular[TAMANHOTELEFONECELULAR];
    char endereco[TAMANHOENDERECO];
    int cep;
    char dataDeNascimento[TAMANHODATADENASCIMENTO];
    
    printf("Nome completo: ");
    fgets(nomeCompleto, TAMANHONOMECOMPLETO, stdin);
    
    do {
        printf("Telefone celular (55555-5555): ");
        fgets(telefoneCelular, TAMANHOTELEFONECELULAR, stdin);
        getchar();
    } while (!validaCelular(telefoneCelular));
    
    printf("Endereço: ");
    fgets(endereco, TAMANHOENDERECO, stdin);
    printf("CEP (somente os números): ");
    scanf("%d", &cep);
    getchar();
    
    do {
        printf("Data de nascimento (dd/mm/aaaa): ");
        fgets(dataDeNascimento, TAMANHODATADENASCIMENTO, stdin);
        getchar();
    } while (!validaDataDeNacimento(dataDeNascimento));
    
    printf("\n");
    insereNo(lista, nomeCompleto, telefoneCelular, endereco, cep, dataDeNascimento);
}


int validaCelular(char telefoneCelular[]) {
    int eValido = 0;
    
    if (telefoneCelular[5] == '-') {
        eValido = 1;
    }
    
    return eValido;
}

int validaDataDeNacimento(char dataDeNascimento[]) {
    int eValido = 0;
    
    char diaString[2];
    diaString[0] = dataDeNascimento[0];
    diaString[1] = dataDeNascimento[1];
    int dia = atoi(&diaString[0]);
    
    char mesString[2];
    mesString[0] = dataDeNascimento[3];
    mesString[1] = dataDeNascimento[4];
    int mes = atoi(&mesString[0]);

    char anoString[4];
    anoString[0] = dataDeNascimento[6];
    anoString[1] = dataDeNascimento[7];
    anoString[2] = dataDeNascimento[8];
    anoString[3] = dataDeNascimento[9];
    int ano = atoi(&anoString[0]);
    
    if (validaFormato(dataDeNascimento) && validaDia(dia) && validaMes(mes) && validaAno(ano)) {
        eValido = 1;
    }

    return eValido;
}

int validaFormato(char dataDeNascimento[]) {
    int eValido = 0;

    if (dataDeNascimento[2] == '/' && dataDeNascimento[5] == '/') {
        eValido = 1;
    }
    
    return eValido;
}

int validaDia(int dia) {
    int eValido = 0;

    if (dia >= 1 && dia <= 31) {
        eValido = 1;
    }
    
    return eValido;
}

int validaMes(int mes) {
    int eValido = 0;

    if (mes >= 1 && mes <= 12) {
        eValido = 1;
    }
    
    return eValido;
}

int validaAno(int ano) {
    int eValido = 0;
    
    if (ano >= 1910 && ano <= 2018) {
        eValido = 1;
    }
    
    return eValido;
}

int verificaNome(char nomeNo[], char nomePesquisa[]) {
    int tamanhoNomePesquisa = 0;
    int letrasIguais = 0;
    int saoIguais = 0;
    
    for (int i = 0; i < TAMANHONOMECOMPLETO; i++) {
        if (nomePesquisa[i] == '\0') {
            tamanhoNomePesquisa = i;
            break;
        }
    }
    
    for (int i = 0; i < tamanhoNomePesquisa; i++) {
        if (nomeNo[i] == nomePesquisa[i]) {
            letrasIguais++;
        }
    }
    
    if (letrasIguais == tamanhoNomePesquisa) {
        saoIguais = 1;
    }
    
    return saoIguais;
}
