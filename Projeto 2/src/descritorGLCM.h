//
//  descritorGLCM.h
//  Problema
//
//  Created by Vinícius Cantuária on 27/04/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#ifndef descritorGLCM_h
#define descritorGLCM_h

#include <stdlib.h>
#include <math.h>

void calculaFrequenciasGLCM(int **matrizDecimal, int **noroeste, int **norte, int **nordeste, int **oeste, int **leste, int **sudoeste, int **sul, int **sudeste);
double calculaContraste(int **matriz);
int calculaEnergia(int **matriz);
int calculaHomogeneidade(int **matriz);

#endif /* descritorGLCM_h */
