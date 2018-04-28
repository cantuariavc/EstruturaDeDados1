//
//  memoria.c
//  Problema
//
//  Created by Vinícius Cantuária on 27/04/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#include "memoria.h"

int *alocaInt(int tamanho) {
    int *vetorInt = (int *) calloc(tamanho, sizeof(int));
    verificaAlocacaoInt(vetorInt);
    
    return vetorInt;
}

char *alocaChar(int tamanho) {
    char *vetorChar = (char *) calloc(tamanho, sizeof(char));
    verificaAlocacaoChar(vetorChar);
    
    return vetorChar;
}

int **alocaMatriz(int quantidadeLinhas, int quantidadeColunas) {
    int **matriz = (int **) calloc(quantidadeLinhas, sizeof(int *));
    verificaAlocacaoMatriz(matriz);
    for (int k = 0; k < quantidadeLinhas; k++) {
        *(matriz + k) = (int *) calloc(quantidadeColunas, sizeof(int));
        verificaAlocacaoInt(*(matriz + k));
    }
    
    return matriz;
}


void verificaAlocacaoInt(int *vetorAlocado) {
    if (vetorAlocado == NULL) {
        printf("Erro na alocação da memória do vetor int!\n");
        exit(1);
    }
}

void verificaAlocacaoChar(char *vetorAlocado) {
    if (vetorAlocado == NULL) {
        printf("Erro na alocação da memória do vetor char!\n");
        exit(1);
    }
}

void verificaAlocacaoMatriz(int **matrizAlocada) {
    if (matrizAlocada == NULL) {
        printf("Erro na alocação da memória da matriz!\n");
        exit(1);
    }
}

void verificaAlocacaoArquivo(FILE *nomeArquivo) {
    if (nomeArquivo == NULL) {
        printf("Erro na abertura da arquivo!\n");
        exit(1);
    }
}


void liberaMatriz(int **matrizAlocada, int quantidadeLinhas) {
    for (int i = 0; i < quantidadeLinhas; i++) {
        free(*(matrizAlocada + i));
    }
    
    free(matrizAlocada);
}
