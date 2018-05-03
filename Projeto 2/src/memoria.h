//
//  memoria.h
//  Problema
//
//  Created by Vinícius Cantuária on 27/04/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#ifndef memoria_h
#define memoria_h

#include <stdio.h>
#include <stdlib.h>

int *alocaInt(int tamanho);
float *alocaFloat(int tamanho);
char *alocaChar(int tamanho);
int **alocaMatriz(int quantidadeLinhas, int quantidadeColunas);

void verificaAlocacaoInt(int *vetorAlocado);
void verificaAlocacaoFloat(float *vetorAlocado);
void verificaAlocacaoChar(char *vetorAlocado);
void verificaAlocacaoMatriz(int **matrizAlocada);
void verificaAlocacaoArquivo(FILE *imagemTexto);

void liberaMatriz(int **matrizAlocada, int quantidadeLinhas);

#endif /* memoria_h */
