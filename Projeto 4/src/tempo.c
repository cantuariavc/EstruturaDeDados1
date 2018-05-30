//
//  tempo.c
//  Projeto 4
//
//  Created by Vinícius Cantuária on 29/05/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#include "tempo.h"

int tempoInicial() {
    int horaInicial = 8;
    
    return horaInicial;
}

int incrementaHoras(int horas, int minutos, int quantidade) {
    int minutosIncrementais = quantidade * 5;
    
    horas += (minutos + minutosIncrementais) / 60;
    
    return horas;
}
