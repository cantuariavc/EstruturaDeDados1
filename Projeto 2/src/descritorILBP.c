//
//  descritorILBP.c
//  Problema
//
//  Created by Vinícius Cantuária on 27/04/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#include "descritorILBP.h"

void converteMatrizDecimalBinario(int **matrizDecimal, int *frequenciaILBP) {
    int media = 0;
    
    int **matrizBinaria = alocaMatriz(3, 3);
    
    for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
            media += *(*(matrizDecimal + k) + l);
        }
    }
    
    media /= 9;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (*(*(matrizDecimal + i) + j) >= media) {
                *(*(matrizBinaria + i) + j) = 1;
            } else {
                *(*(matrizBinaria + i) + j) = 0;
            }
        }
    }
    
    calculaMenorBinario(matrizBinaria, frequenciaILBP);
    
    liberaMatriz(matrizBinaria, 3);
}

void calculaMenorBinario(int **matrizBinaria, int *frequenciaILBP) {
    int *binario = alocaInt(9);
    int indice = 0;
    int expoente = 0;
    int decimal = 0;
    int menorNumero = 511;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++, indice++) {
            *(binario + indice) = *(*(matrizBinaria + i) + j);
        }
    }
    
    for (int i = 0; i < 9; i++) {
        expoente = 0;
        decimal = 0;
        
        for (int j = 8; j >= 0; j--, expoente++) {
            decimal += *(binario + j) * pow(2, expoente);
        }
        
        if (decimal < menorNumero) {
            menorNumero = decimal;
        }
        
        int *binarioAuxiliar = alocaInt(9);
        
        for (int j = 0; j < 8; j++) {
            *(binarioAuxiliar + j) = *(binario + (j + 1));
        }
        *(binarioAuxiliar + 8) = *(binario);
        
        for (int j = 0; j < 9; j++) {
            *(binario + j) = *(binarioAuxiliar + j);
        }
        free(binarioAuxiliar);
    }
    
    free(binario);
    
    calculaFrequenciaILBP(menorNumero, frequenciaILBP);
}


void calculaFrequenciaILBP(int menorNumero, int *frequenciaILBP) {
    *(frequenciaILBP + menorNumero) += 1;
}
