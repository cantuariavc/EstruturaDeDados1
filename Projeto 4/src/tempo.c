//
//  tempo.c
//  Projeto 4
//
//  Created by Vinícius Cantuária on 29/05/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#include "tempo.h"

void incrementaTempo(int *horas, int *minutos, int quantidade) {
    int minutosIncrementais = quantidade * 5;
    
    *minutos += minutosIncrementais;
    
    while (*minutos >= 60) {
        *minutos -= 60;
        *horas += 1;
    }
}
