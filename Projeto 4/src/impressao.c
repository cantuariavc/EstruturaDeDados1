//
//  impressao.c
//  Projeto 4
//
//  Created by Vinícius Cantuária on 03/06/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#include "impressao.h"

void imprimeTracos() {
    for (int i = 0; i < 51; i++) {
        printf("-");
    }
}

void imprimeStatusVoo(char status) {
    if (status == 'D') {
        printf("Status: aeronave decolou\n");
    } else {
        printf("Status: aeronave pousou\n");
    }
}

void imprimeTempo(char frase[], int horas, int minutos) {
    if (minutos >= 10) {
        printf("%s: %dh%d\n", frase, horas, minutos);
    } else {
        printf("%s: %dh0%d\n", frase, horas, minutos);
    }
}

void imprimeRelatorioGeral(int horas, int minutos, Fila *filaAproximacoes, Fila *filaDecolagens, int tamanhoVetorAproximacoes, int tamanhoVetorDecolagens) {
    Voo *va = filaAproximacoes->inicio;
    Voo *vd = filaDecolagens->inicio;
    int prioridade = 1;
    int prioridadeAux = 0;
    
    imprimeTracos();
    printf("\nAeroporto Internacional de Brasília\n");
    imprimeTempo("Hora Inicial", horas, minutos);
    printf("Fila de pedidos: [código do voo – P/D – prioridade]\n");
    while (va != NULL || vd != NULL) {
        for (int i = 0; i < 2; i++) {
            if (va != NULL) {
                printf("\t\t\t\t %s - %c - %d\n", va->codigo, 'P', prioridade);
                va = va->proximo;
                prioridadeAux++;
            }
        }
        if (vd != NULL) {
            printf("\t\t\t\t %s - %c - %d\n", vd->codigo, 'D', prioridade);
            vd = vd->proximo;
            prioridadeAux++;
        }
        if (prioridadeAux == 3) {
            prioridade++;
            prioridadeAux = 0;
            printf("\n");
        }
    }
    printf("Números de Voos: %d\n", (tamanhoVetorAproximacoes + tamanhoVetorDecolagens));
    printf("Número de Aproximações: %d\n", tamanhoVetorAproximacoes);
    printf("Número de Decolagens: %d\n", tamanhoVetorDecolagens);
    imprimeTracos();
    printf("\nListagem de eventos:\n");
}

void imprimeEvento(Fila *pista, int numeroPista, int horas, int minutos) {
    if (pista->inicio != NULL) {
        printf("\nCódigo do voo: %s\n", pista->inicio->codigo);
        imprimeStatusVoo(pista->inicio->status);
        imprimeTempo("Horário do início do procedimento", horas, minutos);
        printf("Número da pista: %d\n", numeroPista);
    }
}
