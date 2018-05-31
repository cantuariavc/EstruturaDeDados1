//
//  fila.c
//  Projeto 4
//
//  Created by Vinícius Cantuária on 30/05/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#include "fila.h"

Fila *alocaEstruturaFila() {
    Fila *estruturaFila = (Fila *) calloc(1, sizeof(Fila));
    verificaAlocacaoEstruturaFila(estruturaFila);
    
    return estruturaFila;
}

void verificaAlocacaoEstruturaFila(Fila *estruturaFila) {
    if (estruturaFila == NULL) {
        printf("Erro na alocação da memória da estrutura Fila!\n");
        exit(1);
    }
}

Fila *criaNovaFila(Voo *inicio, Voo *fim) {
    Fila *novaFila = alocaEstruturaFila();
    novaFila->inicio = inicio;
    novaFila->fim = fim;
    
    return novaFila;
}

Fila *insereNovoVooNaFila(Fila *fila, Voo *novoVoo) {
    Voo *aux = fila->inicio;
    
    if (novoVoo->quantidadeDeCombustivel < fila->inicio->quantidadeDeCombustivel) {
        novoVoo->proximo = fila->inicio;
        fila->inicio = novoVoo;
    } else if (novoVoo->quantidadeDeCombustivel > fila->fim->quantidadeDeCombustivel) {
        fila->fim->proximo = novoVoo;
        fila->fim = novoVoo;
    } else {
        while (aux->proximo->quantidadeDeCombustivel < novoVoo->quantidadeDeCombustivel) {
            aux = aux->proximo;
        }
        novoVoo->proximo = aux->proximo;
        aux->proximo = novoVoo;
    }
    
    return fila;
}
