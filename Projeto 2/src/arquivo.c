//
//  arquivo.c
//  Problema
//
//  Created by Vinícius Cantuária on 27/04/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#include "arquivo.h"

void defineNumeroArquivo(int a, char* numeroArquivo, int *vetorNumerosTreinamento, int *vetorNumerosTeste, int periodoAsfaltoTreinamento, int periodoGramaTreinamento, int periodoAsfaltoTeste, int periodoGramaTeste) {
    int b = 0;
    
    if (periodoAsfaltoTreinamento) {
        b = a;
    } else if (periodoGramaTreinamento) {
        b = (a - QUANTIDADETREINAMENTOSTESTES);
    } else if (periodoAsfaltoTeste) {
        b = (a - QUANTIDADEIMAGENS);
    } else if (periodoGramaTeste) {
        b = (a - (QUANTIDADEIMAGENS + QUANTIDADETREINAMENTOSTESTES));
    }
    
    int numeroUmDigitoTreinamento = (*(vetorNumerosTreinamento + b) <= 9);
    int numeroDoisDigitosTreinamento = (*(vetorNumerosTreinamento + b) > 9);
    int numeroUmDigitoTeste = (*(vetorNumerosTeste + b) <= 9);
    int numeroDoisDigitosTeste = (*(vetorNumerosTeste + b) > 9);

    if (periodoAsfaltoTreinamento) {
        if (numeroUmDigitoTreinamento) {
            sprintf(numeroArquivo, "%c%d%s", '0', *(vetorNumerosTreinamento + b), ".txt\0");
        } else if (numeroDoisDigitosTreinamento) {
            sprintf(numeroArquivo, "%d%s", *(vetorNumerosTreinamento + b), ".txt\0");
        }
    } else if (periodoGramaTreinamento) {
        if (numeroUmDigitoTreinamento) {
            sprintf(numeroArquivo, "%c%d%s", '0', *(vetorNumerosTreinamento + b), ".txt\0");
        } else if (numeroDoisDigitosTreinamento) {
            sprintf(numeroArquivo, "%d%s", *(vetorNumerosTreinamento + b), ".txt\0");
        }
    } else if (periodoAsfaltoTeste) {
        if (numeroUmDigitoTeste) {
            sprintf(numeroArquivo, "%c%d%s", '0', *(vetorNumerosTeste + b), ".txt\0");
        } else if (numeroDoisDigitosTeste) {
            sprintf(numeroArquivo, "%d%s", *(vetorNumerosTeste + b), ".txt\0");
        }
    } else if (periodoGramaTeste) {
        if (numeroUmDigitoTeste) {
            sprintf(numeroArquivo, "%c%d%s", '0', *(vetorNumerosTeste + b), ".txt\0");
        } else if (numeroDoisDigitosTeste) {
            sprintf(numeroArquivo, "%d%s", *(vetorNumerosTeste + b), ".txt\0");
        }
    }
}

void defineNomeArquivo(char *nomeImagem, char *tipoAsfalto, char *tipoGrama, char *numeroArquivo, int periodoAsfaltoTreinamento, int periodoGramaTreinamento, int periodoAsfaltoTeste, int periodoGramaTeste) {
    if (periodoAsfaltoTreinamento || periodoAsfaltoTeste) {
        strcat(nomeImagem, tipoAsfalto);
        strcat(nomeImagem, numeroArquivo);
    } else if (periodoGramaTreinamento || periodoGramaTeste) {
        strcat(nomeImagem, tipoGrama);
        strcat(nomeImagem, numeroArquivo);
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
