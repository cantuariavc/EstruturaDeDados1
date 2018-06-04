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

void imprimeTracos(void);
void imprimeStatusVoo(char status);
void imprimeTempo(char frase[], int horas, int minutos);
void imprimeRelatorioGeral(int horas, int minutos, Fila *filaAproximacoes, Fila *filaDecolagens, int tamanhoVetorAproximacoes, int tamanhoVetorDecolagens);
void imprimeEvento(Fila *pista, int numeroPista, int horas, int minutos);

#endif /* impressao_h */
