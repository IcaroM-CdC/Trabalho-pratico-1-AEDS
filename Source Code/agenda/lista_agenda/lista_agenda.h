#include "../tipo_agenda/tipo_agenda.h"


typedef struct lista_agenda tipo_lista_agenda;
typedef struct celula_agenda *lista_agenda_ponteiro;
typedef struct celula_agenda celula_agenda;

struct celula_agenda {

    tipo_agenda dados;
    lista_agenda_ponteiro proximo;

};

struct lista_agenda {
    lista_agenda_ponteiro ponteiro_primeiro, ponteiro_ultimo;
};

/*
    A função insere_compromisso, manipula a lista de agendas, pois precisamos saber em qual agenda
    queremos inserir o compromisso, portanto precisamos fazer uma pesquisa na lista de agendas
*/

int cria_lista_agenda(tipo_lista_agenda *lista_agenda);

/*
    Funções de inserção
*/

int insere_agenda(tipo_lista_agenda *lista_agenda, unsigned int ID, unsigned int ano, char *nome);
int insere_compromisso(tipo_lista_agenda *lista_agenda, tipo_compromisso *compromisso, unsigned int ID);
int insere_contato(tipo_lista_agenda *lista_agenda, char *nome, char *sobrenome, char *funcao, char *email, char *telefone, unsigned int ID);

/*
    Funções de remoção
*/

int remove_compromisso(tipo_lista_agenda *lista_agenda, int ID_compromisso, int ID);
int remove_contato(tipo_lista_agenda *lista_agenda, char *nome, char *sobrenome, unsigned int ID);

/*
    Funções de visualização
*/

int imprime_agenda(tipo_lista_agenda *lista_agenda, unsigned int ID);
int imprime_agenda_por_data(tipo_lista_agenda *lista_agenda, unsigned int ID, unsigned int dia, unsigned int mes, unsigned int ano);
int imprime_numero_compromissos(tipo_lista_agenda *lista_agenda, unsigned int ID);
int imprime_numero_compromissos_por_data(tipo_lista_agenda *lista_agenda, unsigned int ID, unsigned int dia, unsigned int mes, unsigned int ano);
int imprime_compromisso(tipo_lista_agenda *lista_agenda, unsigned int ID, unsigned int ID_compromisso);
int imprime_prioridade(tipo_lista_agenda *lista_agenda, int ID_compromisso, int ID);
int imprime_contatos(tipo_lista_agenda *lista_agenda, unsigned int ID);

/*
    Outras funções
*/

int lista_agenda_vazia(tipo_lista_agenda *lista_agenda);
int altera_prioridade(tipo_lista_agenda *lista_agenda, int nova_prioridade, int ID_compromisso, int ID);
int verifica_conflito(tipo_lista_agenda *lista_agenda, tipo_compromisso *compromisso, int ID);

celula_agenda* procura_agenda_id(tipo_lista_agenda *lista_agenda, unsigned int ID);