//
//  arquivo.h
//  Projeto 3
//
//  Created by Vinícius Cantuária on 11/05/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#ifndef arquivo_h
#define arquivo_h

#include <unistd.h>
#include "no.h"

#define ENOENT -1

int eArquivoExistente(char caminhoArquivo[]);
FILE *abreArquivo(char caminhoArquivo[]);
void verificaAlocacaoArquivo(FILE *nomeArquivo);
void gravaListaNoArquivo(No *lista, char caminhoArquivo[]);

#endif /* arquivo_h */
