//
//  folha.c
//  Projeto 5
//
//  Created by Vinícius Cantuária on 12/06/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#include "no.h"

No *criaNo(int valor, No *esquerda, No *direita) {
    No *novoNo = (No *) calloc(1, sizeof(No));
    
    if (novoNo == NULL) {
        printf("Erro na alocação de memória do Nó!");
        exit(2);
    }
    
    novoNo->valor = valor;
    novoNo->esquerda = esquerda;
    novoNo->direita = direita;
    
    return novoNo;
}

void insereNo(No **raiz, int valor) {
    if (*raiz != NULL) {
        if (valor < (*raiz)->valor) {
            insereNo(&(*raiz)->esquerda, valor);
        } else {
            insereNo(&(*raiz)->direita, valor);
        }
        
    } else {
        No *novoNo = criaNo(valor, NULL, NULL);
        *raiz = novoNo;
    }
}
