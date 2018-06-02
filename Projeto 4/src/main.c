//
//  main.c
//  Projeto 4
//
//  Created by Vinícius Cantuária on 29/05/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#include "fila.h"
#include "numeroAleatorio.h"
#include "tempo.h"
#include "voo.h"

int main(int argc, const char * argv[]) {
    int horas = tempoInicial();
    int minutos = 0;
    
    int tamanhoVetorAproximacoes = geraNumeroAleatorio(QUANTIDADEMINIMAAPROXIMACOES, QUANTIDADEMAXIMAAPROXIMACOES);
    sleep(1);
    int tamanhoVetorDecolagens = geraNumeroAleatorio(QUANTIDADEMINIMADECOLAGENS, QUANTIDADEMAXIMADECOLAGENS);
    int *vetorComNumerosAleatorios = geraVetorComNumerosAleatorios(tamanhoVetorAproximacoes + tamanhoVetorDecolagens);
    
    Fila *filaAproximacoes = geraFilaAproximacoes(tamanhoVetorAproximacoes, vetorComNumerosAleatorios);
    Fila *filaDecolagens = geraFilaDecolagens(tamanhoVetorAproximacoes, tamanhoVetorDecolagens, vetorComNumerosAleatorios);
    
    imprimeRelatorioGeral(horas, minutos, filaAproximacoes, filaDecolagens, tamanhoVetorAproximacoes, tamanhoVetorDecolagens);
    
    Fila *filaPistaUm = alocaEstruturaFila();
    Fila *filaPistaDois = alocaEstruturaFila();
    Fila *filaPistaTres = alocaEstruturaFila();

    while (1) {
        if (filaAproximacoes->inicio != NULL) {
            insereVoosNaFilaPistaUm(&filaAproximacoes, &filaPistaUm);
        } else {
            break;
        }
        
        if (filaAproximacoes->inicio != NULL) {
            insereVoosNaFilaPistaDois(&filaAproximacoes, &filaPistaDois);
        } else {
            break;
        }
    }
    free(filaAproximacoes);
    insereVoosNaFilaPistaTres(&filaDecolagens, &filaPistaTres);
    
    
    desalocaFila(filaPistaUm);
    desalocaFila(filaPistaDois);
    desalocaFila(filaPistaTres);
    
    return 0;
}
