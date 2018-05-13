//
//  lista.h
//  Projeto 3
//
//  Created by Vinícius Cantuária on 10/05/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#ifndef lista_h
#define lista_h

#include "no.h"
#include "servicos.h"
#include "arquivo.h"

No *transfereContatosParaLista(FILE *contatos);

No *insereNovoRegistro(No *lista);
No *insereNo(No *lista, char nomeCompleto[], char telefoneCelular[], char endereco[], int cep, char dataDeNascimento[]);

void imprimeLista(No *lista);
void imprimeNoPorNome(No *lista);

No *excluiNosPorNome(No *lista);

#endif /* lista_h */
