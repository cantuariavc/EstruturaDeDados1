//
//  servicos.h
//  Projeto 3
//
//  Created by Vinícius Cantuária on 10/05/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#ifndef servicos_h
#define servicos_h

#include "lista.h"

void verificaAlocacaoArquivo(FILE *nomeArquivo);
void transfereContatosParaLista(FILE *contatos, No *lista);
void imprimeMenu(void);
int validaCelular(char telefoneCelular[]);
int validaDataDeNacimento(char dataDeNascimento[]);
int validaFormato(char dataDeNascimento[]);
int validaDia(int dia);
int validaMes(int mes);
int validaAno(int ano);
char *alocaChar(int tamanho);
void realocaChar(char *vetorChar, int tamanho);
void verificaAlocacaoChar(char *vetorAlocado);

#endif /* servicos_h */
