//
//  metricas.h
//  Problema
//
//  Created by Vinícius Cantuária on 28/04/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#ifndef metricas_h
#define metricas_h

#include <stdio.h>
#include <math.h>
#include "numeroAleatorio.h"

int classificaImagem(int *vetorImagem, float *frequenciaMediaAsfalto, float *frequenciaMediaGrama);
void calculaMetricas(int *vetorImagem, float *frequenciaMediaAsfalto, float *frequenciaMediaGrama, int periodoAsfaltoTeste, int periodoGramaTeste, int *acertos, int *falsaAceitacao, int *falsaRejeicao);
void calculaPorcentagemMetricas(int acertos, int falsaAceitacao, int falsaRejeicao, float *taxaAcerto, float *taxaFalsaAceitacao, float *taxaFalsaRejeicao);
void mostraMetricas(float taxaAcerto, float taxaFalsaAceitacao, float taxaFalsaRejeicao);

#endif /* metricas_h */
