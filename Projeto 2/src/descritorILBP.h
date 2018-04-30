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

void converteMatrizDecimalBinario(int **matrizDecimal, int *frequenciaILBP);
void calculaMenorBinario(int **matrizBinaria, int *frequenciaILBP);
void calculaFrequenciaILBP(int menorNumero, int *frequenciaILBP);

#endif /* descritorILBP_h */
