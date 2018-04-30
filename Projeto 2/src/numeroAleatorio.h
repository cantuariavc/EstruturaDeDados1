//
//  numeroAleatorio.h
//  Problema
//
//  Created by Vinícius Cantuária on 27/04/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#ifndef numeroAleatorio_h
#define numeroAleatorio_h

#include <time.h>
#include "memoria.h"
#define QUANTIDADEIMAGENS 50

void geraNumerosAleatorios(int *vetorNumerosTreinamento, int *vetorNumerosTeste);
int eNumeroExistente(int *vetorNumerosAleatorios, int tamanho, int numeroGerado);

#endif /* numeroAleatorio_h */
