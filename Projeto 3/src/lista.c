//
//  lista.c
//  Projeto 3
//
//  Created by Vinícius Cantuária on 10/05/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#include "lista.h"

No *criaLista(void) {
    No *novaLista = NULL;
    
    return novaLista;
}

No *criaNo(char nomeCompleto[], char telefoneCelular[], char endereco[], int cep, char dataDeNascimento[], No *anterior, No *proximo) {
    No *novoNo = (No *) calloc(1, sizeof(No));
    if (novoNo == NULL) {
        printf("Erro na alocação de memória do Nó!");
        exit(1);
    }
    
    for (int i = 0; i < TAMANHONOMECOMPLETO; i++) {
        novoNo->nomeCompleto[i] = nomeCompleto[i];
        novoNo->endereco[i] = endereco[i];
    }
    for (int i = 0; i < TAMANHOTELEFONECELULAR; i++) {
        novoNo->telefoneCelular[i] = telefoneCelular[i];
        novoNo->dataDeNascimento[i] = dataDeNascimento[i];
    }
    novoNo->cep = cep;
    
    novoNo->anterior = anterior;
    novoNo->proximo = proximo;
    
    return novoNo;
}

void insereNo(No *lista, char nomeCompleto[], char telefoneCelular[], char endereco[], int cep, char dataDeNascimento[]) {
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

void imprimeLista(No *lista) {
    printf("Lista");
    printf("\n");
    if (lista != NULL) {
        for (No *aux = lista; aux != NULL; aux = aux->proximo) {
            printf("Nome completo: %s", aux->nomeCompleto);
            printf("\n");
            printf("Telefone celular: %s", aux->telefoneCelular);
            printf("\n");
            printf("Endereço: %s", aux->endereco);
            printf("\n");
            printf("CEP: %d", aux->cep);
            printf("\n");
            printf("Data de nascimento: %s", aux->dataDeNascimento);
            printf("\n");
            printf("\n");
        }
    } else {
        printf("Lista vazia!");
        printf("\n");
    }
}
