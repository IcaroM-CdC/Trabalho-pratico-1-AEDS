#include "../../utils/utils.h"

#include "../../compromisso/lista_compromisso/lista_compromisso.h"
#include "../../contato/lista_contato/lista_contato.h"


typedef struct agenda tipo_agenda;

struct agenda {

    unsigned int ID;
    unsigned int ano;
    char *nome;

    tipo_lista_compromisso lista_compromisso;
    tipo_lista_contato     lista_contato;
};

tipo_agenda *cria_agenda(unsigned int ID, unsigned int ano, char *nome);

