//
//  metricas.c
//  Problema
//
//  Created by Vinícius Cantuária on 28/04/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#include "metricas.h"

int classificaImagem(int *vetorImagem, int *frequenciaMediaAsfalto, int *frequenciaMediaGrama) {
    float distanciaImagemComAsfalto = 0.0;
    float distanciaImagemComGrama = 0.0;
    
    for (int i = 0; i < 536; i++) {
        distanciaImagemComAsfalto += pow((*(vetorImagem + i) - *(frequenciaMediaAsfalto + i)), 2);
    }
    distanciaImagemComAsfalto = sqrtf(distanciaImagemComAsfalto);
    
    for (int i = 0; i < 536; i++) {
        distanciaImagemComGrama += pow((*(vetorImagem + i) - *(frequenciaMediaGrama + i)), 2);
    }
    distanciaImagemComGrama = sqrtf(distanciaImagemComGrama);
    
    if (distanciaImagemComAsfalto > distanciaImagemComGrama) {
        return 0;
    } else {
        return 1;
    }
}
