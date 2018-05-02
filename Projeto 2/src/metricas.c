//
//  metricas.c
//  Problema
//
//  Created by Vinícius Cantuária on 28/04/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#include "metricas.h"

int classificaImagem(int *vetorImagem, double *frequenciaMediaAsfalto, double *frequenciaMediaGrama) {
    double distanciaImagemComAsfalto = 0.0;
    double distanciaImagemComGrama = 0.0;
    
    for (int i = 0; i < 536; i++) {
        distanciaImagemComAsfalto += pow((*(vetorImagem + i) - *(frequenciaMediaAsfalto + i)), 2);
    }
    distanciaImagemComAsfalto = sqrtf(distanciaImagemComAsfalto);
    
    for (int i = 0; i < 536; i++) {
        distanciaImagemComGrama += pow((*(vetorImagem + i) - *(frequenciaMediaGrama + i)), 2);
    }
    distanciaImagemComGrama = sqrtf(distanciaImagemComGrama);
    
    if (distanciaImagemComGrama < distanciaImagemComAsfalto) {
        return 1;
    } else {
        return 0;
    }
}

void calculaMetricas(int *vetorImagem, double *frequenciaMediaAsfalto, double *frequenciaMediaGrama, int periodoAsfaltoTeste, int periodoGramaTeste, int *acertos, int *falsaAceitacao, int *falsaRejeicao) {
    int classificacaoImagem = 2;

    if (periodoAsfaltoTeste) {
        classificacaoImagem = classificaImagem(vetorImagem, frequenciaMediaAsfalto, frequenciaMediaGrama);
        if (classificacaoImagem == 0) {
            *acertos += 1;
        } else if (classificacaoImagem == 1) {
            *falsaAceitacao += 1;
        }
    } else if (periodoGramaTeste) {
        classificacaoImagem = classificaImagem(vetorImagem, frequenciaMediaAsfalto, frequenciaMediaGrama);
        if (classificacaoImagem == 1) {
            *acertos += 1;
        } else if (classificacaoImagem == 0) {
            *falsaRejeicao += 1;
        }
    }
}

void calculaPorcentagemMetricas(int acertos, int falsaAceitacao, int falsaRejeicao, float *taxaAcerto, float *taxaFalsaAceitacao, float *taxaFalsaRejeicao) {
    *taxaAcerto = ((float) acertos / QUANTIDADEIMAGENS) * 100;
    *taxaFalsaAceitacao = ((float) falsaAceitacao / QUANTIDADETESTES) * 100;
    *taxaFalsaRejeicao = ((float) falsaRejeicao / QUANTIDADETESTES) * 100;
}

void mostraMetricas(float taxaAcerto, float taxaFalsaAceitacao, float taxaFalsaRejeicao) {
    printf("Métricas\n");
    printf("Taxa de acerto: %.2f\n", taxaAcerto);
    printf("Taxa de falsa aceitação: %.2f\n", taxaFalsaAceitacao);
    printf("Taxa de falsa rejeição: %.2f\n", taxaFalsaRejeicao);
    printf("\n");
}

