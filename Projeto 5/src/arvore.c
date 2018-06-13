//
//  arvore.c
//  Projeto 5
//
//  Created by Vinícius Cantuária on 12/06/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#include "arvore.h"

No *loadTreeFromFile(char nomeDoArquivo[]) {
    FILE *arquivo = abreArquivo(nomeDoArquivo);
    No *raiz = NULL;
    int valor[QUANTIDADEDENUMEROS];
    
    for (int i = 0; i < QUANTIDADEDENUMEROS; i++) {
        fscanf(arquivo, "%d", (valor + i));
    }
    
    for (int i = 0; i < QUANTIDADEDENUMEROS; i++) {
        insereNo(&raiz, valor[i]);
    }
    
    return raiz;
}
