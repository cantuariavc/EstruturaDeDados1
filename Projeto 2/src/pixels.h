//
//  pixels.h
//  Problema
//
//  Created by Vinícius Cantuária on 28/04/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#ifndef pixels_h
#define pixels_h

#include "memoria.h"
#include "descritorILBP.h"
#include "descritorGLCM.h"

void calculaVizinhancasOito(int **imagemPrograma, int quantidadeLinhas, int quantidadeColunas, int *frequenciaILBP, int *metricasGLCM);

#endif /* pixels_h */
