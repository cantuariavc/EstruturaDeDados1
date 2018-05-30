//
//  fila.c
//  Projeto 4
//
//  Created by Vinícius Cantuária on 30/05/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#include "fila.h"

Fila *criaNovaFila(Voo *inicio, Voo *fim) {
    Fila *novaFila = alocaEstruturaFila();
    novaFila->inicio = inicio;
    novaFila->fim = fim;
    
    return novaFila;
}
