#include "../../utils/utils.h"

typedef struct contato tipo_contato;

struct contato {

    char *nome;
    char *sobrenome;
    char *comentario;
    char *email;
    char *telefone;

};

tipo_contato* cria_contato(char *nome, char *sobrenome, char *comentario, char *email, char *telefone);