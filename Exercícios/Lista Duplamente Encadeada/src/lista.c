
//
//  lista.c
//  Lista Duplamente Encadeada
//
//  Created by Vinícius Cantuária on 08/05/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#include "lista.h"

struct no {
    char *nome;
    int idade;
    struct no *anterior;
    struct no *proximo;
};

No *criaNo(char *nome, int idade, No *anterior) {
    No *novoNo = (No *) calloc(1, sizeof(No));
    if (novoNo == NULL) {
        printf("Erro na alocação de memória No");
        exit(1);
    }
    
    novoNo->nome = nome;
    novoNo->idade = idade;
    novoNo->anterior = anterior;
    novoNo->proximo = NULL;
    
    return novoNo;
}

No *criaLista(void) {
    No *novaLista = criaNo(NULL, 0, NULL);
    
    return novaLista;
}

void insereNo(No *no, char *nome, int idade, int posicao) {
    No *novoNo = criaNo(nome, idade, no);
    No *aux = no;
    
    if (posicao != 0) {
        for (int i = 1; (i != posicao || aux != NULL); i++) {
            aux = no->proximo;
        }
    }
    
    aux->proximo = novoNo;
}

void imprimeNo(No *no) {
    printf("Lista");
    printf("\n");
    if (no != NULL) {
        for (No *aux = no; aux != NULL; aux = aux->proximo) {
            printf("Nome: %s", aux->nome);
            printf("\n");
            printf("Idade: %d", aux->idade);
            printf("\n");
        }
    } else {
        printf("Lista vazia!");
        printf("\n");
    }
}

void excluiLista(No *no) {
    if (no != NULL) {
        No *aux;
        while (no != NULL) {
            aux = no->proximo;
            free(no);
            no = aux;
        }
        printf("Lista limpa!");
        printf("\n");
    } else {
        printf("Lista vazia!");
        printf("\n");
    }
}
