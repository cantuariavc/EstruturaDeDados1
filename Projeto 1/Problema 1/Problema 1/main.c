//
//  main.c
//  Problema 1
//
//  Created by Vinícius Cantuária on 29/03/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define QUANTIDADELIMITE 10

void fneuronio(int *ENTRADAS, int *PESOS, int *T, int quantidadeElementosEntradas, int *StatusNeuronio);
void solicitaEntradas(int *ENTRADAS);
void solicitaPesos(int *PESOS);
void solicitaLimiarT(int *T);
void mostraStatusNeuronio(int *StatusNeuronio);



int main(int argc, const char * argv[]) {
    int *ENTRADAS = (int *) malloc(QUANTIDADELIMITE * sizeof(int));
    int *PESOS = (int *) malloc(QUANTIDADELIMITE * sizeof(int));
    int T = 0;
    int StatusNeuronio = 0;
    
    solicitaEntradas(ENTRADAS);
    solicitaPesos(PESOS);
    solicitaLimiarT(&T);
    fneuronio(ENTRADAS, PESOS, &T, QUANTIDADELIMITE, &StatusNeuronio);
    mostraStatusNeuronio(&StatusNeuronio);
    
    return 0;
}

void fneuronio(int *ENTRADAS, int *PESOS, int *T, int quantidadeElementosEntradas, int *StatusNeuronio) {
    int SOMAP = 0;
    
    for (int i = 0; i < quantidadeElementosEntradas; i++) {
        SOMAP += *(ENTRADAS + i) * *(PESOS + i);
    }
    
    if (SOMAP > *T) {
        *StatusNeuronio = 1;
    } else {
        *StatusNeuronio = 0;
    }
}

void solicitaEntradas(int *ENTRADAS) {
    for (int i = 0; i < QUANTIDADELIMITE; i++) {
        printf("Digite o valor da entrada %d: ", (i + 1));
        scanf("%d", (ENTRADAS + i));
    }
}

void solicitaPesos(int *PESOS) {
    for (int i = 0; i < QUANTIDADELIMITE; i++) {
        printf("Digite o valor do peso %d: ", (i + 1));
        scanf("%d", (PESOS + i));
    }
}

void solicitaLimiarT(int *T) {
    printf("Digite o valor limiar T: ");
    scanf("%d", T);
}

void mostraStatusNeuronio(int *StatusNeuronio) {
    if (*StatusNeuronio == 1) {
        printf("Neurônio ativado!");
    } else {
        printf("Neurôno inibido!");
    }
}
