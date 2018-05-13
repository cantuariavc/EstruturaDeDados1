//
//  servicos.c
//  Projeto 3
//
//  Created by Vinícius Cantuária on 10/05/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#include "servicos.h"

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


int validaCelular(char telefoneCelular[]) {
    int eValido = 0;
    
    if (validaTamanhoCelular(telefoneCelular) && validaFormatoCelular(telefoneCelular) && validaCaracteresCelular(telefoneCelular)) {
        eValido = 1;
    }
    
    return eValido;
}

int validaTamanhoCelular(char telefoneCelular[]) {
    int eValido = 0;
    
    if (strlen(telefoneCelular) == (TAMANHOTELEFONECELULAR - 1)) {
        eValido = 1;
    }
    
    return eValido;
}

int validaFormatoCelular(char telefoneCelular[]) {
    int eValido = 0;

    if (telefoneCelular[5] == '-') {
        eValido = 1;
    }
    
    return eValido;
}

int validaCaracteresCelular(char telefoneCelular[]) {
    int eValido = 0;
    int quantidadeDeNumeros = 0;
    
    for (int i = 0; i < TAMANHOTELEFONECELULAR; i++) {
        if (telefoneCelular[i] == '0' || telefoneCelular[i] == '1' || telefoneCelular[i] == '2' || telefoneCelular[i] == '3' || telefoneCelular[i] == '4' ||
            telefoneCelular[i] == '5' || telefoneCelular[i] == '6' || telefoneCelular[i] == '7' || telefoneCelular[i] == '8' || telefoneCelular[i] == '9') {
            quantidadeDeNumeros++;
        }
    }
    
    if (quantidadeDeNumeros == (TAMANHOTELEFONECELULAR - 2)) {
        eValido = 1;
    }
    
    return eValido;
}


int validaCEP(char cep[]) {
    int eValido = 0;
    int quantidadeDeNumeros = 0;
    
    for (int i = 0; i < strlen(cep); i++) {
        if (cep[i] == '0' || cep[i] == '1' || cep[i] == '2' || cep[i] == '3' || cep[i] == '4' ||
            cep[i] == '5' || cep[i] == '6' || cep[i] == '7' || cep[i] == '8' || cep[i] == '9') {
            quantidadeDeNumeros++;
        }
    }
    
    if (strlen(cep) == quantidadeDeNumeros) {
        eValido = 1;
    }
    
    return eValido;
}


int validaDataDeNascimento(char dataDeNascimento[]) {
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
    
    if (validaFormatoDataDeNascimento(dataDeNascimento) && validaDia(dia) && validaMes(mes) && validaAno(ano)) {
        eValido = 1;
    }

    return eValido;
}

int validaFormatoDataDeNascimento(char dataDeNascimento[]) {
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
    int letrasIguais = 0;
    int saoIguais = 0;
    
    for (int i = 0; i < strlen(nomePesquisa); i++) {
        if (nomeNo[i] == nomePesquisa[i]) {
            letrasIguais++;
        }
    }
    
    if (letrasIguais == strlen(nomePesquisa)) {
        saoIguais = 1;
    }
    
    return saoIguais;
}
