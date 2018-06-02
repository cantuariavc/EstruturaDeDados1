//
//  fila.c
//  Projeto 4
//
//  Created by Vinícius Cantuária on 30/05/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#include "fila.h"

Fila *alocaEstruturaFila() {
    Fila *estruturaFila = (Fila *) calloc(1, sizeof(Fila));
    verificaAlocacaoEstruturaFila(estruturaFila);
    
    return estruturaFila;
}

void verificaAlocacaoEstruturaFila(Fila *estruturaFila) {
    if (estruturaFila == NULL) {
        printf("Erro na alocação da memória da estrutura Fila!\n");
        exit(1);
    }
}

void desalocaFila(Fila *fila) {
    Voo *aux = fila->inicio;
    
    while (aux != NULL) {
        aux = aux->proximo;
        free(fila->inicio);
        fila->inicio = aux;
    }
    
    free(fila);
}

Fila *criaNovaFila(Voo *inicio, Voo *fim) {
    Fila *novaFila = alocaEstruturaFila();
    novaFila->inicio = inicio;
    novaFila->fim = fim;
    
    return novaFila;
}

Fila *insereNovoVooNaFila(Fila *fila, Voo *novoVoo) {
    Voo *aux = fila->inicio;
    
    if (aux != NULL) {
        while (aux->proximo != NULL) {
            aux = aux->proximo;
        }
        
        aux->proximo = novoVoo;
        fila->fim = novoVoo;
        fila->fim->proximo = NULL;
    } else {
        fila->inicio = novoVoo;
        fila->fim = novoVoo;
        fila->fim->proximo = NULL;
    }
    
    return fila;
}

Fila *insereNovoVooNaFilaPorNivelCombustivel(Fila *fila, Voo *novoVoo) {
    Voo *aux = fila->inicio;

    if (novoVoo->quantidadeDeCombustivel <= fila->inicio->quantidadeDeCombustivel) {
        novoVoo->proximo = fila->inicio;
        fila->inicio = novoVoo;
    } else if (novoVoo->quantidadeDeCombustivel >= fila->fim->quantidadeDeCombustivel) {
        fila->fim->proximo = novoVoo;
        fila->fim = novoVoo;
    } else {
        while (novoVoo->quantidadeDeCombustivel < aux->proximo->quantidadeDeCombustivel) {
            aux = aux->proximo;
        }
        novoVoo->proximo = aux->proximo;
        aux->proximo = novoVoo;
    }

    return fila;
}

Fila *geraFilaAproximacoes(int tamanhoVetorAproximacoes, int *vetorComNumerosAleatorios) {
    char codigosVoos[64][6] = {"VG3001", "JJ4404", "LN7001", "TG1501", "GL7602", "TT1010", "AZ1009", "AZ1008", "AZ1010", "TG1506", "VG3002", "JJ4402", "GL7603", "RL7880", "AL0012", "TT4544", "TG1505", "VG3003", "JJ4403", "JJ4401", "LN7002", "AZ1002", "AZ1007", "GL7604", "AZ1006", "TG1503", "AZ1003", "JJ4403", "AZ1001", "LN7003", "AZ1004", "TG1504", "AZ1005", "TG1502", "GL7601", "TT4500", "RL7801", "JJ4410", "GL7607", "AL0029", "VV3390", "VV3392", "GF4681", "GF4690", "AZ1020", "JJ4435", "VG3010", "LF0920", "AZ1065", "LF0978", "RL7867", "TT4502", "GL7645", "LF0932", "JJ4434", "TG1510", "TT1020", "AZ1098", "BA2312", "VG3030", "BA2304", "KL5609", "KL5610", "KL5611"};
    
    int nivelDeCombustivel = geraNumeroAleatorio(0, NIVELMAXIMOCOMBUSTIVEL);
    Voo *novoVoo = criaNovoVoo(codigosVoos[*(vetorComNumerosAleatorios)], 'A', nivelDeCombustivel, NULL);
    Fila *filaAproximacoes = criaNovaFila(novoVoo, novoVoo);
    for (int i = 1; i < tamanhoVetorAproximacoes; i++) {
        nivelDeCombustivel = geraNumeroAleatorio(0, NIVELMAXIMOCOMBUSTIVEL);
        novoVoo = criaNovoVoo(codigosVoos[*(vetorComNumerosAleatorios + i)], 'A', nivelDeCombustivel, NULL);
        insereNovoVooNaFilaPorNivelCombustivel(filaAproximacoes, novoVoo);
    }
    
    return filaAproximacoes;
}

Fila *geraFilaDecolagens(int tamanhoVetorAproximacoes, int tamanhoVetorDecolagens, int *vetorComNumerosAleatorios) {
    char codigosVoos[64][6] = {"VG3001", "JJ4404", "LN7001", "TG1501", "GL7602", "TT1010", "AZ1009", "AZ1008", "AZ1010", "TG1506", "VG3002", "JJ4402", "GL7603", "RL7880", "AL0012", "TT4544", "TG1505", "VG3003", "JJ4403", "JJ4401", "LN7002", "AZ1002", "AZ1007", "GL7604", "AZ1006", "TG1503", "AZ1003", "JJ4403", "AZ1001", "LN7003", "AZ1004", "TG1504", "AZ1005", "TG1502", "GL7601", "TT4500", "RL7801", "JJ4410", "GL7607", "AL0029", "VV3390", "VV3392", "GF4681", "GF4690", "AZ1020", "JJ4435", "VG3010", "LF0920", "AZ1065", "LF0978", "RL7867", "TT4502", "GL7645", "LF0932", "JJ4434", "TG1510", "TT1020", "AZ1098", "BA2312", "VG3030", "BA2304", "KL5609", "KL5610", "KL5611"};
    
    Voo *novoVoo = criaNovoVoo(codigosVoos[*(vetorComNumerosAleatorios + tamanhoVetorAproximacoes)], 'D', -1, NULL);
    Fila *filaDecolagens = criaNovaFila(novoVoo, novoVoo);
    for (int i = (tamanhoVetorAproximacoes + 1); i < tamanhoVetorDecolagens; i++) {
        novoVoo = criaNovoVoo(codigosVoos[*(vetorComNumerosAleatorios + i)], 'D', -1, NULL);
        insereNovoVooNaFila(filaDecolagens, novoVoo);
    }
    
    return filaDecolagens;
}

void insereVoosNaFilaPistaUm(Fila **filaAproximacoes, Fila **filaPistaUm) {
    Voo *vooAux = (*filaAproximacoes)->inicio->proximo;
    (*filaPistaUm) = insereNovoVooNaFila((*filaPistaUm), (*filaAproximacoes)->inicio);
    (*filaAproximacoes)->inicio = vooAux;
}

void insereVoosNaFilaPistaDois(Fila **filaAproximacoes, Fila **filaPistaDois) {
    Voo *vooAux = (*filaAproximacoes)->inicio->proximo;
    (*filaPistaDois) = insereNovoVooNaFila((*filaPistaDois), (*filaAproximacoes)->inicio);
    (*filaAproximacoes)->inicio = vooAux;
}
