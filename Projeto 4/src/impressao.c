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

void imprimeTempo(char frase[], int horas, int minutos) {
    if (minutos >= 10) {
        printf("%s: %dh%d\n", frase, horas, minutos);
    } else {
        printf("%s: %dh0%d\n", frase, horas, minutos);
    }
}

void imprimeFilaDePedidos(Fila *filaPistaUm, Fila *filaPistaDois, Fila *filaPistaTres) {
    Voo *vooPistaUm = filaPistaUm->inicio;
    Voo *vooPistaDois = filaPistaDois->inicio;
    Voo *vooPistaTres = filaPistaTres->inicio;
    
    int prioridade = 1;
    int printCount = 0;
    
    printf("Fila de pedidos: [código do voo – P/D – prioridade]\n");
    while (vooPistaUm != NULL || vooPistaDois != NULL || vooPistaTres != NULL) {
        if (vooPistaUm != NULL) {
            printCount += printf("\t\t\t\t %s - %c - %d\n", vooPistaUm->codigo, vooPistaUm->status, prioridade);
            vooPistaUm = vooPistaUm->proximo;
        }
        
        if (vooPistaDois != NULL) {
            printCount += printf("\t\t\t\t %s - %c - %d\n", vooPistaDois->codigo, vooPistaDois->status, prioridade);
            vooPistaDois = vooPistaDois->proximo;
        }
        
        if (vooPistaTres != NULL) {
            printCount += printf("\t\t\t\t %s - %c - %d\n", vooPistaTres->codigo, vooPistaTres->status, prioridade);
            vooPistaTres = vooPistaTres->proximo;
        }
        
        if (printCount == 60) {
            prioridade++;
            printCount = 0;
            printf("\n");
        }
    }
}

void imprimeStatusVoo(char status) {
    if (status == 'D') {
        printf("Status: aeronave decolou\n");
    } else {
        printf("Status: aeronave pousou\n");
    }
}

void imprimeRelatorioGeral(int horas, int minutos, Fila *filaPistaUm, Fila *filaPistaDois, Fila *filaPistaTres, int tamanhoVetorAproximacoes, int tamanhoVetorDecolagens) {
    imprimeTracos();
    printf("\nAeroporto Internacional de Brasília\n");
    imprimeTempo("Hora Inicial", horas, minutos);
    imprimeFilaDePedidos(filaPistaUm, filaPistaDois, filaPistaTres);
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