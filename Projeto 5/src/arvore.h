//
//  arvore.h
//  Projeto 5
//
//  Created by Vinícius Cantuária on 12/06/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#ifndef arvore_h
#define arvore_h

#include <stdio.h>
#include <stdio.h>

#include "arquivo.h"
#include "no.h"

No *loadTreeFromFile(char nomeDoArquivo[]);
void showTree(No *raiz);
int isFull(No *raiz);
int searchValue(No *raiz, int valor);
int getHeight(No *raiz);
void removeValue(No **raiz, int valor);
void printInOrder(No *raiz);
void printPreOrder(No *raiz);
void printPostOrder(No *raiz);
void balanceTree(No *raiz);
int checkIfTreeIsBalanced(No *raiz);
int calculateBalanceFactor(No *raiz);
No* balanceNode(No *raiz);
No* rotateLeftLeft(No *raiz);
No* rotateLeftRight(No *raiz);
No* rotateRightLeft(No *raiz);
No* rotateRightRight(No *raiz);


void printGivenLevel(No* raiz, int nivel);
No *MaiorDireita(No **no);
No *MenorEsquerda(No **no);

#endif /* arvore_h */
