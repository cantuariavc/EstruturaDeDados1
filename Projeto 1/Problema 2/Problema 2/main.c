//
//  main.c
//  Problema 2
//
//  Created by Vinícius Cantuária on 29/03/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//
// Mateus de Oliveira Barbosa - 14/0154817
// Vinícius de Castro Cantuária - 14/0165169
//

#include <stdio.h>
#include <stdlib.h>
#define QUANTIDADENOTAS 10

int *recebe_notas(int *NOTAS, int quantidadeElementosNotas);
void conta_notas(int *APR, int quantidadeElementosAPR, int *numeroAprovados, int *numeroReprovados);
int percent_aprov(int numeroAprovados, float *porcentagemAprovados, int numeroReprovados, float *porcentagemReprovados);
void solicitaNotas(int *NOTAS);
void mostraResumo(int numeroAprovados, float porcentagemAprovados, int numeroReprovados, float porcentagemReprovados);
void verificaAlocacao(int *NOTAS, int *APR);
void liberaMemoria(int *NOTAS, int *APR);

int main(int argc, const char * argv[]) {
    int numeroAprovados = 0;
    float porcentagemAprovados = 0.0;
    int numeroReprovados = 0;
    float porcentagemReprovados = 0.0;
    int *NOTAS = (int *) malloc(QUANTIDADENOTAS * sizeof(int));
    int *APR = (int *) malloc(QUANTIDADENOTAS * sizeof(int));
    
    verificaAlocacao(NOTAS, APR);
    solicitaNotas(NOTAS);
    APR = recebe_notas(NOTAS, QUANTIDADENOTAS);
    conta_notas(APR, QUANTIDADENOTAS, &numeroAprovados, &numeroReprovados);
    percent_aprov(numeroAprovados, &porcentagemAprovados, numeroReprovados, &porcentagemReprovados);
    mostraResumo(numeroAprovados, porcentagemAprovados, numeroReprovados, porcentagemReprovados);
    liberaMemoria(NOTAS, APR);
    
    return 0;
}

int *recebe_notas(int *NOTAS, int quantidadeElementosNotas) {
    int *APR = (int *) malloc(quantidadeElementosNotas * sizeof(int));
    
    for (int i = 0; i < quantidadeElementosNotas; i++) {
        if (*(NOTAS + i) >= 6) {
            *(APR + i) = 1;
        } else {
            *(APR + i) = 0;
        }
    }
    
    return APR;
}

void conta_notas(int *APR, int quantidadeElementosAPR, int *numeroAprovados, int *numeroReprovados) {
    for (int i = 0; i < quantidadeElementosAPR; i++) {
        if (*(APR + i) == 1) {
            *numeroAprovados += 1;
        } else {
            *numeroReprovados += 1;
        }
    }
}

int percent_aprov(int numeroAprovados, float *porcentagemAprovados, int numeroReprovados, float *porcentagemReprovados) {
    *porcentagemAprovados = numeroAprovados / (numeroAprovados + numeroReprovados);
    *porcentagemReprovados = 1 - *porcentagemAprovados;
    
    if (*porcentagemAprovados > 50) {
        return 1;
    } else {
        return 0;
    }
}

void solicitaNotas(int *NOTAS) {
    for (int i = 0; i < QUANTIDADENOTAS; i++) {
        printf("Digite o valor da nota %d: ", (i + 1));
        scanf("%d", (NOTAS + i));
    }
}

void mostraResumo(int numeroAprovados, float porcentagemAprovados, int numeroReprovados, float porcentagemReprovados) {
    printf("\n");
    printf("Quantidade de aprovados: %d\n", numeroAprovados);
    printf("Percentual de aprovados: %f\n", porcentagemAprovados);
    printf("Quantidade de reprovados: %d\n", numeroReprovados);
    printf("Percentual de reprovados: %f\n", porcentagemReprovados);
    
    if (porcentagemAprovados > 50) {
        printf("Mais da metade da turma foi APROVADA!");
    } else {
        printf("Mais da metade da turma foi REPROVADA!");
    }
    printf("\n");
}

void verificaAlocacao(int *NOTAS, int *APR) {
    if (NOTAS == NULL || APR == NULL) {
        exit(1);
    }
}

void liberaMemoria(int *NOTAS, int *APR) {
    free(NOTAS);
    free(APR);
}
