//
//  lista.h
//  Lista Duplamente Encadeada
//
//  Created by Vinícius Cantuária on 08/05/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#ifndef lista_h
#define lista_h

#include <stdio.h>
#include <stdlib.h>

typedef struct no No;
No *criaNo(char *nome, int idade, No *anterior, No *proximo);
No *criaLista(void);
void insereNo(No *no, int posicao, char *nome, int idade);
void imprimeLista(No *no);
void excluiLista(No *no);

#endif /* lista_h */
