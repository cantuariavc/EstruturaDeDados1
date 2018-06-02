//
//  tempo.h
//  Projeto 4
//
//  Created by Vinícius Cantuária on 29/05/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#ifndef tempo_h
#define tempo_h

int tempoInicial(void);
void incrementaHoras(int *horas, int minutos, int quantidade);
void incrementaMinutos(int *minutos, int quantidade);
void incrementaTempo(int *horas, int *minutos, int quantidade);

#endif /* tempo_h */
