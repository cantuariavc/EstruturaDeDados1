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
                
                if (raiz != NULL) {
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
//                getHeight(raiz);
                break;
            case 6:
//                removeValue(&raiz, valor);
                break;
            case 7:
                printf("Árvore em ordem: ");
                printInOrder(raiz);
                break;
            case 8:
                printf("Árvore em pré-ordem: ");
                printPreOrder(raiz);
                break;
            case 9:
//                printPostOrder(raiz);
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
