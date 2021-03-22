#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "lista_professor.h"


int cria_lista_professor(tipo_lista_professor *lista){

    lista -> ponteiro_primeiro = (lista_professor_ponteiro) malloc(sizeof(celula_professor));

    if (lista -> ponteiro_primeiro != NULL){

        lista -> ponteiro_primeiro -> proximo = NULL;

        lista -> ponteiro_ultimo = lista -> ponteiro_primeiro;

        return 1;

    } else {

        return 0;
    }
}

int insere_professor(tipo_lista_professor *lista, char *nome, char *curso, char *esp, char *CPF, unsigned int idade, unsigned int senha, unsigned int ID){

    tipo_professor *professor = cria_professor(nome, curso, esp, CPF, idade, senha, ID);

    lista -> ponteiro_ultimo -> proximo = (lista_professor_ponteiro) malloc(sizeof(celula_professor));
    lista -> ponteiro_ultimo = lista -> ponteiro_ultimo -> proximo;

    if (lista -> ponteiro_ultimo != NULL){
    
        lista -> ponteiro_ultimo -> dados.CPF =   preenche_string(sizeof(professor -> CPF));
        lista -> ponteiro_ultimo -> dados.curso = preenche_string(sizeof(professor -> curso));
        lista -> ponteiro_ultimo -> dados.nome =  preenche_string(sizeof(professor -> nome));
        lista -> ponteiro_ultimo -> dados.esp =   preenche_string(sizeof(professor -> esp));

        lista -> ponteiro_ultimo -> dados.idade = professor -> idade;
        lista -> ponteiro_ultimo -> dados.senha = professor -> senha;
        lista -> ponteiro_ultimo -> dados.ID =    professor -> ID;
        
        strcpy(lista -> ponteiro_ultimo -> dados.CPF,   professor -> CPF);
        strcpy(lista -> ponteiro_ultimo -> dados.curso, professor -> curso);
        strcpy(lista -> ponteiro_ultimo -> dados.nome,  professor -> nome);
        strcpy(lista -> ponteiro_ultimo -> dados.esp,   professor -> esp);

    }

    lista -> ponteiro_ultimo -> proximo = NULL;
    return 1;
}

int remove_professor(tipo_lista_professor *lista, char *nome, int senha){

    lista_professor_ponteiro ponteiro_auxiliar = lista -> ponteiro_primeiro -> proximo;
    lista_professor_ponteiro anterior_auxiliar = lista -> ponteiro_primeiro;

    while (ponteiro_auxiliar != NULL){

        if (ponteiro_auxiliar -> dados.senha == senha && strcmp(ponteiro_auxiliar -> dados.nome, nome) == 0){  
            break;   
        }

        ponteiro_auxiliar = ponteiro_auxiliar -> proximo;
        anterior_auxiliar = anterior_auxiliar -> proximo;
    }

    if (ponteiro_auxiliar == NULL) {
        return 0;
    }

    else {
        
        anterior_auxiliar -> proximo = ponteiro_auxiliar -> proximo;
        free(ponteiro_auxiliar);
        
        return 1;

    }
}

int imprime_professores(tipo_lista_professor *lista){

    lista_professor_ponteiro ponteiro_auxiliar = lista -> ponteiro_primeiro;

    printf("::::::::::::: PROFESSORES CADASTRADOS :::::::::::::\n");
    printf("\n");

    while (ponteiro_auxiliar != NULL){

        printf("Professor: %s | ID: %d | Curso: %s\n", ponteiro_auxiliar -> dados.nome, ponteiro_auxiliar -> dados.ID, ponteiro_auxiliar -> dados.curso);

        ponteiro_auxiliar = ponteiro_auxiliar -> proximo;
    }

    printf("\n");
    printf(":::::::::::::::::::::::::::::::::::::::::::::::::::\n");

    return 0;
}

int imprime_professor(tipo_lista_professor *lista, unsigned int ID){

    lista_professor_ponteiro ponteiro_auxiliar = lista -> ponteiro_primeiro;


    printf("::::::::::::::: DADOS DO PROFESSOR :::::::::::::::\n\n");
    
    while (ponteiro_auxiliar != NULL){

        if (ponteiro_auxiliar -> dados.ID == ID){

            printf("ID: %d\n\n", ponteiro_auxiliar -> dados.ID);

            printf("Nome: %s\n", ponteiro_auxiliar -> dados.nome);
            printf("Curso: %s\n", ponteiro_auxiliar -> dados.curso);
            printf("Especialização: %s\n", ponteiro_auxiliar -> dados.esp);
            printf("CPF: %s\n", ponteiro_auxiliar -> dados.CPF);
            printf("Curso: %s\n", ponteiro_auxiliar -> dados.curso);
            printf("Senha: %d\n", ponteiro_auxiliar -> dados.senha);
            printf("Idade: %d\n", ponteiro_auxiliar -> dados.idade);

        }

        ponteiro_auxiliar = ponteiro_auxiliar -> proximo;
    }

    printf("\n");
    printf(":::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\n");

}

int lista_professor_vazia(tipo_lista_professor *lista){

    if (lista -> ponteiro_ultimo == lista -> ponteiro_primeiro){
        return 1;
    }

    else {
        return 0;
    }

}


celula_professor* procura_professor_id(tipo_lista_professor *lista, unsigned int ID){

    // Esta função retorna o ponteiro para o professor cujo ID foi passado nos parâmetros

    lista_professor_ponteiro auxiliar = lista -> ponteiro_primeiro -> proximo;
    celula_professor *professor;

    // Caso não existam professores na lista
    if (auxiliar == NULL){
        
        professor = NULL;
        return professor;

    }

    professor = NULL; // por padrão recebe null, pois se for encontrado deixará de ser


    while (auxiliar != NULL){

        if (auxiliar -> dados.ID == ID) {

            professor = auxiliar;
            break;
        }

        auxiliar = auxiliar -> proximo;
    }
    return professor;

}