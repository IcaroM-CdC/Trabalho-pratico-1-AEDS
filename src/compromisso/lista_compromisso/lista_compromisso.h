#ifndef TADCOMPROMISSO_H_INCLUDED
#define TADCOMPROMISSO_H_INCLUDED

#include "../tipo_compromisso/tipo_compromisso.h"

typedef struct celula_compromisso *lista_compromisso_ponteiro; // redefinindo nome de um tipo de ponteiro para lista_compromisso_ponteiro

typedef struct celula_compromisso{

    tipo_compromisso compromisso;
    lista_compromisso_ponteiro proximo; // apontador para a proxima celula_compromisso

}Tcelulainformacoes;

typedef struct{

    lista_compromisso_ponteiro primeiro;
    lista_compromisso_ponteiro ultimo;
    int contador;

}tipo_lista_compromisso;

int cria_lista_compromisso( tipo_lista_compromisso *lista_de_compromisso);
int retirar_ultimo_compromisso(tipo_lista_compromisso *lista_de_compromisso);

int remove_compromisso_base(tipo_lista_compromisso *lista_de_compromisso, int ID);
int lista_compromisso_vazia(tipo_lista_compromisso *lista_de_compromisso);
int insere_compromisso_base(tipo_lista_compromisso *lista_de_compromisso, tipo_compromisso *compromisso);

#endif // TADCOMPROMISSO_H_INCLUDED
