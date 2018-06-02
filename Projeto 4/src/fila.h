//
//  fila.h
//  Projeto 4
//
//  Created by Vinícius Cantuária on 29/05/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#ifndef fila_h
#define fila_h

#include "voo.h"
#include "numeroAleatorio.h"

typedef struct fila {
    Voo *inicio;
    Voo *fim;
} Fila;

Fila *alocaEstruturaFila(void);
void verificaAlocacaoEstruturaFila(Fila *estruturaFila);
void desalocaFila(Fila *fila);

Fila *criaNovaFila(Voo *inicio, Voo *fim);
Fila *insereNovoVooNaFila(Fila *fila, Voo *novoVoo);
void removeVooDaFila(Fila **fila);
Fila *insereNovoVooNaFilaPorNivelCombustivel(Fila *fila, Voo *novoVoo);

Fila *geraFilaAproximacoes(int tamanhoVetorAproximacoes, int *vetorComNumerosAleatorios);
Fila *geraFilaDecolagens(int tamanhoVetorAproximacoes, int tamanhoVetorDecolagens, int *vetorComNumerosAleatorios);

void insereVoosNaFilaPistaUm(Fila **filaAproximacoes, Fila **filaPistaUm);
void insereVoosNaFilaPistaDois(Fila **filaAproximacoes, Fila **filaPistaDois);  
void insereVoosNaFilaPistaTres(Fila **filaDecolagens, Fila **filaPistaTres);

void diminueNivelCombustivel(Fila *fila);

void imprimeRelatorioGeral(int horas, int minutos, Fila *filaAproximacoes, Fila *filaDecolagens, int tamanhoVetorAproximacoes, int tamanhoVetorDecolagens);
void imprimeEvento(char codigoVoo[], char statusVoo, int horas, int minutos, int numeroPista);

#endif /* fila_h */
