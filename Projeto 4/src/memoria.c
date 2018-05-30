//
//  memoria.c
//  Projeto 4
//
//  Created by Vinícius Cantuária on 30/05/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#include "memoria.h"

Voo *alocaEstruturaVoo() {
    Voo *estruturaVoo = (Voo *) calloc(1, sizeof(Voo));
    verificaAlocacaoEstruturaVoo(estruturaVoo);
    
    return estruturaVoo;
}

void verificaAlocacaoEstruturaVoo(Voo *estruturaVoo) {
    if (estruturaVoo == NULL) {
        printf("Erro na alocação da memória do estrutura Voo!\n");
        exit(1);
    }
}
