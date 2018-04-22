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
#include <time.h>
#include <math.h>


int *alocaInt(int tamanho);
char *alocaChar(int tamanho);
int **alocaMatriz(int quantidadeLinhas, int quantidadeColunas);

void verificaAlocacaoInt(int *vetorAlocado);
void verificaAlocacaoChar(char *vetorAlocado);
void verificaAlocacaoMatriz(int **matrizAlocada);
void verificaAlocacaoArquivo(FILE *imagemTexto);

void liberaMatriz(int **matrizAlocada, int quantidadeLinhas);

void geraNumerosAleatorios(int *vetorNumerosTreinamento, int *vetorNumerosTeste);
int eNumeroExistente(int *vetorNumerosAleatorios, int tamanho, int numeroGerado);

void contaTamanhoLinhas(FILE *imagemTexto, int *quantidadeLinhas);
void contaTamanhoColunas(FILE *imagemTexto, int *quantidadeColunas);

void transfereImagemTextoPrograma(FILE *imagemTexto, int **imagemPrograma, int quantidadeLinhas, int quantidadeColunas);
void calculaVizinhancasOito(int **imagemPrograma, int quantidadeLinhas, int quantidadeColunas, int *frequenciaILBP);
void converteMatrizDecimalBinario(int **matrizDecimal, int *frequenciaILBP);
void calculaMenorBinario(int **matrizBinaria, int *frequenciaILBP);
void calculaFrequenciaILBP(int menorNumero, int *frequenciaILBP);


int main(int argc, const char * argv[]) {
    char nomeImagem[] = "/Users/cantuariavc/Desktop/Estrutura de Dados 1/GitHub/EstruturaDeDados1/Projeto 2/DataSet/grass/texts/grass_50.txt";
    FILE *imagemTexto = fopen(nomeImagem, "r");
    verificaAlocacaoArquivo(imagemTexto);
    
    int quantidadeLinhas = 0;
    contaTamanhoLinhas(imagemTexto, &quantidadeLinhas);
    int quantidadeColunas = 0;
    contaTamanhoColunas(imagemTexto, &quantidadeColunas);
    
    int **imagemPrograma = alocaMatriz(quantidadeLinhas, quantidadeColunas);
    //    transfereImagemTextoPrograma(imagemTexto, imagemPrograma, quantidadeLinhas, quantidadeColunas);
    fclose(imagemTexto);
    
    int *frequenciaILBP = alocaInt(512);
    //    calculaVizinhancasOito(imagemPrograma, quantidadeLinhas, quantidadeColunas, frequenciaILBP);
    
    int *vetorNumerosTreinamento = alocaInt(25);
    int *vetorNumerosTeste = alocaInt(25);
    
    geraNumerosAleatorios(vetorNumerosTreinamento, vetorNumerosTeste);
    
    
    
    free(vetorNumerosTreinamento);
    free(vetorNumerosTeste);
    liberaMatriz(imagemPrograma, quantidadeLinhas);
    
    free(frequenciaILBP);
    
    return 0;
}


int *alocaInt(int tamanho) {
    int *vetorInt = (int *) calloc(tamanho, sizeof(int));
    verificaAlocacaoInt(vetorInt);
    
    return vetorInt;
}

char *alocaChar(int tamanho) {
    char *vetorChar = (char *) calloc(tamanho, sizeof(char));
    verificaAlocacaoChar(vetorChar);
    
    return vetorChar;
}

int **alocaMatriz(int quantidadeLinhas, int quantidadeColunas) {
    int **matriz = (int **) calloc(quantidadeLinhas, sizeof(int *));
    verificaAlocacaoMatriz(matriz);
    for (int k = 0; k < quantidadeLinhas; k++) {
        *(matriz + k) = (int *) calloc(quantidadeColunas, sizeof(int));
        verificaAlocacaoInt(*(matriz + k));
    }
    
    return matriz;
}


void verificaAlocacaoInt(int *vetorAlocado) {
    if (vetorAlocado == NULL) {
        printf("Erro na alocação da memória!\n");
        exit(1);
    }
}

void verificaAlocacaoChar(char *vetorAlocado) {
    if (vetorAlocado == NULL) {
        printf("Erro na alocação da memória!\n");
        exit(1);
    }
}

void verificaAlocacaoMatriz(int **matrizAlocada) {
    if (matrizAlocada == NULL) {
        printf("Erro na alocação da memória!\n");
        exit(1);
    }
}

void verificaAlocacaoArquivo(FILE *nomeArquivo) {
    if (nomeArquivo == NULL) {
        printf("Erro na abertura da arquivo!\n");
        exit(1);
    }
}


void liberaMatriz(int **matrizAlocada, int quantidadeLinhas) {
    for (int i = 0; i < quantidadeLinhas; i++) {
        free(*(matrizAlocada + i));
    }
    
    free(matrizAlocada);
}


void geraNumerosAleatorios(int *vetorNumerosTreinamento, int *vetorNumerosTeste) {
    srand((unsigned int)time(NULL));
    
    int *vetorNumerosAleatorios = alocaInt(50);
    int numeroGerado = 0;
    
    for (int i = 0; i < 50; i++) {
        numeroGerado = 1 + (rand() % 50);
        
        while (eNumeroExistente(vetorNumerosAleatorios, i, numeroGerado)) {
            numeroGerado = 1 + (rand() % 50);
        }
        
        *(vetorNumerosAleatorios + i) = numeroGerado;
    }
    
    for (int i = 0; i < 25; i++) {
        *(vetorNumerosTreinamento + i) = *(vetorNumerosAleatorios + i);
    }
    
    for (int i = 0; i < 25; i++) {
        *(vetorNumerosTeste + i) = *(vetorNumerosAleatorios + (i + 25));
    }
    
    free(vetorNumerosAleatorios);
}

int eNumeroExistente(int *vetorNumerosAleatorios, int tamanho, int numeroGerado) {
    int existe = 0;
    
    for (int i = 0; i < tamanho; i++) {
        if (*(vetorNumerosAleatorios + i) == numeroGerado) {
            existe = 1;
        }
    }
    
    return existe;
}


void contaTamanhoLinhas(FILE *imagemTexto, int *quantidadeLinhas) {
    char caractere = '\0';
    
    do {
        caractere = getc(imagemTexto);
        
        if (caractere == ';') {
            (*quantidadeLinhas)++;
        }
    } while (caractere != '\n');
    
    (*quantidadeLinhas)++;
}

void contaTamanhoColunas(FILE *imagemTexto, int *quantidadeColunas) {
    char caractere = '\0';
    
    do {
        caractere = getc(imagemTexto);
        
        if (caractere == ';') {
            (*quantidadeColunas)++;
        }
    } while (caractere != '\n');
    
    (*quantidadeColunas)++;
}


void transfereImagemTextoPrograma(FILE *imagemTexto, int **imagemPrograma, int quantidadeLinhas, int quantidadeColunas) {
    for (int i = 0; i < quantidadeLinhas; i++) {
        for (int j = 0; j < quantidadeColunas; j++) {
            char *numeroString = alocaChar(quantidadeColunas * 4);
            char *caractere = alocaChar(1);
            
            *caractere = getc(imagemTexto);
            while (*caractere != ';' && *caractere != '\n') {
                strcat(numeroString, caractere);
                *caractere = getc(imagemTexto);
            }
            
            *(*(imagemPrograma + i) + j) = atoi(numeroString);
            
            free(numeroString);
            free(caractere);
        }
    }
}

void calculaVizinhancasOito(int **imagemPrograma, int quantidadeLinhas, int quantidadeColunas, int *frequenciaILBP) {
    for (int i = 1; i < (quantidadeLinhas - 1); i++) {
        for (int j = 1; j < (quantidadeColunas - 1); j++) {
//            int **matrizDecimal = alocaMatriz(3, 3);
//
//            for (int k = 0; k < 3; k++) {
//                for (int l = 0; l < 3; l++) {
//                    *(*(matrizDecimal + k) + l) = (i + k);
//                }
//            }
//
//
//            liberaMatriz(matrizDecimal, 3);
        }
    }
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
    char *binario = alocaChar(9);
    
    int indice = 0;
    int decimal = 0;
    int menorNumero = 511;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            *(binario + indice++) = *(*(matrizBinaria + i) + j);
        }
    }
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            decimal += atoi(binario + (8 - j)) * pow(2, j);
        }
        
        if (decimal < menorNumero) {
            menorNumero = decimal;
        }
        
        char *binarioAuxiliar = alocaChar(9);
        
        for (int j = 0; j < 8; j++) {
            *(binarioAuxiliar + j) = *(binario + (j + 1));
        }
        *(binarioAuxiliar + 8) = *(binario);
        
        binario = binarioAuxiliar;
        
        free(binarioAuxiliar);
    }
    
    free(binario);
    
    calculaFrequenciaILBP(menorNumero, frequenciaILBP);
}

void calculaFrequenciaILBP(int menorNumero, int *frequenciaILBP) {
    *(frequenciaILBP + menorNumero) += 1;
}

