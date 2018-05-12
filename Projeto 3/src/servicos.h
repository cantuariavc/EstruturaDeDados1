//
//  servicos.h
//  Projeto 3
//
//  Created by Vinícius Cantuária on 10/05/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#ifndef servicos_h
#define servicos_h

#include "no.h"

void imprimeMenu(int *opcao);

int validaCelular(char telefoneCelular[]);
int validaTamanhoCelular(char telefoneCelular[]);
int validaFormatoCelular(char telefoneCelular[]);
int validaCaracteresCelular(char telefoneCelular[]);

int validaCEP(char cep[]);

int validaDataDeNascimento(char dataDeNascimento[]);
int validaFormatoDataDeNascimento(char dataDeNascimento[]);
int validaDia(int dia);
int validaMes(int mes);
int validaAno(int ano);

int verificaNome(char nomeNo[], char nomePesquisa[]);

#endif /* servicos_h */
