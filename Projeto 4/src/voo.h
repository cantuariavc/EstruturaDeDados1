//
//  voo.h
//  Projeto 4
//
//  Created by Vinícius Cantuária on 29/05/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#ifndef voo_h
#define voo_h

#include "memoria.h"

typedef struct voo {
    char codigo[7];
    char status;
    int quantidadeDeCombustivel;
    struct voo *proximo;
} Voo;

Voo *criaNovoVoo(char codigo[], char status, int quantidadeDeCombustivel, Voo *proximo);

#endif /* voo_h */
