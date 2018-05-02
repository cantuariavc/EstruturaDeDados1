//
//  descritorILBP.h
//  Problema
//
//  Created by Vinícius Cantuária on 27/04/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#ifndef descritorILBP_h
#define descritorILBP_h

#include <math.h>
#include "memoria.h"

int **converteMatrizDecimalBinario(int **matrizDecimal);
int calculaMenorNumero(int **matrizBinaria);
void calculaFrequenciaILBP(int menorNumero, int *frequenciaILBP);

#endif /* descritorILBP_h */
