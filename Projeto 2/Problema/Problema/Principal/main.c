//
//  main.c
//  Problema
//
//  Created by Vinícius Cantuária on 17/04/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//
// Mateus de Oliveira Barbosa - 14/0154817
// Vinícius de Castro Cantuária - 14/0165169
//

#include "arquivo.h"
#include "descritorILBP.h"
#include "descritorGLCM.h"
#include "vetorDescritor.h"
#include "memoria.h"
#include "metricas.h"
#include "numeroAleatorio.h"
#include "pixels.h"
#define QUANTIDADEIMAGENS 50
#define TAMANHOVETOR 536
#define TAMANHOILBP 512
#define TAMANHOGLCM 24

int main(int argc, const char * argv[]) {
    int *vetorNumerosTreinamento = alocaInt(QUANTIDADEIMAGENS / 2);
    int *vetorNumerosTeste = alocaInt(QUANTIDADEIMAGENS / 2);
    geraNumerosAleatorios(vetorNumerosTreinamento, vetorNumerosTeste);
    
    char caminhoArquivo[] = "/Users/cantuariavc/Desktop/Estrutura de Dados 1/GitHub/EstruturaDeDados1/Projeto 2/DataSet/";
    char tipoAsfalto[] = "asphalt/texts/asphalt_";
    char tipoGrama[] = "grass/texts/grass_";
    
    int *frequenciaMediaAsfalto = alocaInt(TAMANHOVETOR);
    int *frequenciaMediaGrama = alocaInt(TAMANHOVETOR);
    
    int acertos = 0;
    int falsaAceitacao = 0;
    int falsaRejeicao = 0;
    float taxaAcerto = 0.0;
    float taxaFalsaAceitacao = 0.0;
    float taxaFalsaRejeicao = 0.0;
    
    for (int a = 0; a < 100; a++) {
        char *numeroArquivo = alocaChar(7);
        char *nomeImagem = alocaChar(130);
        strcat(nomeImagem, caminhoArquivo);

        int periodoAsfaltoTreinamento = (a < 25);
        int periodoGramaTreinamento = (a >= 25 && a < 50);
        int periodoAsfaltoTeste = (a >= 50 && a < 75);
        int periodoGramaTeste = (a >= 75);
        
        defineNumeroArquivo(a, numeroArquivo, vetorNumerosTreinamento, vetorNumerosTeste, periodoAsfaltoTreinamento, periodoGramaTreinamento, periodoAsfaltoTeste, periodoGramaTeste);
        defineNomeArquivo(nomeImagem, tipoAsfalto, tipoGrama, numeroArquivo, periodoAsfaltoTreinamento, periodoGramaTreinamento, periodoAsfaltoTeste, periodoGramaTeste);
        free(numeroArquivo);
        
        FILE *imagemTexto = fopen(nomeImagem, "r");
        verificaAlocacaoArquivo(imagemTexto);
        free(nomeImagem);
        
        int quantidadeLinhas = 0;
        contaTamanhoLinhas(imagemTexto, &quantidadeLinhas);
        int quantidadeColunas = 0;
        contaTamanhoColunas(imagemTexto, &quantidadeColunas);
        
        int **imagemPrograma = alocaMatriz(quantidadeLinhas, quantidadeColunas);
        transfereImagemTextoPrograma(imagemTexto, imagemPrograma, quantidadeLinhas, quantidadeColunas);
        fclose(imagemTexto);

        int *frequenciaILBP = alocaInt(TAMANHOILBP);
        int *metricasGLCM = alocaInt(TAMANHOGLCM);
        calculaVizinhancasOito(imagemPrograma, quantidadeLinhas, quantidadeColunas, frequenciaILBP, metricasGLCM);

        int *vetorImagem = alocaInt(TAMANHOVETOR);
        for (int i = 0; i < TAMANHOILBP; i++) {
            *(vetorImagem + i) = *(frequenciaILBP + i);
        }
        for (int i = TAMANHOILBP; i < TAMANHOVETOR; i++) {
            *(vetorImagem + i) = *(metricasGLCM + i);
        }
        free(frequenciaILBP);
        free(metricasGLCM);

        normalizaVetor(vetorImagem);

        if (periodoAsfaltoTreinamento) {
            calculaMediaVetorAsfalto(a, frequenciaMediaAsfalto, vetorImagem);
        } else if (periodoGramaTreinamento) {
            calculaMediaVetorGrama(a, frequenciaMediaGrama, vetorImagem);
        } else if (periodoAsfaltoTeste || periodoGramaTeste) {
            calculaMetricas(vetorImagem, frequenciaMediaAsfalto, frequenciaMediaGrama, periodoAsfaltoTeste, periodoGramaTeste, &acertos, &falsaAceitacao, &falsaRejeicao);
        }
        
        free(vetorImagem);
        liberaMatriz(imagemPrograma, quantidadeLinhas);
    }
    
    free(frequenciaMediaAsfalto);
    free(frequenciaMediaGrama);
    free(vetorNumerosTreinamento);
    free(vetorNumerosTeste);
    
    calculaPorcentagemMetricas(acertos, falsaAceitacao, falsaRejeicao, &taxaAcerto, &taxaFalsaAceitacao, &taxaFalsaRejeicao);
    mostraMetricas(taxaAcerto, taxaFalsaAceitacao, taxaFalsaRejeicao);
    
    return 0;
}

