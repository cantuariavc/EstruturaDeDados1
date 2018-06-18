//
//  arvore.c
//  Projeto 5
//
//  Created by Vinícius Cantuária on 12/06/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#include "arvore.h"

No *loadTreeFromFile(char nomeDoArquivo[]) {
    FILE *arquivo = abreArquivo(nomeDoArquivo);
    if (!arquivo) {
        return NULL;
    }

    No *raiz = NULL;
    int valor = 0;

    while (fscanf(arquivo, "%d", &valor) != EOF) {
        insereNo(&raiz, valor);
    }

    return raiz;
}

void showTree(No *raiz) {
    int h = getHeight(raiz);
    for (int i = 0; i <= h; i++) {
        printGivenLevel(raiz, i);
        printf("\n");
    }
}

void printGivenLevel(No* raiz, int nivel) {
    if (!raiz) {
        printf("* ");
    } else {
        if (nivel == 0) {
            printf("%d ", raiz->valor);
        } else if (nivel > 0) {
            printGivenLevel(raiz->esquerda, nivel-1);
            printGivenLevel(raiz->direita, nivel-1);
        }
    }
}

int isFull(No *raiz) {
    if (!raiz) {
        return 1;
    } else if (!raiz->esquerda && !raiz->direita) {
        return 1;
    } else if (raiz->esquerda && raiz->direita) {
        return (isFull(raiz->esquerda) && isFull(raiz->direita));
    }

    return 0;
}

int searchValue(No *raiz, int valor) {
    int encontrado = 0;

    if (raiz) {
        if (raiz->valor == valor) {
            return 1;
        } else if (valor < raiz->valor && raiz->esquerda != NULL) {
            encontrado = searchValue(raiz->esquerda, valor);
        } else if (valor > raiz->valor && raiz->direita != NULL) {
            encontrado = searchValue(raiz->direita, valor);
        } else {
            printf("Valor não encontrado!\n\n");
        }

        if (encontrado) {
//            printf("Nível do nó: %d", );

            printf("Valor do pai: %d\n", raiz->valor);
            if (raiz->esquerda != NULL && valor == raiz->esquerda->valor && raiz->direita != NULL) {
                printf("Valor do irmão a direita: %d\n", raiz->direita->valor);
            } else if (raiz->direita != NULL && valor == raiz->direita->valor && raiz->esquerda != NULL) {
                printf("Valor do irmão a esquerda: %d\n", raiz->esquerda->valor);
            } else {
                printf("Não possue irmão.\n");
            }

            return 0;
        }
    }

    return encontrado;
}

int getHeight(No *raiz) {
    if (!raiz) {
        return -1;
    } else {
        int esquerda = getHeight(raiz->esquerda);
        int direita = getHeight(raiz->direita);

        if (esquerda > direita) {
            return esquerda + 1;
        } else {
            return direita + 1;
        }
    }
}

void removeValue(No **raiz, int valor) {
    if (!(*raiz)) {
        printf("Este valor não existe na árvore!");

        return;
    }

    if (valor < (*raiz)->valor) {
        removeValue(&(*raiz)->esquerda, valor);
    } else {
        if (valor > (*raiz)->valor) {
            removeValue(&(*raiz)->direita, valor);
        } else {
            No *pAux = *raiz;
            if (!(*raiz)->esquerda && !(*raiz)->direita) {
                free(pAux);
                (*raiz) = NULL;
            } else {
                if ((*raiz)->esquerda == NULL) {
                    (*raiz) = (*raiz)->direita;
                    pAux->direita = NULL;
                    free(pAux);
                    pAux = NULL;
                } else {
                    if (!(*raiz)->direita) {
                        (*raiz) = (*raiz)->esquerda;
                        pAux->esquerda = NULL;
                        free(pAux);
                        pAux = NULL;
                    } else {
                        pAux = MaiorDireita(&(*raiz)->esquerda);
                        pAux->esquerda = (*raiz)->esquerda;
                        pAux->direita = (*raiz)->direita;
                        (*raiz)->esquerda = (*raiz)->direita = NULL;
                        free((*raiz));
                        *raiz = pAux;
                        pAux = NULL;
                    }
                }
            }
        }
    }
}

No *MaiorDireita(No **no) {
    if ((*no)->direita) {
        return MaiorDireita(&(*no)->direita);
    } else {
        No *aux = *no;
        if ((*no)->esquerda) {
            *no = (*no)->esquerda;
        } else {
            *no = NULL;
        }

        return aux;
    }
}

No *MenorEsquerda(No **no) {
    if ((*no)->esquerda) {
        return MenorEsquerda(&(*no)->esquerda);
    } else {
        No *aux = *no;
        if ((*no)->direita) {
            *no = (*no)->direita;
        } else {
            *no = NULL;
        }

        return aux;
    }
}

void printInOrder(No *raiz) {
    if (raiz) {
        printInOrder(raiz->esquerda);
        printf("%d\t", raiz->valor);
        printInOrder(raiz->direita);
    }
}

void printPreOrder(No *raiz) {
    if (raiz) {
        printf("%d\t", raiz->valor);
        printPreOrder(raiz->esquerda);
        printPreOrder(raiz->direita);
    }
}

void printPostOrder(No *raiz) {
    if (raiz) {
        printPostOrder(raiz->esquerda);
        printPostOrder(raiz->direita);
        printf("%d\t", raiz->valor);
    }
}

//void balanceTree(No **raiz);
