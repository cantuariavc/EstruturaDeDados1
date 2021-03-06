//
//  voo.c
//  Projeto 4
//
//  Created by Vinícius Cantuária on 30/05/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#include "voo.h"

Voo *alocaEstruturaVoo() {
    Voo *estruturaVoo = (Voo *) calloc(1, sizeof(Voo));
    verificaAlocacaoEstruturaVoo(estruturaVoo);
    
    return estruturaVoo;
}

void verificaAlocacaoEstruturaVoo(Voo *estruturaVoo) {
    if (estruturaVoo == NULL) {
        printf("Erro na alocação da memória da estrutura Voo!\n");
        exit(1);
    }
}

Voo *criaNovoVoo(char codigo[], char status, int quantidadeDeCombustivel, Voo *proximo) {
    Voo *novoVoo = alocaEstruturaVoo();
    for (int i = 0; i < 6; i++) {
        novoVoo->codigo[i] = codigo[i];
    }
    novoVoo->codigo[6] = '\0';
    novoVoo->status = status;
    novoVoo->quantidadeDeCombustivel = quantidadeDeCombustivel;
    novoVoo->proximo = proximo;
    
    return novoVoo;
}
