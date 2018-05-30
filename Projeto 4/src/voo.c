//
//  voo.c
//  Projeto 4
//
//  Created by Vinícius Cantuária on 30/05/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#include "voo.h"

Voo *criaNovoVoo(char codigo[], char status, int quantidadeDeCombustivel, Voo *proximo) {
    Voo *novoVoo = alocaEstruturaVoo();
    for (int i = 0; i < 7; i++) {
        novoVoo->codigo[i] = codigo[i];
    }
    novoVoo->status = status;
    novoVoo->quantidadeDeCombustivel = quantidadeDeCombustivel;
    novoVoo->proximo = proximo;
    
    return novoVoo;
}
