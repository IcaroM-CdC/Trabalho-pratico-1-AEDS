#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tipo_contato.h"


tipo_contato* cria_contato(char *nome, char *sobrenome, char *comentario, char *email, char *telefone) {
    
    tipo_contato *contato = (tipo_contato*) malloc(sizeof (tipo_contato));

    // Alocando o espaço necessario para os campos


    // Preenche os campos relacionados a strings
    contato -> nome = nome;
    contato -> sobrenome = sobrenome;
    contato -> comentario = comentario;
    contato -> email = email;
    contato -> telefone = telefone;

    return contato;
}