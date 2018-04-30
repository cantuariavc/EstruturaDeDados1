//
//  descritorGLCM.c
//  Problema
//
//  Created by Vinícius Cantuária on 27/04/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#include "descritorGLCM.h"

void calculaFrequenciasGLCM(int **matrizDecimal, int **noroeste, int **norte, int **nordeste, int **oeste, int **leste, int **sudoeste, int **sul, int **sudeste) {
    *(*(noroeste + (*(*(matrizDecimal + 1) + 1))) + (*(*(matrizDecimal + 0) + 0))) += 1;
    *(*(norte + (*(*(matrizDecimal + 1) + 1))) + (*(*(matrizDecimal + 0) + 1))) += 1;
    *(*(nordeste + (*(*(matrizDecimal + 1) + 1))) + (*(*(matrizDecimal + 0) + 2))) += 1;
    *(*(oeste + (*(*(matrizDecimal + 1) + 1))) + (*(*(matrizDecimal + 1) + 0))) += 1;
    *(*(leste + (*(*(matrizDecimal + 1) + 1))) + (*(*(matrizDecimal + 1) + 2))) += 1;
    *(*(sudoeste + (*(*(matrizDecimal + 1) + 1))) + (*(*(matrizDecimal + 2) + 0))) += 1;
    *(*(sul + (*(*(matrizDecimal + 1) + 1))) + (*(*(matrizDecimal + 2) + 1))) += 1;
    *(*(sudeste + (*(*(matrizDecimal + 1) + 1))) + (*(*(matrizDecimal + 2) + 2))) += 1;
}

int calculaContraste(int **matriz) {
    int contraste = 0;
    
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            contraste += pow(abs(i - j), 2) * *(*(matriz + i) + j);
        }
    }
    
    return contraste;
}

int calculaEnergia(int **matriz) {
    int energia = 0;
    
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            energia += pow(*(*(matriz + i) + j), 2);
        }
    }
    
    return energia;
}

int calculaHomogeneidade(int **matriz) {
    int homogeneidade = 0;
    
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            homogeneidade += (*(*(matriz + i) + j)) / (1 + abs(i - j));
        }
    }
    
    return homogeneidade;
}
