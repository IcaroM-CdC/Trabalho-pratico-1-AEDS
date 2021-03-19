#include "../tipo_professor/tipo_professor.h"
#include "../../utils/utils.h"

typedef struct lista tipo_lista_professor;
typedef struct celula_professor *lista_professor_ponteiro;
typedef struct celula_professor celula_professor;

struct celula_professor {

    tipo_professor dados;
    lista_professor_ponteiro proximo;

};

struct lista {
    lista_professor_ponteiro ponteiro_primeiro, ponteiro_ultimo;
};

int cria_lista_professor(tipo_lista_professor *lista);
int insere_professor(tipo_lista_professor *lista, char *nome, char *curso, char *esp, char *CPF, unsigned int idade, unsigned int senha, unsigned int ID);
int remove_professor(tipo_lista_professor *lista, char *nome, int senha);
int imprime_professores(tipo_lista_professor *lista);
int imprime_professor(tipo_lista_professor *lista, unsigned int ID);
int lista_professor_vazia(tipo_lista_professor *lista);

celula_professor* procura_professor_id(tipo_lista_professor *lista, unsigned int ID);

