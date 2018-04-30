//
//  numeroAleatorio.c
//  Problema
//
//  Created by Vinícius Cantuária on 27/04/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#include "numeroAleatorio.h"

void geraNumerosAleatorios(int *vetorNumerosTreinamento, int *vetorNumerosTeste) {
    srand((unsigned int)time(NULL));
    
    int *vetorNumerosAleatorios = alocaInt(QUANTIDADEIMAGENS);
    int numeroGerado = 0;
    
    for (int i = 0; i < QUANTIDADEIMAGENS; i++) {
        numeroGerado = 1 + (rand() % QUANTIDADEIMAGENS);
        
        while (eNumeroExistente(vetorNumerosAleatorios, i, numeroGerado)) {
            numeroGerado = 1 + (rand() % QUANTIDADEIMAGENS);
        }
        
        *(vetorNumerosAleatorios + i) = numeroGerado;
    }
    
    for (int i = 0; i < QUANTIDADETREINAMENTOS; i++) {
        *(vetorNumerosTreinamento + i) = *(vetorNumerosAleatorios + i);
    }
    
    for (int i = 0; i < QUANTIDADETESTES; i++) {
        *(vetorNumerosTeste + i) = *(vetorNumerosAleatorios + (i + QUANTIDADETREINAMENTOS));
    }
    
    free(vetorNumerosAleatorios);
}

int eNumeroExistente(int *vetorNumerosAleatorios, int tamanho, int numeroGerado) {
    int existe = 0;
    
    for (int i = 0; i < tamanho; i++) {
        if (*(vetorNumerosAleatorios + i) == numeroGerado) {
            existe = 1;
        }
    }
    
    return existe;
}
