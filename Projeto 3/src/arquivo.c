//
//  arquivo.c
//  Projeto 3
//
//  Created by Vinícius Cantuária on 11/05/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#include "arquivo.h"

int eArquivoExistente(char caminhoArquivo[]) {
    int existe = 1;
    
    int errcode = access(caminhoArquivo, F_OK);
    if (errcode == ENOENT) {
        existe = 0;
    }
    
    return existe;
}

FILE *abreArquivo(char caminhoArquivo[]) {
    FILE *arquivo;
    
    if (eArquivoExistente(caminhoArquivo)) {
        arquivo = fopen(caminhoArquivo, "r");
    } else {
        arquivo = fopen(caminhoArquivo, "a+");
    }
    verificaAlocacaoArquivo(arquivo);
    
    return arquivo;
}

void verificaAlocacaoArquivo(FILE *nomeArquivo) {
    if (nomeArquivo == NULL) {
        printf("Erro na abertura da arquivo!\n");
        exit(1);
    }
}

void gravaListaNoArquivo(No *lista, char caminhoArquivo[]) {
    FILE *arquivo = fopen(caminhoArquivo, "w+");
    verificaAlocacaoArquivo(arquivo);
    
    for (No *aux = lista; aux != NULL; aux = aux->proximo) {
        fprintf(arquivo, "%s\n", aux->nomeCompleto);
        fprintf(arquivo, "%s\n", aux->telefoneCelular);
        fprintf(arquivo, "%s\n", aux->endereco);
        fprintf(arquivo, "%d\n", aux->cep);
        fprintf(arquivo, "%s\n", aux->dataDeNascimento);
        fprintf(arquivo, "%c", '$');
        if (aux->proximo != NULL) {
            fprintf(arquivo, "\n");
        }
    }
}
