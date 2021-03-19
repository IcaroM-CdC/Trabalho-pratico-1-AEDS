#ifndef TADINFORMACOES_H_INCLUDED
#define TADINFORMACOES_H_INCLUDED


typedef struct{

    int prioridade;
    int identificador;
    int dia;
    int mes;
    int ano;
    int horas;
    int minutos;
    int duracaocompromisso;
    char descricao[100];

} tipo_compromisso;

int alterar_prioridade_base(tipo_compromisso *compromisso, int novaprioridade);

int incializar_compromisso(tipo_compromisso *compromisso, int prioridade, int dia, int mes, int ano, int horas, int minutos, int duracao, char descricao[100]); 
int imprime_prioridade_base(tipo_compromisso *compromisso); // tipo um get
int imprime_compromisso_base(tipo_compromisso *compromisso);
int verifica_conflito_base(tipo_compromisso *compromisso1, tipo_compromisso *compromisso2);



#endif // TADINFORMACOES_H_INCLUDED
