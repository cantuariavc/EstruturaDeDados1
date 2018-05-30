//
//  numeroAleatorio.h
//  Projeto 4
//
//  Created by Vinícius Cantuária on 29/05/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#ifndef numeroAleatorio_h
#define numeroAleatorio_h

#include <stdlib.h>
#include <time.h>
#include "memoria.h"

int geraNumeroAleatorio(int tamanhoMinimo, int tamanhoMaximo);
int eNumeroExistente(int *vetor, int tamanho, int numeroGerado);
int *geraVetorComNumerosAleatorios(int numeroMinimo, int NunumeroMaximo);

#endif /* numeroAleatorio_h */
