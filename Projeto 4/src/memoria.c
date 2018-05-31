//
//  memoria.c
//  Projeto 4
//
//  Created by Vinícius Cantuária on 30/05/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#include "memoria.h"


int *alocaInt(int tamanho) {
    int *vetorInt = (int *) calloc(tamanho, sizeof(int));
    verificaAlocacaoInt(vetorInt);
    
    return vetorInt;
}

void verificaAlocacaoInt(int *vetorAlocado) {
    if (vetorAlocado == NULL) {
        printf("Erro na alocação da memória do vetor int!\n");
        exit(4);
    }
}
