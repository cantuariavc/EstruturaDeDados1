//
//  impressao.h
//  Projeto 4
//
//  Created by Vinícius Cantuária on 03/06/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#ifndef impressao_h
#define impressao_h

#include <stdio.h>
#include "fila.h"
#include "tempo.h"

void imprimeTracos(void);
void imprimeTempo(char frase[], int horas, int minutos);
void imprimeFilaDePedidos(Fila *filaPistaUm, Fila *filaPistaDois, Fila *filaPistaTres);
void imprimeStatusVoo(char status);
void imprimeRelatorioGeral(int horas, int minutos, Fila *filaPistaUm, Fila *filaPistaDois, Fila *filaPistaTres, int tamanhoVetorAproximacoes, int tamanhoVetorDecolagens);
void imprimeEvento(Fila *pista, int numeroPista, int horas, int minutos);
void imprimeRelatorioDeEventos(int horas, int minutos, Fila *filaPistaUm, Fila *filaPistaDois, Fila *filaPistaTres);

#endif /* impressao_h */
