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
    int horas = 8;
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
    
    int quantidadeTempo = 0;
    while (filaPistaUm->inicio != NULL || filaPistaDois->inicio != NULL || filaPistaTres->inicio != NULL) {
        imprimeEvento(filaPistaUm, 1, horas, minutos);
        imprimeEvento(filaPistaDois, 2, horas, minutos);
        imprimeEvento(filaPistaTres, 3, horas, minutos);
        incrementaTempo(&horas, &minutos, 1);
        quantidadeTempo++;
        
        incrementaTempo(&horas, &minutos, 1);
        quantidadeTempo++;
        removeVooDaFila(&filaPistaTres);
        imprimeEvento(filaPistaTres, 3, horas, minutos);

        if (quantidadeTempo == 10) {
            diminueNivelCombustivel(filaPistaUm);
            diminueNivelCombustivel(filaPistaDois);
            quantidadeTempo = 0;
        }
        
        incrementaTempo(&horas, &minutos, 2);
        quantidadeTempo += 2;
        removeVooDaFila(&filaPistaUm);
        removeVooDaFila(&filaPistaDois);
        removeVooDaFila(&filaPistaTres);

        if (quantidadeTempo == 10) {
            diminueNivelCombustivel(filaPistaUm);
            diminueNivelCombustivel(filaPistaDois);
            quantidadeTempo = 0;
        }
    }
    
    desalocaFila(filaPistaUm);
    desalocaFila(filaPistaDois);
    desalocaFila(filaPistaTres);
    
    return 0;
}
