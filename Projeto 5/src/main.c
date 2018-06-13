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

#include <string.h>

#include "arvore.h"
#include "servicos.h"

int main(int argc, const char * argv[]) {
    int opcao = 11;
    No *raiz = NULL;
    
    do {
        do {
            imprimeMenu(&opcao);
        } while (opcao < 0 || opcao > 10);
        
        switch (opcao) {
            case 1:
//                raiz = loadTreeFromFile(arquivo);
                break;
            case 2:
//                showTree(raiz);
                break;
            case 3:
//                isFull(raiz);
                break;
            case 4:
//                searchValue(raiz);
                break;
            case 5:
//                getHeight(raiz);
                break;
            case 6:
//                removeValue(&raiz, valor);
                break;
            case 7:
//                printInOrder(raiz);
                break;
            case 8:
//                printPreOrder(raiz);
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
    } while (opcao != 0);
    
    return 0;
}
