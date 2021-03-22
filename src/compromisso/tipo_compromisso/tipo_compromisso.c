#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "tipo_compromisso.h"

int alterar_prioridade_base(tipo_compromisso *compromisso, int nova_prioridade){

    compromisso -> prioridade = nova_prioridade;

    return 1;
}

int imprime_prioridade_base(tipo_compromisso *compromisso){

    return compromisso -> prioridade;

}

int incializar_compromisso(tipo_compromisso *compromisso, int prioridade, int dia, int mes, int ano, int horas, int minutos, int duracao, char descricao[100]) {

    compromisso -> prioridade = prioridade;
    compromisso -> dia = dia;
    compromisso -> mes = mes;
    compromisso -> ano = ano;
    compromisso -> horas = horas;
    compromisso -> minutos = minutos;
    compromisso -> duracaocompromisso = duracao;

    srand((unsigned)time(NULL));//nao repetir os numeros - semente
    compromisso -> identificador = rand() % 100000;
    strcpy(compromisso -> descricao, descricao);

    return compromisso -> identificador; 

}

int imprime_compromisso_base(tipo_compromisso *compromisso){

    printf(":::::::::::::::::: COMPROMISSO ::::::::::::::::::::\n\n");
    printf("Identificador: %d\n", compromisso -> identificador);
    printf("Prioridade: %d\n", compromisso -> prioridade);
    printf("Data: %d/%d/%d", compromisso -> dia, compromisso -> mes, compromisso -> ano);
    printf("Horário: %d:%d\n", compromisso -> horas, compromisso -> minutos);
    printf("Duração: %d minutos\n", compromisso -> duracaocompromisso);
    printf("Descrição: %s\n\n", compromisso -> descricao);
    printf(":::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");

    return 1;

}

int verifica_conflito_base(tipo_compromisso *compromisso1, tipo_compromisso *compromisso2){

    int duracao_primeiro;
    int hora_proximo, minuto_proximo;
    int hora_primeiro, minuto_primeiro;

    int duracao_primeiro_horas;
    int duracao_primeiro_minutos;

    /*
    
    Os compromissos serão conflitantes em 2 casos

    1 - Datas e horarios iguais
    2 - Data igual e duração do que começa primeiro termina depois do horario do que começa por ultimo 
    
    */

    // Para de alguma forma conflitarem, o ano, mes e dia devem ser obrigatoriamente iguais
    if ((compromisso1 -> ano == compromisso2 -> ano) && (compromisso1 -> mes == compromisso2 -> mes) && (compromisso1 -> dia == compromisso2 -> dia)){

        // Primeiro caso
        if ((compromisso1 -> horas == compromisso2 -> horas) && (compromisso1 -> minutos == compromisso2 -> minutos)){

            return 1;

        }

        else {

            if (compromisso1 -> horas > compromisso2 -> horas){

                duracao_primeiro = compromisso2 -> duracaocompromisso;
                
                hora_primeiro = compromisso2 -> horas;
                minuto_primeiro = compromisso2 -> minutos;

                hora_proximo = compromisso1 -> horas;
                minuto_proximo = compromisso1 -> minutos;

            }

            else if (compromisso2 -> horas > compromisso1 -> horas){

                duracao_primeiro == compromisso1 -> duracaocompromisso;

                hora_primeiro = compromisso1 -> horas;
                minuto_primeiro = compromisso1 -> minutos;

                hora_proximo = compromisso2 -> horas;
                minuto_proximo = compromisso2 -> minutos;

            }

            else if ((compromisso1 -> horas == compromisso2 -> horas) && (compromisso1 -> minutos > compromisso2 -> minutos)){

                duracao_primeiro == compromisso2 -> duracaocompromisso;

                hora_primeiro = compromisso2 -> horas;
                minuto_primeiro = compromisso2 -> minutos;

                hora_proximo = compromisso1 -> horas;
                minuto_proximo = compromisso1 -> minutos;

            }

            else if ((compromisso1 -> horas == compromisso2 -> horas) && (compromisso1 -> minutos < compromisso2 -> minutos)){

                duracao_primeiro == compromisso1 -> duracaocompromisso;

                hora_primeiro = compromisso1 -> horas;
                minuto_primeiro = compromisso1 -> minutos;

                hora_proximo = compromisso2 -> horas;
                minuto_proximo = compromisso2 -> minutos;

            }

        }
   
    }
   
    // Caso a data for diferente
    else {

        return 0;

    }

    if (duracao_primeiro > 60){

        duracao_primeiro_horas = duracao_primeiro / 60;
        duracao_primeiro_minutos = duracao_primeiro % 60;

        if (duracao_primeiro_minutos + minuto_primeiro >= 60){

            duracao_primeiro_horas++;

            if (duracao_primeiro_horas + hora_primeiro >= hora_proximo){

                return 1;

            }

            else {

                return 0;
            
            }

        }

        else {

            if (duracao_primeiro_horas + hora_primeiro >= hora_proximo){

                return 1;

            }

            else {

                return 0;

            }

        }

    }

}
