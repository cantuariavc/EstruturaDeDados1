//
//  main.c
//  Lista Simples
//
//  Created by Vinícius Cantuária on 08/05/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#include "lista.h"
#include "servicos.h"

int main(int argc, const char * argv[]) {
    No *lista = criaLista();
    int opcao = 5;
    
    do {
        while (opcao < 0 || opcao > 4) {
            imprimeMenu();
            scanf("%d", &opcao);
        }
        
        switch (opcao) {
            case 1:
                // Inseri nó
                break;
            case 2:
                // Imprime lista
                break;
            case 3:
                // Exclui nó
                break;
            case 4:
                // Exclui lista
                break;
            default:
                break;
        }
    } while (opcao != 0);

    return 0;
}
