#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "lista_agenda.h"



int cria_lista_agenda(tipo_lista_agenda *lista_agenda){

    lista_agenda -> ponteiro_primeiro = (lista_agenda_ponteiro) malloc(sizeof(celula_agenda));
    lista_agenda -> ponteiro_ultimo = lista_agenda -> ponteiro_primeiro;
    lista_agenda -> ponteiro_primeiro -> proximo = NULL;

}

/*
    Funções de inserção
*/

int insere_agenda(tipo_lista_agenda *lista_agenda, unsigned int ID, unsigned int ano, char *nome){

    tipo_agenda *agenda = cria_agenda(ID, ano, nome);

    lista_agenda -> ponteiro_ultimo -> proximo = (lista_agenda_ponteiro) malloc(sizeof(celula_agenda));
    lista_agenda -> ponteiro_ultimo = lista_agenda -> ponteiro_ultimo -> proximo;
    
    if (lista_agenda -> ponteiro_ultimo != NULL){

        lista_agenda -> ponteiro_ultimo -> dados.nome = preenche_string(sizeof(agenda -> nome));

        lista_agenda -> ponteiro_ultimo -> dados.ano = agenda -> ano;
        lista_agenda -> ponteiro_ultimo -> dados.ID = agenda -> ID;

        strcpy(lista_agenda -> ponteiro_ultimo -> dados.nome, agenda -> nome);

    }
    
    lista_agenda -> ponteiro_ultimo -> proximo = NULL;
    return 1;
}

int insere_compromisso(tipo_lista_agenda *lista_agenda, tipo_compromisso *compromisso, unsigned int ID){

    // Procura a agenda que queremos inserir o compromisso e retorna um ponteiro que aponta para ela
    celula_agenda *agenda = procura_agenda_id(lista_agenda, ID);

    /*
        Caso seja a primeira vez que uma agenda receba um compromisso, a lista de compromissos 
        ainda não existe, então o if será responsavel por criar a lista de compromissos dentro
        da a genda.
    */
   
    if (lista_compromisso_vazia(&agenda -> dados.lista_compromisso)){

        cria_lista_compromisso(&agenda -> dados.lista_compromisso);

    }
    
    if (verifica_conflito(lista_agenda, compromisso, ID) == 1){
        
        printf("\n");
        printf("COMPROMISSO CONFLITANTE, IMPOSSIVEL INSERIR\n");
        system("sleep 2");

        return 0;

    }

    else {

        // Como o proprio nome sugere, essa função é a base para inserir o compromisso
        insere_compromisso_base(&agenda -> dados.lista_compromisso, compromisso);

        printf("\n");
        printf("COMPROMISSO CRIADO COM SUCESSO\n");
        printf("\n");
    
        return compromisso -> identificador;

    }
}

int insere_contato(tipo_lista_agenda *lista_agenda, char *nome, char *sobrenome, char *funcao, char *email, char *telefone, unsigned int ID){

    // Procura a agenda que queremos inserir o contato e retorna um ponteiro que aponta para ela
    celula_agenda *agenda = procura_agenda_id(lista_agenda, ID);

    /*
        Caso seja a primeira vez que uma agenda recebe um contato, a lista de contatos 
        ainda não existe, então o if será responsavel por criar a lista de contatos dentro
        da agenda.
    */

    if (lista_contato_vazia(&agenda -> dados.lista_contato)){

        cria_lista_contato(&agenda -> dados.lista_contato);

    }

    insere_contato_base(&agenda -> dados.lista_contato, nome, sobrenome, funcao, email, telefone);
    return 1;

}


/*
    Funções de remoção
*/

int remove_compromisso(tipo_lista_agenda *lista_agenda, int ID_compromisso, int ID){

    celula_agenda *agenda = procura_agenda_id(lista_agenda, ID);
    int retorno = 0;

    if (agenda == NULL){

        printf("\n");
        printf("ERRO: AGENDA INEXISTENTE\n");
        printf("\n");

        return 0;    
    }

    if (lista_compromisso_vazia(&agenda -> dados.lista_compromisso)){

        printf("\n");
        printf("ERRO: NENHUM COMPROMISSO CADASTRADO\n");
        printf("\n");
        
        return 0;

    }

    else {
        
        retorno = remove_compromisso_base(&agenda -> dados.lista_compromisso, ID_compromisso);

        if (retorno == 0){

            printf("\n");
            printf("ERRO: COMPROMISSO INEXISTENTE\n");
            system("sleep 2");
            
            return 0;

        }

        if (retorno == 1){

            printf("\n");
            printf("COMPROMISSO DELETADO COM SUCESSO!!!\n");
            system("sleep 2");

            return 1;

        }
    }
}

int remove_contato(tipo_lista_agenda *lista_agenda, char *nome, char *sobrenome, unsigned int ID){

    celula_agenda *agenda = procura_agenda_id(lista_agenda, ID);
    int retorno = 0;

    if (agenda == NULL){

        printf("\n");
        printf("ERRO: AGENDA INEXISTENTE\n");
        printf("\n");

        return 0;    
    }

    if (lista_contato_vazia(&agenda -> dados.lista_contato) == 1){

        printf("\n");
        printf("ERRO: NENHUM CONTATO CADASTRADO\n");
        printf("\n");

        return 0;

    }

    else {
        
        remove_contato_base(&agenda -> dados.lista_contato, nome, sobrenome);

        if (retorno == 0){

            printf("\n");
            printf("ERRO: CONTATO INEXISTENTE\n");
            system("sleep 2");
            
            return 0;

        }

        if (retorno == 1){

            printf("\n");
            printf("CONTATO DELETADO COM SUCESSO!!!\n");
            system("sleep 2");

            return 1;

        }

    }
}


/*
    Funções de visualização
*/


int imprime_agenda(tipo_lista_agenda *lista_agenda, unsigned int ID){

    // Procura a agenda que queremos imprimir os compromissos e retorna um ponteiro que aponta para ela
    celula_agenda *agenda = procura_agenda_id(lista_agenda, ID);

    // Caso a lista de compromisso estiver vazia, a função retorna um erro e encerra
    if (lista_compromisso_vazia(&agenda -> dados.lista_compromisso)){
        
        printf("LISTA DE COMPROMISSO VAZIA !!!\n");
        return 0;
        
    }

    else {

        lista_compromisso_ponteiro auxiliar = agenda -> dados.lista_compromisso.primeiro -> proximo;

        printf("::::::::::::::::::: COMPROMISSOS ::::::::::::::::::\n\n");
        
        while (auxiliar != NULL) {

            printf("Identificador: %d\n", auxiliar -> compromisso.identificador);
            printf("Prioridade: %d\n", auxiliar -> compromisso.prioridade);
            printf("Data: %d/%d/%d\n", auxiliar -> compromisso.dia, auxiliar -> compromisso.mes, auxiliar->compromisso.ano);
            printf("Horário: %d:%d\n", auxiliar -> compromisso.horas, auxiliar -> compromisso.minutos);
            printf("Duração: %d minutos\n", auxiliar -> compromisso.duracaocompromisso);
            printf("Descrição: %s\n", auxiliar -> compromisso.descricao);
            
            printf("\n");

            auxiliar = auxiliar -> proximo;

        }
        printf(":::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
    }
}

int imprime_agenda_por_data(tipo_lista_agenda *lista_agenda, unsigned int ID, unsigned int dia, unsigned int mes, unsigned int ano){

    celula_agenda *agenda = procura_agenda_id(lista_agenda, ID);

    // Caso a lista de compromisso estiver vazia, a função retorna um erro e encerra
    if (lista_compromisso_vazia(&agenda -> dados.lista_compromisso)){
        
        printf("LISTA DE COMPROMISSO VAZIA !!!\n");
        return 0;
        
    }

    else {

        lista_compromisso_ponteiro auxiliar = agenda -> dados.lista_compromisso.primeiro -> proximo;


        printf("::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");


        while (auxiliar != NULL) {

            if (auxiliar -> compromisso.dia > dia && auxiliar -> compromisso.mes > mes && auxiliar -> compromisso.ano > ano){

                printf("Identificador: %d\n", auxiliar -> compromisso.identificador);
                printf("Prioridade: %d\n", auxiliar -> compromisso.prioridade);
                printf("Data: %d/%d/%d\n", auxiliar -> compromisso.dia, auxiliar -> compromisso.mes, auxiliar->compromisso.ano);
                printf("Horário: %d:%d\n", auxiliar -> compromisso.horas, auxiliar -> compromisso.minutos);
                printf("Descrição: %s\n", auxiliar -> compromisso.descricao);
                
                printf("\n");
            }
            
            auxiliar = auxiliar -> proximo;

        }
        printf("::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");

    }

}

int imprime_numero_compromissos(tipo_lista_agenda *lista_agenda, unsigned int ID){

    // Procura a agenda que queremos imprimir os compromissos e retorna um ponteiro que aponta para ela
    celula_agenda *agenda = procura_agenda_id(lista_agenda, ID);

    // Caso a lista de compromisso estiver vazia, a função retorna um erro e encerra
    if (lista_compromisso_vazia(&agenda -> dados.lista_compromisso)){
        
        printf("LISTA DE COMPROMISSO VAZIA !!!\n");
        return 0;
        
    }

    else {

        lista_compromisso_ponteiro auxiliar = agenda -> dados.lista_compromisso.primeiro -> proximo;

        int numero_compromissos = 0;
        
        while (auxiliar != NULL) {

            numero_compromissos = numero_compromissos + 1;
            auxiliar = auxiliar -> proximo;

        }

        printf("A agenda possui %d compromissos\n", numero_compromissos);
    }
}

int imprime_numero_compromissos_por_data(tipo_lista_agenda *lista_agenda, unsigned int ID, unsigned int dia, unsigned int mes, unsigned int ano){

    celula_agenda *agenda = procura_agenda_id(lista_agenda, ID);

    // Caso a lista de compromisso estiver vazia, a função retorna um erro e encerra
    if (lista_compromisso_vazia(&agenda -> dados.lista_compromisso)){
        
        printf("LISTA DE COMPROMISSO VAZIA !!!\n");
        return 0;
        
    }

    else {

        int contador = 0;      
        
        lista_compromisso_ponteiro auxiliar = agenda -> dados.lista_compromisso.primeiro -> proximo;

        printf("::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
        printf("Nome: %s\n", agenda -> dados.nome);

        while (auxiliar != NULL) {

            if (auxiliar -> compromisso.dia > dia && auxiliar -> compromisso.mes > mes && auxiliar -> compromisso.ano > ano){
                
                contador = contador + 1;
            
            }
            
            auxiliar = auxiliar -> proximo;

        }
        printf("Encontradors %d compromissos a partir de %d/%d/%d\n\n", contador, dia, mes, ano);
        printf("::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");


        return 1;
    }
}

int imprime_compromisso(tipo_lista_agenda *lista_agenda, unsigned int ID, unsigned int ID_compromisso){

    celula_agenda *agenda = procura_agenda_id(lista_agenda, ID);   


    if (agenda == NULL){

        printf("\n");
        printf("ERRO: AGENDA INEXISTENTE\n");
        printf("\n");

        return 0;    
    }

    else {

        lista_compromisso_ponteiro auxiliar = agenda -> dados.lista_compromisso.primeiro -> proximo;

        while (auxiliar != NULL){
            
            if (auxiliar -> compromisso.identificador == ID_compromisso){

                break;

            }

            auxiliar = auxiliar -> proximo;

        }

        imprime_compromisso_base(&auxiliar -> compromisso);

    }

}

int imprime_prioridade(tipo_lista_agenda *lista_agenda, int ID_compromisso, int ID){

    celula_agenda *agenda = procura_agenda_id(lista_agenda, ID);

    if (agenda == NULL){

        printf("\n");
        printf("ERRO: AGENDA INEXISTENTE\n");
        printf("\n");

        return 0;    
    }

    else {

        lista_compromisso_ponteiro auxiliar = agenda -> dados.lista_compromisso.primeiro -> proximo;

        while (auxiliar != NULL){
            
            if (auxiliar -> compromisso.identificador == ID_compromisso){

                break;

            }

            auxiliar = auxiliar -> proximo;

        }

        int prioridade = imprime_prioridade_base(&auxiliar -> compromisso);
        printf("Compromisso id %d, prioridade: %d", ID_compromisso, prioridade);
        system("sleep 2");

        return 1;
    }
}

int imprime_contatos(tipo_lista_agenda *lista_agenda, unsigned int ID){

    celula_agenda *agenda = procura_agenda_id(lista_agenda, ID);

    if (agenda == NULL){

        printf("\n");
        printf("ERRO: AGENDA INEXISTENTE\n");
        printf("\n");

        return 0;    
    }

    else {

        imprime_contatos_base(&agenda ->dados.lista_contato);
        
        return 1;
    }
}


/*
    Outras funções
*/


int lista_agenda_vazia(tipo_lista_agenda *lista_agenda){


    if (lista_agenda -> ponteiro_ultimo == lista_agenda -> ponteiro_primeiro){
        return 1;
    }

    else {
        return 0;
    }

}

int altera_prioridade(tipo_lista_agenda *lista_agenda, int nova_prioridade, int ID_compromisso, int ID){

    celula_agenda *agenda = procura_agenda_id(lista_agenda, ID);

    if (agenda == NULL){

        printf("\n");
        printf("ERRO: AGENDA INEXISTENTE\n");
        printf("\n");

        return 0;    
    }

    else {

        lista_compromisso_ponteiro auxiliar = agenda -> dados.lista_compromisso.primeiro -> proximo;

        while (auxiliar != NULL){
            
            if (auxiliar -> compromisso.identificador == ID_compromisso){

                break;

            }

            auxiliar = auxiliar -> proximo;

        }

        alterar_prioridade_base(&auxiliar -> compromisso, nova_prioridade);

        printf("\n");
        printf("PRIORIDADE ALTERADA COM SUCESSO!!!\n");
        system("sleep 2");

    }
}

int verifica_conflito(tipo_lista_agenda *lista_agenda, tipo_compromisso *compromisso, int ID){

    celula_agenda *agenda = procura_agenda_id(lista_agenda, ID);

    int flag = 0;

    if (agenda == NULL){

        printf("\n");
        printf("ERRO: AGENDA INEXISTENTE\n");
        printf("\n");

        return 0;    
    }

    lista_compromisso_ponteiro auxiliar = agenda -> dados.lista_compromisso.primeiro -> proximo;


    while (auxiliar != NULL){

        if (verifica_conflito_base(&auxiliar -> compromisso, compromisso) == 1){
            
            flag = 1;
            
            return 1;
            break;
        }

        auxiliar = auxiliar -> proximo;

    }


    if (flag == 0){
        
        return 0;
    }

}

celula_agenda* procura_agenda_id(tipo_lista_agenda *lista_agenda, unsigned int ID){
    
    // Esta função retorna o ponteiro para a agenda cujo ID foi passado nos parâmetros
    lista_agenda_ponteiro auxiliar = lista_agenda -> ponteiro_primeiro -> proximo;
    celula_agenda *agenda;

    // Caso não existam agendas na lista
    if (auxiliar == NULL){
        
        agenda = NULL;
        return agenda;

    }

    /*
        Caso existam agendas na lista mas foi passado um ID inválido, atribuir NULL para agenda
        previne que dê segmentation fault
    */

    agenda = NULL;

    while (auxiliar != NULL){

        if (auxiliar -> dados.ID == ID) {

            agenda = auxiliar;
            break;
        }

        auxiliar = auxiliar -> proximo;
    }
    return agenda;
}