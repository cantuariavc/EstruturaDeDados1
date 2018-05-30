//
//  memoria.h
//  Projeto 4
//
//  Created by Vinícius Cantuária on 30/05/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#ifndef memoria_h
#define memoria_h

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Voo *alocaEstruturaVoo(void);
void verificaAlocacaoEstruturaVoo(Voo *estruturaVoo);
Fila *alocaEstruturaFila(void);
void verificaAlocacaoEstruturaFila(Fila *estruturaFila);

#endif /* memoria_h */
