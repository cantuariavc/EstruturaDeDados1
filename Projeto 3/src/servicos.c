//
//  servicos.c
//  Projeto 3
//
//  Created by Vinícius Cantuária on 10/05/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#include "servicos.h"

void verificaAlocacaoArquivo(FILE *nomeArquivo) {
    if (nomeArquivo == NULL) {
        printf("Erro na abertura da arquivo!\n");
        exit(1);
    }
}

void transfereContatosParaLista(FILE *contatos, No *lista) {
    No *aux = lista;
    int cifrao = 0;
    
    while (1) {
        char *nomeCompleto = alocaChar(TAMANHONOMECOMPLETO);
        
        if (*(nomeCompleto + 0) == EOF) {
            break;
        }
        
        char *telefoneCelular = alocaChar(TAMANHOTELEFONECELULAR);
        char *endereco = alocaChar(TAMANHOENDERECO);
        char *cep = alocaChar(TAMANHOCEP);
        char *dataDeNascimento = alocaChar(TAMANHODATADENASCIMENTO);
        
        fgets(nomeCompleto, TAMANHONOMECOMPLETO, contatos);
        fgets(telefoneCelular, TAMANHOTELEFONECELULAR, contatos);
        fgets(endereco, TAMANHOENDERECO, contatos);
        fgets(cep, TAMANHOCEP, contatos);
        fgets(dataDeNascimento, TAMANHODATADENASCIMENTO, contatos);
        cifrao = fgetc(contatos);
        
        realocaChar(nomeCompleto, sizeof(nomeCompleto));
        realocaChar(telefoneCelular, sizeof(telefoneCelular));
        realocaChar(endereco, sizeof(endereco));
        realocaChar(cep, sizeof(cep));
        realocaChar(dataDeNascimento, sizeof(dataDeNascimento));
        
        insereNo(aux, nomeCompleto, telefoneCelular, endereco, cep, dataDeNascimento);
    }
}

void imprimeMenu(void) {
    printf("Menu");
    printf("\n");
    printf("1 - Inserir novo registro");
    printf("\n");
    printf("2 - Remover registros que possuem certo nome");
    printf("\n");
    printf("3 - Visualizar registro a partir do nome");
    printf("\n");
    printf("4 - Visualizar todos os registros em ordem alfabética de acordo com o nome");
    printf("\n");
    printf("0 - Sair");
    printf("\n");
    printf("Opção: ");
}

char *alocaChar(int tamanho) {
    char *vetorChar = (char *) calloc(tamanho, sizeof(char));
    verificaAlocacaoChar(vetorChar);
    
    return vetorChar;
}

void realocaChar(char *vetorChar, int tamanho) {
    vetorChar = (char *) realloc(vetorChar, tamanho);
    verificaAlocacaoChar(vetorChar);
}

void verificaAlocacaoChar(char *vetorAlocado) {
    if (vetorAlocado == NULL) {
        printf("Erro na alocação da memória do vetor char!\n");
        exit(1);
    }
}
