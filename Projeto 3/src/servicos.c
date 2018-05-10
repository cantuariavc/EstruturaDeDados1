//
//  servicos.c
//  Projeto 3
//
//  Created by Vinícius Cantuária on 10/05/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#include "servicos.h"

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

void verificaAlocacaoChar(char *vetorAlocado) {
    if (vetorAlocado == NULL) {
        printf("Erro na alocação da memória do vetor char!\n");
        exit(1);
    }
}
