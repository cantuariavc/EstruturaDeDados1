//
//  main.c
//  Projeto 4
//
//  Created by Vinícius Cantuária on 29/05/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//
// Mateus de Oliveira Barbosa - 14/0154817
// Vinícius de Castro Cantuária - 14/0165169
//

#include "fila.h"
#include "impressao.h"
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
    
    Fila *filaPistaUm = alocaEstruturaFila();
    Fila *filaPistaDois = alocaEstruturaFila();
    Fila *filaPistaTres = alocaEstruturaFila();
    
    realocaVoosNaFilasDasPistas(&filaAproximacoes, &filaDecolagens, &filaPistaUm, &filaPistaDois, &filaPistaTres);
    
    imprimeRelatorioGeral(horas, minutos, filaPistaUm, filaPistaDois, filaPistaTres, tamanhoVetorAproximacoes, tamanhoVetorDecolagens);
    imprimeRelatorioDeEventos(horas, minutos, filaPistaUm, filaPistaDois, filaPistaTres);
    
    desalocaFila(filaPistaUm);
    desalocaFila(filaPistaDois);
    desalocaFila(filaPistaTres);
    
    return 0;
}
