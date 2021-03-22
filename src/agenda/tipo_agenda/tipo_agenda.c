#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "tipo_agenda.h"


tipo_agenda *cria_agenda(unsigned int ID, unsigned int ano, char *nome){
    
    tipo_agenda *agenda = (tipo_agenda*) malloc(sizeof(tipo_agenda));
    
    // Alocando o espaço necessario para o campo nome
    agenda -> nome = preenche_string(sizeof(nome));

    strcpy(agenda -> nome, nome);
    agenda -> ID = ID;
    agenda -> ano = ano;

    return agenda;
}
