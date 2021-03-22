#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "lista_compromisso.h"

int cria_lista_compromisso(tipo_lista_compromisso *lista_de_compromisso){
    
    lista_de_compromisso -> primeiro = (lista_compromisso_ponteiro) malloc(sizeof(Tcelulainformacoes)); // celula_compromisso cabe�a
    lista_de_compromisso -> ultimo = lista_de_compromisso->primeiro; // apontado pra mesma celula_compromisso
    lista_de_compromisso -> primeiro -> proximo = NULL;
    lista_de_compromisso -> contador = 0;// eletmento 0 - celula_compromisso cabe�a
    
    return 1;

}

int lista_compromisso_vazia(tipo_lista_compromisso *lista_de_compromisso){

    if (lista_de_compromisso -> primeiro == lista_de_compromisso -> ultimo ){
        return 1;
    }

    else {
        return 0;
    }

}

int insere_compromisso_base(tipo_lista_compromisso *lista_de_compromisso, tipo_compromisso *compromisso){
    
    lista_compromisso_ponteiro auxiliar = lista_de_compromisso -> primeiro -> proximo;
    lista_compromisso_ponteiro anterior = lista_de_compromisso -> primeiro;


    while (auxiliar != NULL && auxiliar -> compromisso.prioridade >= compromisso -> prioridade){

        auxiliar = auxiliar -> proximo;
        anterior = anterior -> proximo;
        
    }

    if (auxiliar != NULL) {

        lista_compromisso_ponteiro novo = (lista_compromisso_ponteiro) malloc(sizeof(Tcelulainformacoes));

        novo -> proximo = auxiliar;
        anterior -> proximo = novo;

        novo -> compromisso = (*compromisso);  // Derreferenciando, passando o valor e não o endereço

        return 1; 

    }
    
    lista_de_compromisso -> ultimo -> proximo = (lista_compromisso_ponteiro) malloc(sizeof(Tcelulainformacoes));
    lista_de_compromisso -> ultimo = lista_de_compromisso -> ultimo -> proximo;
    lista_de_compromisso -> ultimo -> compromisso = (*compromisso); // Derreferenciando, passando o valor e não o endereço
    lista_de_compromisso -> ultimo -> proximo = NULL;

    return 1;

}

int remove_compromisso_base(tipo_lista_compromisso *lista_de_compromisso, int ID) {

    lista_compromisso_ponteiro ponteiro_auxiliar = lista_de_compromisso ->primeiro -> proximo;
    lista_compromisso_ponteiro anterior_auxiliar = lista_de_compromisso -> primeiro;

    while (ponteiro_auxiliar != NULL){

        if (ponteiro_auxiliar -> compromisso.identificador == ID){

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

