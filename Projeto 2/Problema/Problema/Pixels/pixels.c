//
//  pixels.c
//  Problema
//
//  Created by Vinícius Cantuária on 28/04/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#include "pixels.h"

void calculaVizinhancasOito(int **imagemPrograma, int quantidadeLinhas, int quantidadeColunas, int *frequenciaILBP) {
    int **noroeste = alocaMatriz(256, 256);
    int **norte = alocaMatriz(256, 256);
    int **nordeste = alocaMatriz(256, 256);
    int **oeste = alocaMatriz(256, 256);
    int **leste = alocaMatriz(256, 256);
    int **sudoeste = alocaMatriz(256, 256);
    int **sul = alocaMatriz(256, 256);
    int **sudeste = alocaMatriz(256, 256);
    
    for (int i = 1; i < (quantidadeLinhas - 1); i++) {
        for (int j = 1; j < (quantidadeColunas - 1); j++) {
            int **matrizDecimal = alocaMatriz(3, 3);
            
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    *(*(matrizDecimal + k) + l) = *(*(imagemPrograma + (i + (k - 1))) + (j + (l - 1)));
                }
            }
            
            converteMatrizDecimalBinario(matrizDecimal, frequenciaILBP);
            calculaFrequenciasGLCM(matrizDecimal, noroeste, norte, nordeste, oeste, leste, sudoeste, sul, sudeste);
            
            liberaMatriz(matrizDecimal, 3);
        }
    }
    
    liberaMatriz(noroeste, 256);
    liberaMatriz(norte, 256);
    liberaMatriz(nordeste, 256);
    liberaMatriz(oeste, 256);
    liberaMatriz(leste, 256);
    liberaMatriz(sudoeste, 256);
    liberaMatriz(sul, 256);
    liberaMatriz(sudeste, 256);
}
