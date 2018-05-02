//
//  pixels.c
//  Problema
//
//  Created by Vinícius Cantuária on 28/04/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#include "pixels.h"

void calculaVizinhancasOito(int **imagemPrograma, int quantidadeLinhas, int quantidadeColunas, int *frequenciaILBP, int *metricasGLCM) {
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
            
            int **matrizBinaria = converteMatrizDecimalBinario(matrizDecimal);
            int menorNumero = calculaMenorNumero(matrizBinaria);

            calculaFrequenciaILBP(menorNumero, frequenciaILBP);
            calculaFrequenciasGLCM(matrizDecimal, noroeste, norte, nordeste, oeste, leste, sudoeste, sul, sudeste);
            
            liberaMatriz(matrizDecimal, 3);
            liberaMatriz(matrizBinaria, 3);
        }
    }
    
    *(metricasGLCM + 0) = calculaContraste(noroeste);
    *(metricasGLCM + 1) = calculaEnergia(noroeste);
    *(metricasGLCM + 2) = calculaHomogeneidade(noroeste);

    *(metricasGLCM + 3) = calculaContraste(norte);
    *(metricasGLCM + 4) = calculaEnergia(norte);
    *(metricasGLCM + 5) = calculaHomogeneidade(norte);

    *(metricasGLCM + 6) = calculaContraste(nordeste);
    *(metricasGLCM + 7) = calculaEnergia(nordeste);
    *(metricasGLCM + 8) = calculaHomogeneidade(nordeste);

    *(metricasGLCM + 9) = calculaContraste(oeste);
    *(metricasGLCM + 10) = calculaEnergia(oeste);
    *(metricasGLCM + 11) = calculaHomogeneidade(oeste);

    *(metricasGLCM + 12) = calculaContraste(leste);
    *(metricasGLCM + 13) = calculaEnergia(leste);
    *(metricasGLCM + 14) = calculaHomogeneidade(leste);

    *(metricasGLCM + 15) = calculaContraste(sudoeste);
    *(metricasGLCM + 16) = calculaEnergia(sudoeste);
    *(metricasGLCM + 17) = calculaHomogeneidade(sudoeste);

    *(metricasGLCM + 18) = calculaContraste(sul);
    *(metricasGLCM + 19) = calculaEnergia(sul);
    *(metricasGLCM + 20) = calculaHomogeneidade(sul);

    *(metricasGLCM + 21) = calculaContraste(sudeste);
    *(metricasGLCM + 22) = calculaEnergia(sudeste);
    *(metricasGLCM + 23) = calculaHomogeneidade(sudeste);
    
    liberaMatriz(noroeste, 256);
    liberaMatriz(norte, 256);
    liberaMatriz(nordeste, 256);
    liberaMatriz(oeste, 256);
    liberaMatriz(leste, 256);
    liberaMatriz(sudoeste, 256);
    liberaMatriz(sul, 256);
    liberaMatriz(sudeste, 256);
}
