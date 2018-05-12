//
//  servicos.h
//  Projeto 3
//
//  Created by Vinícius Cantuária on 10/05/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#ifndef servicos_h
#define servicos_h

#include <unistd.h>
#include "no.h"
#include "lista.h"

#define ENOENT -1

int eArquivoExistente(char caminhoArquivo[]);
FILE *abreArquivo(char caminhoArquivo[]);
void verificaAlocacaoArquivo(FILE *nomeArquivo);

void imprimeMenu(int *opcao);
void insereNovoRegistro(No *lista);

int validaCelular(char telefoneCelular[]);
int validaDataDeNacimento(char dataDeNascimento[]);
int validaFormato(char dataDeNascimento[]);
int validaDia(int dia);
int validaMes(int mes);
int validaAno(int ano);
int verificaNome(char nomeNo[], char nomePesquisa[]);

#endif /* servicos_h */
