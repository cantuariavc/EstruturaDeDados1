//
//  numeroAleatorio.c
//  Projeto 4
//
//  Created by Vinícius Cantuária on 29/05/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#include "numeroAleatorio.h"

int geraNumeroAleatorio(int tamanhoMinimo, int tamanhoMaximo) {
    srand((unsigned int)time(NULL));
    
    int numeroGerado = tamanhoMinimo + (rand() % tamanhoMaximo);
    
    return numeroGerado;
}
