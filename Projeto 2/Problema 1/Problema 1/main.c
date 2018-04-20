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
#include <string.h>
#include <time.h>

void verificaAlocacao(int *vetorAlocado);
void verificaAlocacaoMatriz(int **matrizAlocada);
void liberaMemoria(int *vetorAlocado);
void liberaMatriz(int **matrizAlocada, int quatidadeLinhas);
void geraNumerosAleatorios(int *vetorNumerosTreinamento, int *vetorNumerosTeste);
int numeroExistente(int *vetorNumerosAleatorios, int tamanho, int numnumeroGeradoero);
void verificaImagem(FILE *imagemTexto);
void contaTamanhoLinhas(FILE *imagemTexto, int *quantidadeLinhas);
void contaTamanhoColunas(FILE *imagemTexto, int *quantidadeColunas);
void transfereImagemTexto(FILE *imagemTexto, int **imagemPrograma, int quantidadeLinhas, int quantidadeColunas);

int main(int argc, const char * argv[]) {
    char nomeImagem[] = "/Users/cantuariavc/Desktop/Estrutura de Dados 1/GitHub/EstruturaDeDados1/Projeto 2/DataSet/grass/texts/grass_50.txt";
    FILE *imagemTexto = fopen(nomeImagem, "r");
    verificaImagem(imagemTexto);

    int quatidadeLinhas = 0;
    contaTamanhoLinhas(imagemTexto, &quatidadeLinhas);
    int quantidadeColunas = 0;
    contaTamanhoColunas(imagemTexto, &quantidadeColunas);

    int **imagemPrograma = (int **) calloc(quatidadeLinhas, sizeof(int *));
    verificaAlocacaoMatriz(imagemPrograma);
    for (int i = 0; i < quatidadeLinhas; i++) {
        *(imagemPrograma + i) = (int *) calloc(quantidadeColunas, sizeof(int));
    }
    verificaAlocacao(*imagemPrograma);




    int *vetorNumerosTreinamento = (int *) calloc(25, sizeof(int));
    verificaAlocacao(vetorNumerosTreinamento);
    int *vetorNumerosTeste = (int *) calloc(25, sizeof(int));
    verificaAlocacao(vetorNumerosTeste);


    geraNumerosAleatorios(vetorNumerosTreinamento, vetorNumerosTeste);



    liberaMemoria(vetorNumerosTreinamento);
    liberaMemoria(vetorNumerosTeste);
    liberaMatriz(imagemPrograma, quatidadeLinhas);
    fclose(imagemTexto);

    return 0;
}

void verificaAlocacao(int *vetorAlocado) {
    if (vetorAlocado == NULL) {
        printf("Erro na alocação da memória!\n");
        exit(1);
    }
}

void verificaAlocacaoMatriz(int **matrizAlocada) {
    if (matrizAlocada == NULL) {
        printf("Erro na alocação da memória!\n");
        exit(1);
    }
}

void liberaMemoria(int *vetorAlocado) {
    free(vetorAlocado);
}

void liberaMatriz(int **matrizAlocada, int quatidadeLinhas) {
    for (int i = 0; i < quatidadeLinhas; i++) {
        free(*(matrizAlocada + i));
    }

    free(matrizAlocada);
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

void verificaImagem(FILE *imagemTexto) {
    if (imagemTexto == NULL) {
        printf("Erro na abertura da imagemTexto!\n");
        exit(1);
    }
}

void contaTamanhoLinhas(FILE *imagemTexto, int *quantidadeLinhas) {
    char caractere = '\0';

    do {
        caractere = getc(imagemTexto);

        if (caractere == ';') {
            (*quantidadeLinhas)++;
        }
    } while (caractere != '\n');

    (*quantidadeLinhas)++;
}

void contaTamanhoColunas(FILE *imagemTexto, int *quantidadeColunas) {
    char caractere = '\0';

    do {
        caractere = getc(imagemTexto);

        if (caractere == ';') {
            (*quantidadeColunas)++;
        }
    } while (caractere != '\n');

    (*quantidadeColunas)++;
}

void transfereImagemTexto(FILE *imagemTexto, int **imagemPrograma, int quantidadeLinhas, int quantidadeColunas) {
//    char caractere = '\0';
//    char *numeroString = (char *) calloc(3, sizeof(char));
//    if (numeroString == NULL) {
//        printf("Erro na alocação de memória!\n");
//        exit(1);
//    }
//    int numero = 0;
//
//    do {
//        caractere = getc(imagemTexto);
//        if (caractere != ';') {
//            strcat(numeroString, &caractere);
//        } else {
//            numero = atoi(numeroString);
//        }
//    } while (caractere != '\n');
//
//    free(numeroString);
}






