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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "arquivo.h"
#include "descritorILBP.h"
#include "descritorGLCM.h"
#include "vetorDescritor.h"
#include "memoria.h"
#include "numeroAleatorio.h"

void calculaVizinhancasOito(int **imagemPrograma, int quantidadeLinhas, int quantidadeColunas, int *frequenciaILBP);
void converteMatrizDecimalBinario(int **matrizDecimal, int *frequenciaILBP);
void calculaMenorBinario(int **matrizBinaria, int *frequenciaILBP);

int main(int argc, const char * argv[]) {
    int *vetorNumerosTreinamento = alocaInt(25);
    int *vetorNumerosTeste = alocaInt(25);
    geraNumerosAleatorios(vetorNumerosTreinamento, vetorNumerosTeste);
    
    char caminhoArquivo[] = "/Users/cantuariavc/Desktop/Estrutura de Dados 1/GitHub/EstruturaDeDados1/Projeto 2/DataSet/";
    char tipoAsfalto[] = "asphalt/texts/asphalt_";
    char tipoGrama[] = "grass/texts/grass_";
    
    int *frequenciaMediaAsfalto = alocaInt(536);
    int *frequenciaMediaGrama = alocaInt(536);
    
    for (int a = 0; a < 100; a++) {
        char *numeroArquivo = alocaChar(7);
        char *nomeImagem = alocaChar(sizeof(caminhoArquivo) + sizeof(tipoAsfalto) + sizeof(numeroArquivo));
        strcat(nomeImagem, caminhoArquivo);

        int periodoAsfaltoTreinamento = (a < 25);
        int periodoGramaTreinamento = (a >= 25 && a < 50);
        int periodoAsfaltoTeste = (a >= 50 && a < 75);
        int periodoGramaTeste = (a >= 75);
        
        defineNumeroArquivo(a, numeroArquivo, vetorNumerosTreinamento, vetorNumerosTeste, periodoAsfaltoTreinamento, periodoGramaTreinamento, periodoAsfaltoTeste, periodoGramaTeste);
        defineNomeArquivo(nomeImagem, tipoAsfalto, tipoGrama, numeroArquivo, periodoAsfaltoTreinamento, periodoGramaTreinamento, periodoAsfaltoTeste, periodoGramaTeste);
        free(numeroArquivo);

        printf("%s\n\n", nomeImagem);
        
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
        
        int *frequenciaILBP = alocaInt(512);
        int *metricasGLCM = alocaInt(24);
        calculaVizinhancasOito(imagemPrograma, quantidadeLinhas, quantidadeColunas, frequenciaILBP);
        
        int *vetorImagem = alocaInt(sizeof(frequenciaILBP) + sizeof(metricasGLCM));
        for (int i = 0; i < sizeof(frequenciaILBP); i++) {
            *(vetorImagem + i) = *(frequenciaILBP + i);
        }
        for (int i = sizeof(frequenciaILBP); i < (sizeof(frequenciaILBP) + sizeof(metricasGLCM)); i++) {
            *(vetorImagem + i) = *(metricasGLCM + i);
        }
        free(frequenciaILBP);
        free(metricasGLCM);
        
        normalizaVetor(vetorImagem);
        
        if (periodoAsfaltoTreinamento) {
            calculaMediaVetorAsfalto(a, frequenciaMediaAsfalto, vetorImagem);
        } else if (periodoGramaTreinamento) {
            calculaMediaVetorGrama(a, frequenciaMediaGrama, vetorImagem);
        }
        free(vetorImagem);
        
        
        liberaMatriz(imagemPrograma, quantidadeLinhas);
    }
    
    free(frequenciaMediaAsfalto);
    free(frequenciaMediaGrama);
    free(vetorNumerosTreinamento);
    free(vetorNumerosTeste);
    
    return 0;
}

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

