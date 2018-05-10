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

void transfereContatosParaLista(FILE *contatos, No *lista) {
    char nomeCompleto[TAMANHONOMECOMPLETO];
    char telefoneCelular[TAMANHOTELEFONECELULAR];
    char endereco[TAMANHOENDERECO];
    int cep = 0;
    char dataDeNascimento[TAMANHODATADENASCIMENTO];
    char cifrao = '\0';
    
    while (fscanf(contatos, "%s\n%s\n%s\n%d\n%s\n%c", &nomeCompleto[0], &telefoneCelular[0], &endereco[0], &cep, &dataDeNascimento[0], &cifrao) != EOF) {
        insereNo(lista, nomeCompleto, telefoneCelular, endereco, cep, dataDeNascimento);
    }
}

void imprimeMenu(void) {
    printf("Menu");
    printf("\n");
    printf("1 - Inserir novo registro");
    printf("\n");
    printf("2 - Remover registros que possuem certo nome");
    printf("\n");
    printf("3 - Visualizar registro a partir do nome");
    printf("\n");
    printf("4 - Visualizar todos os registros em ordem alfabética de acordo com o nome");
    printf("\n");
    printf("0 - Sair");
    printf("\n");
    printf("Opção: ");
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
