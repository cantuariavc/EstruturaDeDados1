//
//  lista.c
//  Projeto 3
//
//  Created by Vinícius Cantuária on 10/05/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#include "lista.h"

    
    return novaLista;
}

No *insereNo(No *lista, char nomeCompleto[], char telefoneCelular[], char endereco[], int cep, char dataDeNascimento[]) {
    No *novoNo = criaNo(nomeCompleto, telefoneCelular, endereco, cep, dataDeNascimento, NULL, NULL);
    
    if (lista != NULL) {
        No *aux;
        for (aux = lista; aux->proximo != NULL; aux = aux->proximo);
        
        aux->proximo = novoNo;
        novoNo->anterior = aux;
    } else {
        lista = novoNo;
    }
    
    return lista;
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
        printf("Vazia!");
        printf("\n");
        printf("\n");
    }
}

void imprimeNoPorNome(No *lista) {
    if (lista != NULL) {
        char nomeCompleto[101];
        
        printf("Nome completo: ");
        fgets(nomeCompleto, TAMANHONOMECOMPLETO, stdin);
        for (int i = 0; i < TAMANHONOMECOMPLETO; i++) {
            if (nomeCompleto[i] == '\n') {
                nomeCompleto[i] = '\0';
                break;
            }
        }
        printf("\n");
        
        for (No *aux = lista; aux != NULL; aux = aux->proximo) {
            if (verificaNome(aux->nomeCompleto, nomeCompleto)) {
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
        }
    } else {
        printf("Lista Vazia!");
        printf("\n");
        printf("\n");
    }
}
