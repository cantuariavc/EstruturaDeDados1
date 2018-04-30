//
//  arquivo.h
//  Problema
//
//  Created by Vinícius Cantuária on 27/04/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#ifndef arquivo_h
#define arquivo_h

#include <string.h>
#include "memoria.h"
#include "numeroAleatorio.h"

void defineNumeroArquivo(int a, char* numeroArquivo, int *vetorNumerosTreinamento, int *vetorNumerosTeste, int periodoAsfaltoTreinamento, int periodoGramaTreinamento, int periodoAsfaltoTeste, int periodoGramaTeste);
void defineNomeArquivo(char *nomeImagem, char *tipoAsfalto, char *tipoGrama, char *numeroArquivo, int periodoAsfaltoTreinamento, int periodoGramaTreinamento, int periodoAsfaltoTeste, int periodoGramaTeste);

void contaTamanhoLinhas(FILE *imagemTexto, int *quantidadeLinhas);
void contaTamanhoColunas(FILE *imagemTexto, int *quantidadeColunas);

void transfereImagemTextoPrograma(FILE *imagemTexto, int **imagemPrograma, int quantidadeLinhas, int quantidadeColunas);

#endif /* arquivo_h */
