//
//  main.c
//  Projeto 4
//
//  Created by Vinícius Cantuária on 29/05/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#include "fila.h"
#include "numeroAleatorio.h"
#include "voo.h"

int main(int argc, const char * argv[]) {
    int tamanhoVetorAproximacoes = geraNumeroAleatorio(QUANTIDADEMINIMAAPROXIMACOES, QUANTIDADEMAXIMAAPROXIMACOES);
    int tamanhoVetorDecolagens = geraNumeroAleatorio(QUANTIDADEMINIMADECOLAGENS, QUANTIDADEMAXIMADECOLAGENS);
    int *vetorComNumerosAleatorios = geraVetorComNumerosAleatorios(tamanhoVetorAproximacoes + tamanhoVetorDecolagens);
    
    Fila *filaAproximacoes = geraFilaAproximacoes(tamanhoVetorAproximacoes, vetorComNumerosAleatorios);
    Fila *filaDecolagens = geraFilaDecolagens(tamanhoVetorAproximacoes, tamanhoVetorDecolagens, vetorComNumerosAleatorios);

    desalocaFila(filaAproximacoes);
    desalocaFila(filaDecolagens);
    
    return 0;
}
