//
//  main.c
//  Projeto 5
//
//  Created by Vinícius Cantuária on 12/06/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//
// Mateus de Oliveira Barbosa - 14/0154817
// Vinícius de Castro Cantuária - 14/0165169
//

#include "arvore.h"
#include "servicos.h"

int main(int argc, const char * argv[]) {
    char nomeArquivo[5];
    char arquivo[] = {"../BSTs/\0\0\0\0.txt"};
    int opcao = 11;
    No *raiz = NULL;
    int valor = 0;

    do {
        do {
            imprimeMenu(&opcao);
        } while (opcao < 0 || opcao > 10);

        switch (opcao) {
            case 1:
                printf("Nome do arquivo sem extensão: ");
                fgets(nomeArquivo, 5, stdin);

                for (int i = 0; i < 4; i++) {
                    arquivo[8 + i] = nomeArquivo[i];
                }

                raiz = loadTreeFromFile(arquivo);

                if (raiz) {
                    printf("\nÁrvore carregada com sucesso!");
                } else {
                    printf("\nÁrvore não carregada!");
                }
                break;
            case 2:
//                showTree(raiz);
                break;
            case 3:
//                isFull(raiz);
                break;
            case 4:
               printf("Valor a ser procurado na árvore: ");
               scanf("%d", &valor);

               searchValue(raiz, valor);
                break;
            case 5:
                printf("Altura da árvore: %d", getHeight(raiz));
                break;
            case 6:
              printf("Escolha o valor a ser removido da arvore: ");
              scanf("%d", &valor);
               removeValue(&raiz, valor);
                break;
            case 7:
                if (raiz) {
                    printf("Árvore em ordem: ");
                    printInOrder(raiz);
                } else {
                    printf("Árvore vazia!");
                }
                break;
            case 8:
                if (raiz) {
                    printf("Árvore em pré-ordem: ");
                    printPreOrder(raiz);
                } else {
                    printf("Árvore vazia!");
                }
                break;
            case 9:
                if (raiz) {
                    printf("Árvore em pós-ordem: ");
                    printPostOrder(raiz);
                } else {
                    printf("Árvore vazia!");
                }
                break;
            case 10:
//                balanceTree(&raiz);
                break;
            default:
                break;
        }
        printf("\n\n");
    } while (opcao != 0);

    return 0;
}
