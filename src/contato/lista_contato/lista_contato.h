#include "../tipo_contato/tipo_contato.h"

typedef struct lista_contato tipo_lista_contato;
typedef struct celula_contato *lista_ponteiro_contato;
typedef struct celula_contato celula_contato;

struct celula_contato {
    tipo_contato dados;
    lista_ponteiro_contato proximo;
};

struct lista_contato {
    lista_ponteiro_contato ponteiro_primeiro, ponteiro_ultimo;
};


int cria_lista_contato(tipo_lista_contato *lista_contato);
int insere_contato_base(tipo_lista_contato *lista_contato, char *nome, char *sobrenome, char *comentario, char *email, char *telefone);
int remove_contato_base(tipo_lista_contato *lista_contato, char *nome, char *sobrenome);
int imprime_contatos_base(tipo_lista_contato *lista_contato);

int lista_contato_vazia(tipo_lista_contato *lista_contato);