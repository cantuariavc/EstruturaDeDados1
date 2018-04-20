//
//  main.c
//  Problema 1
//
//  Created by Vinícius Cantuária on 17/04/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//
// Mateus de Oliveira Barbosa - 14/0154817
// Vinícius de Castro Cantuária - 14/0165169
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void verificaAlocacao(int *vetorAlocado);
void liberaMemoria(int *vetorAlocado);
void geraNumerosAleatorios(int *vetorNumerosTreinamento, int *vetorNumerosTeste);
int numeroExistente(int *vetorNumerosAleatorios, int tamanho, int numnumeroGeradoero);
void verificaImagem(FILE *imagem);
void contaTamanhoColunas(FILE *imagem, int *quantidadeColunas);
void contaTamanhoLinhas(FILE *imagem, int *quantidadeLinhas);

int main(int argc, const char * argv[]) {
    char nomeImagem[] = "/Users/cantuariavc/Desktop/Estrutura de Dados 1/GitHub/EstruturaDeDados1/Projeto 2/DataSet/grass/texts/grass_50.txt";
    
    FILE *imagem = fopen(nomeImagem, "r");
    
    int *vetorNumerosTreinamento = (int *) calloc(25, sizeof(int));
    int *vetorNumerosTeste = (int *) calloc(25, sizeof(int));
    int quantidadeColunas = 0;
    int quatidadeLinhas = 0;
    
    
    verificaImagem(imagem);
    verificaAlocacao(vetorNumerosTreinamento);
    verificaAlocacao(vetorNumerosTeste);
    geraNumerosAleatorios(vetorNumerosTreinamento, vetorNumerosTeste);
    
    contaTamanhoColunas(imagem, &quantidadeColunas);
    contaTamanhoLinhas(imagem, &quatidadeLinhas);
    
    
    
    liberaMemoria(vetorNumerosTreinamento);
    liberaMemoria(vetorNumerosTeste);
    fclose(imagem);
    
    return 0;
}

void verificaAlocacao(int *vetorAlocado) {
    if (vetorAlocado == NULL) {
        printf("Erro na alocação da memória!\n");
        exit(1);
    }
}

void liberaMemoria(int *vetorAlocado) {
    free(vetorAlocado);
}

void geraNumerosAleatorios(int *vetorNumerosTreinamento, int *vetorNumerosTeste) {
    srand((unsigned int)time(NULL));
    
    int *vetorNumerosAleatorios = (int *) calloc(50, sizeof(int));
    int numeroGerado = 0;
    
    verificaAlocacao(vetorNumerosAleatorios);
    
    for (int i = 0; i < 50; i++) {
        numeroGerado = 1 + (rand() % 50);
        
        while (numeroExistente(vetorNumerosAleatorios, i, numeroGerado)) {
            numeroGerado = 1 + (rand() % 50);
        }
        
        *(vetorNumerosAleatorios + i) = numeroGerado;
    }
    
    for (int i = 0; i < 25; i++) {
        *(vetorNumerosTreinamento + i) = *(vetorNumerosAleatorios + i);
    }
    
    for (int i = 0; i < 25; i++) {
        *(vetorNumerosTeste + i) = *(vetorNumerosAleatorios + (i + 25));
    }
    
    liberaMemoria(vetorNumerosAleatorios);
}

int numeroExistente(int *vetorNumerosAleatorios, int tamanho, int numnumeroGeradoero) {
    int existe = 0;
    
    for (int i = 0; i < tamanho; i++) {
        if (*(vetorNumerosAleatorios + i) == numnumeroGeradoero) {
            existe = 1;
        }
    }
    
    return existe;
}

void verificaImagem(FILE *imagem) {
    if (imagem == NULL) {
        printf("Erro na abertura da imagem!\n");
        exit(1);
    }
}

void contaTamanhoColunas(FILE *imagem, int *quantidadeColunas) {
    char caractere = '\0';
    
    do {
        caractere = getc(imagem);
        
        if (caractere == ';') {
            (*quantidadeColunas)++;
        }
    } while (caractere != '\n');
    
    (*quantidadeColunas)++;
}

void contaTamanhoLinhas(FILE *imagem, int *quantidadeLinhas) {
    char caractere = '\0';
    
    do {
        caractere = getc(imagem);
        
        if (caractere == ';') {
            (*quantidadeLinhas)++;
        }
    } while (caractere != '\n');
    
    (*quantidadeLinhas)++;
}





