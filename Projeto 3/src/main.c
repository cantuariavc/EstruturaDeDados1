//
//  main.c
//  Projeto 3
//
//  Created by Vinícius Cantuária on 10/05/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//
// Mateus de Oliveira Barbosa - 14/0154817
// Vinícius de Castro Cantuária - 14/0165169
//

#include "lista.h"
#include "servicos.h"

int main(int argc, const char * argv[]) {
    char caminhoArquivo[] = "../contatos.txt\0";
    FILE *contatos = abreArquivo(caminhoArquivo);
    No *lista = transfereContatosParaLista(contatos);
    fclose(contatos);
    
    int opcao = 5;
    do {
        do {
            imprimeMenu(&opcao);
        } while (opcao < 0 || opcao > 4);
        
        switch (opcao) {
            case 1:
                lista = insereNovoRegistro(lista);
                break;
            case 2:
                lista = excluiNosPorNome(lista);
                break;
            case 3:
                imprimeNoPorNome(lista);
                break;
            case 4:
                imprimeLista(lista);
                break;
            default:
                gravaListaNoArquivo(lista, caminhoArquivo);
                break;
        }
    } while (opcao != 0);
    
    return 0;
}
