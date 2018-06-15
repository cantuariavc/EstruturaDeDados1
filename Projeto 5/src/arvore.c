//
//  arvore.c
//  Projeto 5
//
//  Created by Vinícius Cantuária on 12/06/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#include "arvore.h"

No *loadTreeFromFile(char nomeDoArquivo[]) {
    FILE *arquivo = abreArquivo(nomeDoArquivo);
    if (arquivo == NULL) {
        return NULL;
    }
    
    No *raiz = NULL;
    int valor[QUANTIDADEDENUMEROS];
    
    for (int i = 0; i < QUANTIDADEDENUMEROS; i++) {
        fscanf(arquivo, "%d", (valor + i));
        insereNo(&raiz, valor[i]);
    }
    
    return raiz;
}

int searchValue(No *raiz, int valor) {
    int encontrado = 0;
    
    if (raiz != NULL) {
        if (raiz->valor == valor) {
            return 1;
        } else if (valor < raiz->valor && raiz->esquerda != NULL) {
            encontrado = searchValue(raiz->esquerda, valor);
        } else if (valor > raiz->valor && raiz->direita != NULL) {
            encontrado = searchValue(raiz->direita, valor);
        }
        
        if (encontrado == 1) {
            printf("Valor do pai: %d\n", raiz->valor);
            if (raiz->esquerda != NULL && valor == raiz->esquerda->valor && raiz->direita != NULL) {
                printf("Valor do irmão a direita: %d\n", raiz->direita->valor);
            } else if (raiz->direita != NULL && valor == raiz->direita->valor && raiz->esquerda != NULL) {
                printf("Valor do irmão a esquerda: %d\n", raiz->esquerda->valor);
            } else {
                printf("Não possue irmão.\n");
            }
            
            return 0;
        }
    } else {
        printf("Valor não encontrado!\n\n");
    }
    
    return encontrado;
}

void printInOrder(No *raiz) {
    if (raiz != NULL) {
        printInOrder(raiz->esquerda);
        printf("%d\t", raiz->valor);
        printInOrder(raiz->direita);
    }
}

void printPreOrder(No *raiz) {
    if (raiz != NULL) {
        printf("%d\t", raiz->valor);
        printPreOrder(raiz->esquerda);
        printPreOrder(raiz->direita);
    }
}
