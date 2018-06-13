//
//  arquivo.c
//  Projeto 5
//
//  Created by Vinícius Cantuária on 12/06/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#include "arquivo.h"

FILE *abreArquivo(char caminhoArquivo[]) {
    FILE *arquivo = fopen(caminhoArquivo, "r");
    
    if (arquivo == NULL) {
        printf("Erro na abertura da arquivo!\n");
    }
    
    return arquivo;
}
