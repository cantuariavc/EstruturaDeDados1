//
//  lista.c
//  Projeto 3
//
//  Created by Vinícius Cantuária on 10/05/2018.
//  Copyright © 2018 Vinícius Cantuária. All rights reserved.
//

#include "lista.h"

No *transfereContatosParaLista(FILE *contatos) {
    No *lista = NULL;
    char nomeCompleto[TAMANHONOMECOMPLETO];
    char telefoneCelular[TAMANHOTELEFONECELULAR];
    char endereco[TAMANHOENDERECO];
    int cep = 0;
    char dataDeNascimento[TAMANHODATADENASCIMENTO];
    int cifrao = 0;
    
    while (1) {
        fgets(nomeCompleto, TAMANHONOMECOMPLETO, contatos);
        fscanf(contatos, "%s", telefoneCelular);
        fgetc(contatos);
        fgets(endereco, TAMANHOENDERECO, contatos);
        fscanf(contatos, "%d", &cep);
        fgetc(contatos);
        fscanf(contatos, "%s", dataDeNascimento);
        fgetc(contatos);
        cifrao = fgetc(contatos);
        
        lista = insereNo(lista, nomeCompleto, telefoneCelular, endereco, cep, dataDeNascimento);
        
        if (fgetc(contatos) == EOF) {
            break;
        }
    }
    
    if (cifrao == -1) {
        lista = NULL;
    }
    
    return lista;
}


No *insereNovoRegistro(No *lista) {
    char nomeCompleto[TAMANHONOMECOMPLETO];
    char telefoneCelular[TAMANHOTELEFONECELULAR];
    char endereco[TAMANHOENDERECO];
    char cep[TAMANHOCEP];
    char dataDeNascimento[TAMANHODATADENASCIMENTO];
    
    printf("Nome completo: ");
    fgets(nomeCompleto, TAMANHONOMECOMPLETO, stdin);
    
    do {
        printf("Telefone celular (55555-5555): ");
        scanf("%s", telefoneCelular);
        getchar();
    } while (!validaCelular(telefoneCelular));
    
    printf("Endereço: ");
    fgets(endereco, TAMANHOENDERECO, stdin);
    
    do {
        printf("CEP (somente os números): ");
        scanf("%s", cep);
        getchar();
    } while (!validaCEP(cep));
    
    do {
        printf("Data de nascimento (dd/mm/aaaa): ");
        scanf("%s", dataDeNascimento);
        getchar();
    } while (!validaDataDeNascimento(dataDeNascimento));
    
    printf("\n");
    lista = insereNo(lista, nomeCompleto, telefoneCelular, endereco, atoi(cep), dataDeNascimento);
    
    return lista;
}


No *insereNo(No *lista, char nomeCompleto[], char telefoneCelular[], char endereco[], int cep, char dataDeNascimento[]) {
    No *novoNo = criaNo(nomeCompleto, telefoneCelular, endereco, cep, dataDeNascimento, NULL, NULL);
    
    if (lista != NULL) {
        No *aux;
        for (aux = lista; aux->proximo != NULL; aux = aux->proximo);
        
        aux->proximo = novoNo;
        novoNo->anterior = aux;
    } else {
        lista = novoNo;
    }
    
    return lista;
}


void imprimeLista(No *lista) {
    printf("Lista");
    printf("\n");
    if (lista != NULL) {
        for (No *aux = lista; aux != NULL; aux = aux->proximo) {
            printf("Nome completo: %s", aux->nomeCompleto);
            printf("\n");
            printf("Telefone celular: %s", aux->telefoneCelular);
            printf("\n");
            printf("Endereço: %s", aux->endereco);
            printf("\n");
            printf("CEP: %d", aux->cep);
            printf("\n");
            printf("Data de nascimento: %s", aux->dataDeNascimento);
            printf("\n\n");
        }
    } else {
        printf("Vazia!");
        printf("\n\n");
    }
}

void imprimeNoPorNome(No *lista) {
    int haNome = 0;

    if (lista != NULL) {
        char nomeCompleto[101];
        
        printf("Nome para pesquisa: ");
        fgets(nomeCompleto, TAMANHONOMECOMPLETO, stdin);
        for (int i = 0; i < TAMANHONOMECOMPLETO; i++) {
            if (nomeCompleto[i] == '\n') {
                nomeCompleto[i] = '\0';
                break;
            }
        }
        printf("\n");
        
        for (No *aux = lista; aux != NULL; aux = aux->proximo) {
            if (verificaNome(aux->nomeCompleto, nomeCompleto)) {
                printf("Nome completo: %s", aux->nomeCompleto);
                printf("\n");
                printf("Telefone celular: %s", aux->telefoneCelular);
                printf("\n");
                printf("Endereço: %s", aux->endereco);
                printf("\n");
                printf("CEP: %d", aux->cep);
                printf("\n");
                printf("Data de nascimento: %s", aux->dataDeNascimento);
                printf("\n\n");
                
                haNome++;
            }
        }
        
        if (haNome == 0) {
            printf("Nada encontrado!");
            printf("\n\n");
        }
    } else {
        printf("Lista Vazia!");
        printf("\n\n");
    }
}


No *excluiNosPorNome(No *lista) {
    int haNome = 0;
    
    if (lista != NULL) {
        char nomeCompleto[101];
        
        printf("Nome para exclusão: ");
        fgets(nomeCompleto, TAMANHONOMECOMPLETO, stdin);
        nomeCompleto[(strlen(nomeCompleto) - 1)] = '\0';
        printf("\n");
        
        for (No *aux = lista; aux != NULL; aux = aux->proximo) {
            if (verificaNome(aux->nomeCompleto, nomeCompleto)) {
                if (aux->proximo != NULL) {
                    aux->proximo->anterior = aux->anterior;
                }
                
                if (aux->anterior != NULL) {
                    aux->anterior->proximo = aux->proximo;
                    No *aux2 = aux->anterior;
                    free(aux);
                    aux = aux2;
                } else {
                    lista = aux->proximo;
                    free(aux);
                    aux = lista;
                }
                
                if (lista == NULL) {
                    haNome++;
                    break;
                }
                
                haNome++;
            }
        }
        
        if (haNome == 1) {
            printf("Exclusão ocorrída com sucesso!");
        } else if (haNome > 1) {
            printf("Exclusões ocorrídas com sucesso!");
        } else {
            printf("Nada encontrado!");
        }
    } else {
        printf("Lista Vazia!");
    }
    printf("\n\n");
    
    return lista;
}
