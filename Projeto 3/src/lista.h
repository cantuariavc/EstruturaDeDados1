//
//  lista.h
//  Projeto 3
//
//  Created by Vinícius Cantuária on 10/05/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#ifndef lista_h
#define lista_h

#include <stdio.h>
#include <stdlib.h>

typedef struct no No;
No *criaLista(void);
No *criaNo(char *nomeCompleto, char *telefoneCelular, char *endereco, char *cep, char *dataDeNascimento, No *anterior, No *proximo);
void insereNo(No *lista, char *nomeCompleto, char *telefoneCelular, char *endereco, char *cep, char *dataDeNascimento);
void imprimeLista(No *lista);

#endif /* lista_h */
