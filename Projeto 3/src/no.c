//
//  no.c
//  src
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
    
    for (int i = 0; i < TAMANHONOMECOMPLETO; i++) {
        if (nomeCompleto[i] == '\n') {
            novoNo->nomeCompleto[i] = '\0';
        } else {
            novoNo->nomeCompleto[i] = nomeCompleto[i];
        }
        
        if (endereco[i] == '\n') {
            novoNo->endereco[i] = '\0';
        } else {
            novoNo->endereco[i] = endereco[i];
        }
    }
    
    for (int i = 0; i < TAMANHOTELEFONECELULAR; i++) {
        novoNo->telefoneCelular[i] = telefoneCelular[i];
        novoNo->dataDeNascimento[i] = dataDeNascimento[i];
    }
    novoNo->telefoneCelular[10] = '\0';
    novoNo->dataDeNascimento[10] = '\0';
    
    novoNo->cep = cep;
    
    novoNo->anterior = anterior;
    novoNo->proximo = proximo;
    
    return novoNo;
}
