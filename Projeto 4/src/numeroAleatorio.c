//
//  numeroAleatorio.c
//  Projeto 4
//
//  Created by Vinícius Cantuária on 29/05/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#include "numeroAleatorio.h"

int geraNumeroAleatorio(int tamanhoMinimo, int tamanhoMaximo) {
    srand((unsigned int)time(NULL));
    
    int numeroGerado = tamanhoMinimo + (rand() % tamanhoMaximo);
    
    return numeroGerado;
}

int eNumeroExistente(int *vetor, int tamanho, int numeroGerado) {
    int existe = 0;
    
    for (int i = 0; i < tamanho; i++) {
        if (*(vetor + i) == numeroGerado) {
            existe = 1;
        }
    }
    
    return existe;
}

int *geraVetorComNumerosAleatorios(int numeroMinimo, int NunumeroMaximo) {
    int tamanhoVetor = geraNumeroAleatorio(numeroMinimo, NunumeroMaximo);
    int *vetorNumerosAleatorios = (int *) calloc(tamanhoVetor, sizeof(int));
    int numeroGerado = 0;
    
    for (int i = 0; i < tamanhoVetor; i++) {
        numeroGerado = geraNumeroAleatorio(1, 64);
        while (eNumeroExistente(vetorNumerosAleatorios, i, numeroGerado)) {
            numeroGerado = geraNumeroAleatorio(1, 64);
        }
        *(vetorNumerosAleatorios + i) = numeroGerado;
    }
    
    return vetorNumerosAleatorios;
}
