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
    char nomeCompleto[TAMANHONOMECOMPLETO];
    char telefoneCelular[TAMANHOTELEFONECELULAR];
    char endereco[TAMANHOENDERECO];
    int cep = 0;
    char dataDeNascimento[TAMANHODATADENASCIMENTO];
    char cifrao = '\0';
    
    while (fscanf(contatos, "%s\n%s\n%s\n%d\n%s\n%c", &nomeCompleto[0], &telefoneCelular[0], &endereco[0], &cep, &dataDeNascimento[0], &cifrao) != EOF) {
        insereNo(lista, nomeCompleto, telefoneCelular, endereco, cep, dataDeNascimento);
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
