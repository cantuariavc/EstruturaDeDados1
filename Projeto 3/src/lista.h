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

#define TAMANHONOMECOMPLETO 101
#define TAMANHOTELEFONECELULAR 11
#define TAMANHOENDERECO TAMANHONOMECOMPLETO
#define TAMANHODATADENASCIMENTO TAMANHOTELEFONECELULAR

typedef struct no {
    char nomeCompleto[TAMANHONOMECOMPLETO];
    char telefoneCelular[TAMANHOTELEFONECELULAR];
    char endereco[TAMANHOENDERECO];
    int cep;
    char dataDeNascimento[TAMANHODATADENASCIMENTO];
    struct no *anterior;
    struct no *proximo;
} No;

No *criaLista(void);
No *criaNo(char nomeCompleto[], char telefoneCelular[], char endereco[], int cep, char dataDeNascimento[], No *anterior, No *proximo);
No *insereNo(No *lista, char nomeCompleto[], char telefoneCelular[], char endereco[], int cep, char dataDeNascimento[]);
void imprimeLista(No *lista);

#endif /* lista_h */
