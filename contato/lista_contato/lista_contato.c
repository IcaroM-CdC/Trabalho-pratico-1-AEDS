#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "lista_contato.h"

int cria_lista_contato(tipo_lista_contato *lista_contato){
    
    lista_contato -> ponteiro_primeiro = (lista_ponteiro_contato) malloc(sizeof(celula_contato));
    lista_contato -> ponteiro_ultimo = lista_contato -> ponteiro_primeiro;
    lista_contato -> ponteiro_primeiro -> proximo = NULL;

}

int insere_contato_base(tipo_lista_contato *lista_contato, char *nome, char *sobrenome, char *comentario, char *email, char *telefone){
    
    tipo_contato *contato = cria_contato(nome, sobrenome, comentario, email, telefone);
    
    lista_contato -> ponteiro_ultimo -> proximo = (lista_ponteiro_contato) malloc(sizeof (celula_contato));
    lista_contato -> ponteiro_ultimo = lista_contato -> ponteiro_ultimo -> proximo;

    if (lista_contato -> ponteiro_ultimo != NULL){
        
        lista_contato -> ponteiro_ultimo -> dados.nome = preenche_string(sizeof(contato -> nome));
        lista_contato -> ponteiro_ultimo -> dados.sobrenome = preenche_string(sizeof(contato -> sobrenome));
        lista_contato -> ponteiro_ultimo -> dados.comentario = preenche_string(sizeof(contato -> comentario));
        lista_contato -> ponteiro_ultimo -> dados.email = preenche_string(sizeof(contato -> email));
        lista_contato -> ponteiro_ultimo -> dados.telefone = preenche_string(sizeof(contato -> telefone));

        strcpy(lista_contato -> ponteiro_ultimo -> dados.nome, contato -> nome);
        strcpy(lista_contato -> ponteiro_ultimo -> dados.sobrenome, contato -> sobrenome);
        strcpy(lista_contato -> ponteiro_ultimo -> dados.comentario, contato -> comentario);
        strcpy(lista_contato -> ponteiro_ultimo -> dados.email, contato -> email);
        strcpy(lista_contato -> ponteiro_ultimo -> dados.telefone, contato -> telefone);

    }

    lista_contato -> ponteiro_ultimo -> proximo = NULL;
    
    return 1;    
}

int remove_contato_base(tipo_lista_contato *lista_contato, char *nome, char *sobrenome){
    
    lista_ponteiro_contato ponteiro_auxiliar = lista_contato -> ponteiro_primeiro -> proximo;
    lista_ponteiro_contato anterior_auxiliar = lista_contato -> ponteiro_primeiro;

    while (ponteiro_auxiliar != NULL){

        if (strcmp(ponteiro_auxiliar -> dados.nome, nome) == 0 && strcmp(ponteiro_auxiliar -> dados.sobrenome, sobrenome) == 0){

            break;
        }

        ponteiro_auxiliar = ponteiro_auxiliar -> proximo;
        anterior_auxiliar = anterior_auxiliar -> proximo;
    }

    if (ponteiro_auxiliar == NULL){
        return 0;
    }
    
    else {

        anterior_auxiliar -> proximo = ponteiro_auxiliar -> proximo;
        free(ponteiro_auxiliar);
        return 1;
    
    }
}

int imprime_contatos_base(tipo_lista_contato *lista_contato){
    
    lista_ponteiro_contato ponteiro_auxiliar = lista_contato -> ponteiro_primeiro -> proximo;

    if (ponteiro_auxiliar == NULL){

        printf("\n");
        printf("NENHUM CONTATO CADASTRADO !!!\n");
        printf("\n");
        return 0;
    }

    else {

        printf(":::::::::::::::::::: CONTATOS ::::::::::::::::::::\n\n");
        
        while (ponteiro_auxiliar != NULL){
            
            printf("Nome: %s %s\n", ponteiro_auxiliar -> dados.nome, ponteiro_auxiliar -> dados.sobrenome);
            printf("E-mail: %s\n", ponteiro_auxiliar -> dados.email);
            printf("Telefone: %s\n", ponteiro_auxiliar -> dados.telefone);
            printf("Comentario: %s\n\n", ponteiro_auxiliar -> dados.comentario);
        
            ponteiro_auxiliar = ponteiro_auxiliar -> proximo;
            
        }

        printf("::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");

        return 1;
    }
}

int lista_contato_vazia(tipo_lista_contato *lista_contato){

    if (lista_contato -> ponteiro_primeiro == lista_contato -> ponteiro_ultimo ){
        return 1;
    }

    else {
        return 0;
    }

}