//
//  servicos.h
//  Projeto 3
//
//  Created by Vinícius Cantuária on 10/05/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#ifndef servicos_h
#define servicos_h

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#define TAMANHONOMECOMPLETO 101
#define TAMANHOTELEFONECELULAR 11
#define TAMANHOENDERECO 101
#define TAMANHOCEP 6
#define TAMANHODATADENASCIMENTO 11

void verificaAlocacaoArquivo(FILE *nomeArquivo);
void transfereContatosParaLista(FILE *contatos, No *lista);
void imprimeMenu(void);
char *alocaChar(int tamanho);
void realocaChar(char *vetorChar, int tamanho);
void verificaAlocacaoChar(char *vetorAlocado);

#endif /* servicos_h */
