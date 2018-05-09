
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

No *criaNo(char *nome, int idade, No *anterior, No *proximo) {
    No *novoNo = (No *) calloc(1, sizeof(No));
    if (novoNo == NULL) {
        printf("Erro na alocação de memória No");
        exit(1);
    }
    
    novoNo->nome = nome;
    novoNo->idade = idade;
    novoNo->anterior = anterior;
    novoNo->proximo = proximo;
    
    return novoNo;
}

No *criaLista(void) {
    No *novaLista = NULL;
    
    return novaLista;
}

void insereNo(No *no, int posicao, char *nome, int idade) {
    No *novoNo = criaNo(nome, idade, NULL, NULL);
    
    if (no != NULL) {
        No *aux = no;
        
        if (posicao == 1) {
            novoNo->proximo = aux;
            aux->anterior = novoNo;
        } else if (posicao != 0) {
            for (int i = 1; i != posicao; i++) {
                aux = aux->proximo;
            }
        
            aux->proximo->anterior = novoNo;
            novoNo->proximo = aux->proximo;
            aux->proximo = novoNo;
            novoNo->anterior = aux;
        } else if (posicao == 0) {
            aux->proximo = novoNo;
            novoNo->anterior = aux;
        }
    } else {
        no = novoNo;
    }
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

void excluiNo(No *no, int posicao, int tamanho) {
    if (no != NULL) {
        No *aux = no;
        
        if (posicao == 1) {
            aux->proximo->anterior = NULL;
            free(aux);
        } else if (posicao != tamanho) {
            for (int i = 1; i != posicao; i++) {
                aux = aux->proximo;
            }
            aux->anterior->proximo = aux->proximo;
            aux->proximo = aux->anterior;
            free(aux);
        } else if (posicao == tamanho) {
            for (; aux->proximo != NULL; aux = aux->proximo);
            aux->anterior->proximo = NULL;
            free(aux);
        }
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
