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
    
    int numeroGerado = tamanhoMinimo + (rand() % ((tamanhoMaximo - tamanhoMinimo) + 1));
    
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

int *geraVetorComNumerosAleatorios(int tamanhoVetor) {
    int *vetorNumerosAleatorios = alocaInt(tamanhoVetor);
    int numeroGerado = 0;
    
    for (int i = 0; i < tamanhoVetor; i++) {
        numeroGerado = geraNumeroAleatorio(0, 63);
        while (eNumeroExistente(vetorNumerosAleatorios, i, numeroGerado)) {
            numeroGerado = geraNumeroAleatorio(0, 63);
        }
        *(vetorNumerosAleatorios + i) = numeroGerado;
    }
    
    return vetorNumerosAleatorios;
}
