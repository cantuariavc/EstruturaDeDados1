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

#define QUANTIDADEMINIMAAPROXIMACOES 10
#define QUANTIDADEMAXIMAAPROXIMACOES 32
#define QUANTIDADEMINIMADECOLAGENS 10
#define QUANTIDADEMAXIMADECOLAGENS 32
#define NIVELMAXIMOCOMBUSTIVEL 12

typedef struct voo {
    char codigo[7];
    char status;
    int quantidadeDeCombustivel;
    struct voo *proximo;
} Voo;

Voo *alocaEstruturaVoo(void);
void verificaAlocacaoEstruturaVoo(Voo *estruturaVoo);
Voo *criaNovoVoo(char codigo[], char status, int quantidadeDeCombustivel, Voo *proximo);

#endif /* voo_h */
