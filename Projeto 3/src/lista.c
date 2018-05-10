//
//  lista.c
//  Projeto 3
//
//  Created by Vinícius Cantuária on 10/05/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#include "lista.h"

struct no {
    char *nomeCompleto;
    char *telefoneCelular;
    char *endereco;
    char *cep;
    char *dataDeNascimento;
    struct no *anterior;
    struct no *proximo;
};

No *criaLista(void) {
    No *novaLista = NULL;
    
    return novaLista;
}

No *criaNo(char *nomeCompleto, char *telefoneCelular, char *endereco, char *cep, char *dataDeNascimento, No *anterior, No *proximo) {
    No *novoNo = (No *) calloc(1, sizeof(No));
    if (novoNo == NULL) {
        printf("Erro na alocação de memória do Nó!");
        exit(1);
    }
    
    novoNo->nomeCompleto = nomeCompleto;
    novoNo->telefoneCelular = telefoneCelular;
    novoNo->endereco = endereco;
    novoNo->cep = cep;
    novoNo->dataDeNascimento = dataDeNascimento;
    novoNo->anterior = anterior;
    novoNo->proximo = proximo;
    
    return novoNo;
}

void insereNo(No *lista, char *nomeCompleto, char *telefoneCelular, char *endereco, char *cep, char *dataDeNascimento) {
    No *novoNo = criaNo(nomeCompleto, telefoneCelular, endereco, cep, dataDeNascimento, NULL, NULL);
    
    if (lista != NULL) {
        No *aux;
        for (aux = lista; aux->proximo != NULL; aux = aux->proximo);
        
        aux->proximo = novoNo;
        novoNo->anterior = aux;
    } else {
        lista = novoNo;
    }
}

