//
//  no.c
//  Projeto 3
//
//  Created by Vinícius Cantuária on 11/05/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#include "no.h"

No *criaNo(char nomeCompleto[], char telefoneCelular[], char endereco[], int cep, char dataDeNascimento[], No *anterior, No *proximo) {
    No *novoNo = (No *) calloc(1, sizeof(No));
    if (novoNo == NULL) {
        printf("Erro na alocação de memória do Nó!");
        exit(1);
    }
    
    strcpy(novoNo->nomeCompleto, nomeCompleto);
    novoNo->nomeCompleto[(strlen(novoNo->nomeCompleto) - 1)] = '\0';
    
    strcpy(novoNo->telefoneCelular, telefoneCelular);
    novoNo->telefoneCelular[strlen(novoNo->telefoneCelular)] = '\0';
    
    strcpy(novoNo->endereco, endereco);
    novoNo->endereco[(strlen(novoNo->endereco) - 1)] = '\0';
    
    novoNo->cep = cep;
    
    strcpy(novoNo->dataDeNascimento, dataDeNascimento);
    novoNo->dataDeNascimento[strlen(novoNo->dataDeNascimento)] = '\0';
    
    novoNo->anterior = anterior;
    novoNo->proximo = proximo;
    
    return novoNo;
}
