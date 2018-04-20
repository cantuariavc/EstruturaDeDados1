//
//  main.c
//  Problema 1
//
//  Created by Vinícius Cantuária on 17/04/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//
// Mateus de Oliveira Barbosa - 14/0154817
// Vinícius de Castro Cantuária - 14/0165169
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void verificaAlocacao(int *vetorAlocado);
void liberaMemoria(int *vetorAlocado);
void geraNumerosAleatorios(int *vetorNumerosTreinamento, int *vetorNumerosTeste);
int numeroExistente(int *vetorNumerosAleatorios, int tamanho, int numnumeroGeradoero);

int main(int argc, const char * argv[]) {
    FILE *imagem;
    
    int *vetorNumerosTreinamento = (int *) calloc(25, sizeof(int));
    int *vetorNumerosTeste = (int *) calloc(25, sizeof(int));
    
    verificaAlocacao(vetorNumerosTreinamento);
    verificaAlocacao(vetorNumerosTeste);
    geraNumerosAleatorios(vetorNumerosTreinamento, vetorNumerosTeste);
    
    
    liberaMemoria(vetorNumerosTreinamento);
    liberaMemoria(vetorNumerosTeste);
    
    return 0;
}

void verificaAlocacao(int *vetorAlocado) {
    if (vetorAlocado == NULL) {
        exit(1);
    }
}

void liberaMemoria(int *vetorAlocado) {
    free(vetorAlocado);
}

void geraNumerosAleatorios(int *vetorNumerosTreinamento, int *vetorNumerosTeste) {
    srand((unsigned int)time(NULL));
    
    int *vetorNumerosAleatorios = (int *) calloc(50, sizeof(int));
    int numeroGerado = 0;
    
    verificaAlocacao(vetorNumerosAleatorios);
    
    for (int i = 0; i < 50; i++) {
        numeroGerado = 1 + (rand() % 50);
        
        while (numeroExistente(vetorNumerosAleatorios, i, numeroGerado)) {
            numeroGerado = 1 + (rand() % 50);
        }
        
        *(vetorNumerosAleatorios + i) = numeroGerado;
    }
    
    for (int i = 0; i < 25; i++) {
        *(vetorNumerosTreinamento + i) = *(vetorNumerosAleatorios + i);
    }
    
    for (int i = 0; i < 25; i++) {
        *(vetorNumerosTeste + i) = *(vetorNumerosAleatorios + (i + 25));
    }
    
    liberaMemoria(vetorNumerosAleatorios);
}

int numeroExistente(int *vetorNumerosAleatorios, int tamanho, int numnumeroGeradoero) {
    int existe = 0;
    
    for (int i = 0; i < tamanho; i++) {
        if (*(vetorNumerosAleatorios + i) == numnumeroGeradoero) {
            existe = 1;
        }
    }
    
    return existe;
}





