//
//  vetorDescritor.c
//  Problema
//
//  Created by Vinícius Cantuária on 27/04/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#include "vetorDescritor.h"

void normalizaVetor(int *vetor) {
    int minimo = 535;
    int maximo = 0;
    
    for (int i = 0; i < 536; i++) {
        if (*(vetor + i) < minimo) {
            minimo = *(vetor + i);
        }
        
        if (*(vetor + i) > maximo) {
            maximo = *(vetor + i);
        }
    }
    
    for (int i = 0; i < 536; i++) {
        *(vetor + i) = (*(vetor + i) - minimo) / (maximo - minimo);
    }
}

void calculaMediaVetorAsfalto(int a, int *frequenciaMediaAsfalto, int *vetorImagem) {
    if (a == 0) {
        for (int i = 0; i < sizeof(frequenciaMediaAsfalto); i++) {
            *(frequenciaMediaAsfalto + i) = *(vetorImagem + i);
        }
    } else {
        for (int i = 0; i < sizeof(frequenciaMediaAsfalto); i++) {
            *(frequenciaMediaAsfalto + i) = (*(frequenciaMediaAsfalto + i) + *(vetorImagem + i)) / 2;
        }
    }
}

void calculaMediaVetorGrama(int a, int *frequenciaMediaGrama, int *vetorImagem) {
    if (a == 25) {
        for (int i = 0; i < sizeof(frequenciaMediaGrama); i++) {
            *(frequenciaMediaGrama + i) = *(vetorImagem + i);
        }
    } else {
        for (int i = 0; i < sizeof(frequenciaMediaGrama); i++) {
            *(frequenciaMediaGrama + i) = (*(frequenciaMediaGrama + i) + *(vetorImagem + i)) / 2;
        }
    }
}
