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
void calculaFrequenciasGLCM(int **matrizDecimal, int **noroeste, int **norte, int **nordeste, int **oeste, int **leste, int **sudoeste, int **sul, int **sudeste);

void normalizaVetor(int *vetor);
void calculaMediaILBPAsfalto(int *frequenciaILBPAsfalto, int *frequenciaILBP);
void calculaMediaILBPGrama(int *frequenciaILBPGrama, int *frequenciaILBP);


int main(int argc, const char * argv[]) {
    int *vetorNumerosTreinamento = alocaInt(25);
    int *vetorNumerosTeste = alocaInt(25);
    geraNumerosAleatorios(vetorNumerosTreinamento, vetorNumerosTeste);
    
    char caminhoArquivo[] = "/Users/cantuariavc/Desktop/Estrutura de Dados 1/GitHub/EstruturaDeDados1/Projeto 2/DataSet/";
    char tipoAsfalto[] = "asphalt/texts/asphalt_";
    char tipoGrama[] = "grass/texts/grass_";
    
    int *frequenciaILBPAsfalto = alocaInt(512);
    int *frequenciaILBPGrama = alocaInt(512);
    
    int b = 0;
    for (int a = 0; a < 100; a++) {
        char *numeroArquivo = alocaChar(7);
        char *nomeImagem = alocaChar(sizeof(caminhoArquivo) + sizeof(tipoAsfalto) + sizeof(numeroArquivo));
        strcat(nomeImagem, caminhoArquivo);

        int periodoAsfalto = (a < 25 || (a >= 50 && a < 75));
        int periodoGrama = ((a >= 25 && a < 50) || a >= 75);
        
        if (a < 25) {
            b = a;
        } else if (a >= 25 && a < 50){
            b = (a - 25);
        } else if (a >= 50 && a < 75) {
            b = (a - 50);
        } else {
            b = (a - 75);
        }
        
        if (periodoAsfalto) {
            if (*(vetorNumerosTreinamento + b) <= 9) {
                sprintf(numeroArquivo, "%c%d%s", '0', *(vetorNumerosTreinamento + b), ".txt\0");
            } else if (*(vetorNumerosTreinamento + b) > 9) {
                sprintf(numeroArquivo, "%d%s", *(vetorNumerosTreinamento + b), ".txt\0");
            }
            
            strcat(nomeImagem, tipoAsfalto);
            strcat(nomeImagem, numeroArquivo);
        } else if (periodoGrama) {
            if (*(vetorNumerosTeste + b) <= 9) {
                sprintf(numeroArquivo, "%c%d%s", '0', *(vetorNumerosTeste + b), ".txt\0");
            } else if (*(vetorNumerosTeste + b) > 9) {
                sprintf(numeroArquivo, "%d%s", *(vetorNumerosTeste + b), ".txt\0");
            }
            
            strcat(nomeImagem, tipoGrama);
            strcat(nomeImagem, numeroArquivo);
        }
            
        FILE *imagemTexto = fopen(nomeImagem, "r");
        verificaAlocacaoArquivo(imagemTexto);
        free(nomeImagem);
        free(numeroArquivo);
        
        int quantidadeLinhas = 0;
        contaTamanhoLinhas(imagemTexto, &quantidadeLinhas);
        int quantidadeColunas = 0;
        contaTamanhoColunas(imagemTexto, &quantidadeColunas);
        
        int **imagemPrograma = alocaMatriz(quantidadeLinhas, quantidadeColunas);
        transfereImagemTextoPrograma(imagemTexto, imagemPrograma, quantidadeLinhas, quantidadeColunas);
        fclose(imagemTexto);
        
        int *frequenciaILBP = alocaInt(512);
        calculaVizinhancasOito(imagemPrograma, quantidadeLinhas, quantidadeColunas, frequenciaILBP);
        
        if (periodoAsfalto) {
            calculaMediaILBPAsfalto(frequenciaILBPAsfalto, frequenciaILBP);
        } else if (periodoGrama) {
            calculaMediaILBPGrama(frequenciaILBPGrama, frequenciaILBP);
        }
        free(frequenciaILBP);
        
        
        liberaMatriz(imagemPrograma, quantidadeLinhas);
    }
    
    free(frequenciaILBPAsfalto);
    free(frequenciaILBPGrama);
    free(vetorNumerosTreinamento);
    free(vetorNumerosTeste);
    
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
        printf("Erro na alocação da memória do vetor int!\n");
        exit(1);
    }
}

void verificaAlocacaoChar(char *vetorAlocado) {
    if (vetorAlocado == NULL) {
        printf("Erro na alocação da memória do vetor char!\n");
        exit(1);
    }
}

void verificaAlocacaoMatriz(int **matrizAlocada) {
    if (matrizAlocada == NULL) {
        printf("Erro na alocação da memória da matriz!\n");
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
            char *numeroString = alocaChar(3);
            char *caractere = alocaChar(1);
            
            *caractere = getc(imagemTexto);
            while (*caractere != ';' && *caractere != '\n' && *caractere != EOF) {
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


void calculaFrequenciaILBP(int menorNumero, int *frequenciaILBP) {
    *(frequenciaILBP + menorNumero) += 1;
}

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
}

void calculaMediaILBPAsfalto(int *frequenciaILBPAsfalto, int *frequenciaILBP) {
    for (int i = 0; i < 512; i++) {
        *(frequenciaILBPAsfalto + i) = (*(frequenciaILBPAsfalto + i) + *(frequenciaILBP + i)) / 2;
    }
}

void calculaMediaILBPGrama(int *frequenciaILBPGrama, int *frequenciaILBP) {
    for (int i = 0; i < 512; i++) {
        *(frequenciaILBPGrama + i) = (*(frequenciaILBPGrama + i) + *(frequenciaILBP + i)) / 2;
    }
}

