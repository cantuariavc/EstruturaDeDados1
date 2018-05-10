//
//  lista.c
//  Projeto 3
//
//  Created by Vinícius Cantuária on 10/05/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#include "lista.h"

struct no {
    char nomeCompleto[101];
    char celular[11];
    char endereco[101];
    char cep[9];
    char dataDeNacimento[11];
    struct no *anterior;
    struct no *proximo;
};

