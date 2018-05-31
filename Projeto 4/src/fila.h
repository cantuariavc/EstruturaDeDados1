//
//  fila.h
//  Projeto 4
//
//  Created by Vinícius Cantuária on 29/05/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#ifndef fila_h
#define fila_h

#include "voo.h"

typedef struct fila {
    Voo *inicio;
    Voo *fim;
} Fila;

Fila *alocaEstruturaFila(void);
void verificaAlocacaoEstruturaFila(Fila *estruturaFila);
Fila *criaNovaFila(Voo *inicio, Voo *fim);

#endif /* fila_h */
