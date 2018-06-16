//
//  servicos.c
//  src
//
//  Created by Vinícius Cantuária on 13/06/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#include "servicos.h"

void imprimeMenu(int *opcao) {
    printf("Menu\n");
    printf("1 - Carregar árvore no arquivo\n");
    printf("2 - Imprimir árvore\n");
//    printf("3 - Mostrar se árvore está cheia\n");
//    printf("4 - Procurar valor na árvore\n");
    printf("5 - Mostrar altura da árvore\n");
   printf("6 - Remover valor da árvore\n");
    printf("7 - Imprimir valores da árvore em ordem\n");
    printf("8 - Imprimir valores da árvore pré-ordem\n");
    printf("9 - Imprimir valores da árvore pós-ordem\n");
//    printf("10 - Balancear árvore\n");
    printf("0 - Sair\n");
    printf("Opção: ");
    scanf("%d", opcao);
    getchar();
    printf("\n");
}
