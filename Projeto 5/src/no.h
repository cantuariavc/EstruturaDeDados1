//
//  folha.h
//  Projeto 5
//
//  Created by Vinícius Cantuária on 12/06/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#ifndef folha_h
#define folha_h

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *esquerda;
    struct no *direita;
} No;

No *criaNo(int valor, No *esquerda, No *direita);

#endif /* folha_h */
