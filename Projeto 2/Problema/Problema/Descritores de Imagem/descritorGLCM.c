//
//  descritorGLCM.c
//  Problema
//
//  Created by Vinícius Cantuária on 27/04/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#include "descritorGLCM.h"

void calculaFrequenciasGLCM(int **matrizDecimal, int **noroeste, int **norte, int **nordeste, int **oeste, int **leste, int **sudoeste, int **sul, int **sudeste) {
    *(*(noroeste + (*(*(matrizDecimal + 1) + 1))) + (*(*(matrizDecimal + 0) + 0))) += 1;
    *(*(norte + (*(*(matrizDecimal + 1) + 1))) + (*(*(matrizDecimal + 0) + 1))) += 1;
    *(*(nordeste + (*(*(matrizDecimal + 1) + 1))) + (*(*(matrizDecimal + 0) + 2))) += 1;
    *(*(oeste + (*(*(matrizDecimal + 1) + 1))) + (*(*(matrizDecimal + 1) + 0))) += 1;
    *(*(leste + (*(*(matrizDecimal + 1) + 1))) + (*(*(matrizDecimal + 1) + 2))) += 1;
    *(*(sudoeste + (*(*(matrizDecimal + 1) + 1))) + (*(*(matrizDecimal + 2) + 0))) += 1;
    *(*(sul + (*(*(matrizDecimal + 1) + 1))) + (*(*(matrizDecimal + 2) + 1))) += 1;
    *(*(sudeste + (*(*(matrizDecimal + 1) + 1))) + (*(*(matrizDecimal + 2) + 2))) += 1;
}
