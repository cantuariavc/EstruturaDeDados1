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
    FILE *contatos = fopen(caminhoArquivo, "r");
    verificaAlocacaoArquivo(contatos);
    
    No *lista = criaLista();
    
    transfereContatosParaLista(contatos, lista);
    fclose(contatos);
    
    int opcao = 5;
    do {
        do {
            imprimeMenu();
            scanf("%d", &opcao);
            getchar();
            printf("\n");
        } while (opcao < 0 || opcao > 4);
        
        switch (opcao) {
            case 1:
                {
                    char nomeCompleto[TAMANHONOMECOMPLETO];
                    char telefoneCelular[TAMANHOTELEFONECELULAR];
                    char endereco[TAMANHOENDERECO];
                    int cep;
                    char dataDeNascimento[TAMANHODATADENASCIMENTO];
                    
                    printf("Nome completo: ");
                    fgets(nomeCompleto, TAMANHONOMECOMPLETO, stdin);
                    
                    do {
                        printf("Telefone celular (55555-5555): ");
                        fgets(telefoneCelular, TAMANHOTELEFONECELULAR, stdin);
                        getchar();
                    } while (!validaCelular(telefoneCelular));
                    
                    printf("Endereço: ");
                    fgets(endereco, TAMANHOENDERECO, stdin);
                    printf("CEP (somente os números): ");
                    scanf("%d", &cep);
                    getchar();
                    
                    do {
                        printf("Data de nascimento (dd/mm/aaaa): ");
                        fgets(dataDeNascimento, TAMANHODATADENASCIMENTO, stdin);
                        getchar();
                    } while (!validaDataDeNacimento(dataDeNascimento));
                        
                    printf("\n");
                    insereNo(lista, nomeCompleto, telefoneCelular, endereco, cep, dataDeNascimento);
                }
                break;
            case 2:
                // Remover registros que possuem certo nome
                break;
            case 3:
                // Visualizar registro a partir do nome
                break;
            case 4:
                // Visualizar todos os registros em ordem alfabética de acordo com o nome
                break;
            default:
                break;
        }
    } while (opcao != 0);
    
    return 0;
}
