//
//  main.c
//  Problema 1
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

void verificaAlocacaoInt(int *vetorAlocado);
void verificaAlocacaoChar(char *vetorAlocado);
void verificaAlocacaoMatriz(int **matrizAlocada);
void liberaMatriz(int **matrizAlocada, int quatidadeLinhas);
void geraNumerosAleatorios(int *vetorNumerosTreinamento, int *vetorNumerosTeste);
int numeroExistente(int *vetorNumerosAleatorios, int tamanho, int numnumeroGeradoero);
void verificaImagem(FILE *imagemTexto);
void contaTamanhoLinhas(FILE *imagemTexto, int *quantidadeLinhas);
void contaTamanhoColunas(FILE *imagemTexto, int *quantidadeColunas);
void transfereImagemTextoPrograma(FILE *imagemTexto, int **imagemPrograma, int quantidadeLinhas, int quantidadeColunas);
void converteMatrizDecimalBinario(int **matrizDecimal, int *media);
void calculaMenorBinario(int **matrizBinaria);

int main(int argc, const char * argv[]) {
    char nomeImagem[] = "/Users/cantuariavc/Desktop/Estrutura de Dados 1/GitHub/EstruturaDeDados1/Projeto 2/DataSet/grass/texts/grass_50.txt";
    FILE *imagemTexto = fopen(nomeImagem, "r");
    verificaImagem(imagemTexto);

    int quatidadeLinhas = 0;
    contaTamanhoLinhas(imagemTexto, &quatidadeLinhas);
    int quantidadeColunas = 0;
    contaTamanhoColunas(imagemTexto, &quantidadeColunas);

    int **imagemPrograma = (int **) calloc(quatidadeLinhas, sizeof(int *));
    verificaAlocacaoMatriz(imagemPrograma);
    for (int i = 0; i < quatidadeLinhas; i++) {
        *(imagemPrograma + i) = (int *) calloc(quantidadeColunas, sizeof(int));
    }
    verificaAlocacaoInt(*imagemPrograma);
    transfereImagemTextoPrograma(imagemTexto, imagemPrograma, quatidadeLinhas, quantidadeColunas);

    int *vetorNumerosTreinamento = (int *) calloc(25, sizeof(int));
    verificaAlocacaoInt(vetorNumerosTreinamento);
    int *vetorNumerosTeste = (int *) calloc(25, sizeof(int));
    verificaAlocacaoInt(vetorNumerosTeste);


    geraNumerosAleatorios(vetorNumerosTreinamento, vetorNumerosTeste);



    free(vetorNumerosTreinamento);
    free(vetorNumerosTeste);
    liberaMatriz(imagemPrograma, quatidadeLinhas);
    fclose(imagemTexto);

    return 0;
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

void liberaMatriz(int **matrizAlocada, int quatidadeLinhas) {
    for (int i = 0; i < quatidadeLinhas; i++) {
        free(*(matrizAlocada + i));
    }

    free(matrizAlocada);
}

void geraNumerosAleatorios(int *vetorNumerosTreinamento, int *vetorNumerosTeste) {
    srand((unsigned int)time(NULL));

    int *vetorNumerosAleatorios = (int *) calloc(50, sizeof(int));
    int numeroGerado = 0;

    verificaAlocacaoInt(vetorNumerosAleatorios);

    for (int i = 0; i < 50; i++) {
        numeroGerado = 1 + (rand() % 50);

        while (numeroExistente(vetorNumerosAleatorios, i, numeroGerado)) {
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

int numeroExistente(int *vetorNumerosAleatorios, int tamanho, int numnumeroGeradoero) {
    int existe = 0;

    for (int i = 0; i < tamanho; i++) {
        if (*(vetorNumerosAleatorios + i) == numnumeroGeradoero) {
            existe = 1;
        }
    }

    return existe;
}

void verificaImagem(FILE *imagemTexto) {
    if (imagemTexto == NULL) {
        printf("Erro na abertura da imagemTexto!\n");
        exit(1);
    }
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
            char *numeroString = (char *) calloc(quantidadeColunas, 4);
            char *caractere = (char *) calloc(1, sizeof(char));
            verificaAlocacaoChar(numeroString);
            verificaAlocacaoChar(caractere);

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

void converteMatrizDecimalBinario(int **matrizDecimal, int *media) {
    int **matrizBinaria = (int **) calloc(3, sizeof(int *));
    verificaAlocacaoMatriz(matrizBinaria);
    for (int k = 0; k < 3; k++) {
        *(matrizBinaria + k) = (int *) calloc(3, sizeof(int));
    }
    verificaAlocacaoInt(*matrizBinaria);
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (*(*(matrizDecimal + i) + j) >= *media) {
                *(*(matrizBinaria + i) + j) = 1;
            } else {
                *(*(matrizBinaria + i) + j) = 0;
            }
        }
    }
    
    calculaMenorBinario(matrizBinaria);
    
    liberaMatriz(matrizBinaria, 3);
}

void calculaMenorBinario(int **matrizBinaria) {
    char *binario = (char *) calloc(9, sizeof(char));
    verificaAlocacaoChar(binario);
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
        
        char *binarioAuxiliar = (char *) calloc(9, sizeof(char));
        verificaAlocacaoChar(binarioAuxiliar);
        
        for (int j = 0; j < 8; j++) {
            *(binarioAuxiliar + j) = *(binario + (j + 1));
        }
        *(binarioAuxiliar + 8) = *(binario);
        
        binario = binarioAuxiliar;
        
        free(binarioAuxiliar);
    }
    
    free(binario);
}

