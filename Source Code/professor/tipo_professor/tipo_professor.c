#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tipo_professor.h"
#include "../../utils/utils.h"

tipo_professor* cria_professor(char *nome, char *curso, char *esp, char *CPF, unsigned int idade, unsigned int senha, unsigned int ID) {

    tipo_professor *professor = (tipo_professor*) malloc(sizeof(tipo_professor));

    // Alocando o espaço necessario para os campos
    professor -> nome = preenche_string(sizeof(nome));
    professor -> curso = preenche_string(sizeof(curso));
    professor -> esp = preenche_string(sizeof(esp));
    professor -> CPF = preenche_string(sizeof(CPF));

    // Preenche os campos relacionados a strings
    strcpy(professor -> nome, nome);
    strcpy(professor -> curso, curso);
    strcpy(professor -> esp, esp);
    strcpy(professor -> CPF, CPF);

    professor -> idade = idade;
    professor -> senha = senha;
    professor -> ID = ID;

    return professor;
}