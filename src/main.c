// Inclusão das bibliotecas basicas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h> // Biblioteca que contem a função para limpar o buffer(linux)

// Inclusão dos TAD's
#include "agenda/lista_agenda/lista_agenda.h"
#include "professor/lista_professor/lista_professor.h"


int menu_opcao_entrada(void){

    int opcao = 0;

    //system("clear");

    printf(":::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
    printf("            1 -> Entrada por teclado                 \n");
    printf("            2 -> Entrada por arquivo               \n\n");
    printf("            9 -> Sair                              \n\n");
    printf(":::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");

    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    if (opcao == 1){
        return 1;
    }

    if (opcao == 2){
        return 2;
    }

    if (opcao == 9){
        return 9;
    }

    else {

        system("clear");
        printf("ERRO: COMANDO INVÁLIDO\n");
        system("sleep 2");
        system("clear");

        return menu_opcao_entrada();

    }
}

int menu_opcao_professor(int flag){

    system("clear");

    if (flag == 1){
        printf("A SENHA PADRÃO DO PROFESSOR INSERIDO PELA ENTRADA POR ARQUIVO É 1\n");
    }

    int opcao = 0;

    printf(":::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
    printf("        1 -> Listar professores cadastrados          \n");
    printf("        2 -> Cadastrar novo professor                \n");
    printf("        3 -> Login                                 \n\n");
    printf("        9 -> Sair                                  \n\n");
    printf(":::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");

    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    printf("\n");

    if (opcao == 1){       
        return 1;
    }

    if (opcao == 2){
        return 2;
    }

    if (opcao == 3){
        return 3;
    }

    if (opcao == 9){
        return 9;
    }

    else {

        system("clear");
        printf("ERRO: COMANDO INVÁLIDO\n");
        system("sleep 2");
        system("clear");

        return menu_opcao_professor(flag);
    }
}   

int menu_opcao_agenda(void){

    system("clear");

    int opcao = 0;

    printf(":::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
    printf("   1  -> Inserir compromisso                         \n");
    printf("   2  -> Imprimir compromisso                        \n");
    printf("   3  -> Imprimir compromissos                       \n");
    printf("   4  -> Imprimir compromissos por data              \n");
    printf("   5  -> Imprimir numero de compromissos             \n");
    printf("   6  -> Imprimir numero de compromissos por data  \n\n");
    printf("   7  -> Remover compromisso                         \n");
    printf("   8  -> Alterar prioridade                          \n");
    printf("   9  -> Imprimir prioridade                       \n\n");
    printf("   10 -> Imprimir seus dados                       \n\n");
    printf("   11 -> Contatos                                  \n\n");
    printf("   99 -> SAIR                                      \n\n");
    printf(":::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");

    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    printf("\n");

    if (opcao == 1){  
        return 1;
    }

    if (opcao == 2){
        return 2;
    }

    if (opcao == 3){
        return 3;
    }

    if (opcao == 4){
        return 4;
    }

    if (opcao == 5){
        return 5;
    }

    if (opcao == 6){
        return 6;
    }

    if (opcao == 7){
        return 7;
    }
    
    if (opcao == 8){
        return 8;
    }

    if (opcao == 9){
        return 9;
    }

    if (opcao == 10){
        return 10;
    }

    if (opcao == 11){
        return 11;
    }

    if (opcao == 99){
        return 99;
    }

    else {

        system("clear");
        printf("ERRO: COMANDO INVÁLIDO\n");
        system("sleep 2");
        system("clear");

        return menu_opcao_agenda();
    }
}

int menu_opcao_contato(void){

    system("clear");

    int opcao = 0;

    printf(":::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
    printf("        1 -> Inserir contato                         \n");
    printf("        2 -> Imprimir contatos                       \n");
    printf("        3 -> Remover contato                       \n\n");
    printf("        9 -> Sair                                  \n\n");
    printf(":::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");

    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    printf("\n");

    if (opcao == 1){       
        return 1;
    }

    if (opcao == 2){
        return 2;
    }

    if (opcao == 3){
        return 3;
    }

    if (opcao == 9){
        return 9;
    }

    else {

        system("clear");
        printf("ERRO: COMANDO INVÁLIDO\n");
        system("sleep 2");
        system("clear");

        return menu_opcao_contato();
    }
}


int main(void){

    tipo_lista_agenda LISTA_AGENDA;
    tipo_lista_professor LISTA_PROFESSOR;
 
    cria_lista_agenda(&LISTA_AGENDA);
    cria_lista_professor(&LISTA_PROFESSOR);

    int opcao_entrada   = 0;
    int opcao_professor = 0;
    int opcao_agenda    = 0;
    int opcao_contato   = 0;

    int flag_entrada_por_arquivo = 0;

    int ID = 0;
    int ID_contato = 0;

    while (opcao_entrada != 9){    
        
        /*
            Condicional para verificar se a entrada por arquivo já foi ultilizada
            caso já estiver, pula a parte de selecionar a entrada
        */

        if (opcao_entrada != 1 && opcao_entrada != 9){

            opcao_entrada = menu_opcao_entrada();

        }
    
        if (opcao_entrada == 1){

            while (1){

                opcao_professor = menu_opcao_professor(flag_entrada_por_arquivo);

                if (opcao_professor == 1){
                    
                    if (lista_professor_vazia(&LISTA_PROFESSOR) == 1) {

                        printf("NENHUM PROFESSOR CADASTRADO\n");
                        system("sleep 2");

                    }

                    else {

                        imprime_professores(&LISTA_PROFESSOR);

                        printf("\n");
                        printf("Tecle para sair\n");
                        getchar();
                        getchar();

                    }

                }

                if (opcao_professor == 2){

                    char nome[100];
                    char curso[30];
                    char esp[25];       // especialização
                    char CPF[25];

                    unsigned int idade;
                    unsigned int senha;
                    unsigned int ano;

                    printf(":::::::::: CADASTRANDO PROFESSOR/AGENDA :::::::::::\n\n");
                    
                    __fpurge(stdin);
                    printf("Insira o nome: ");
                    fgets(nome, 100, stdin);
                    __fpurge(stdin);

                    __fpurge(stdin);
                    printf("Insira o CPF (Não ultilizar separadores entre os numeros): ");
                    fgets(CPF, 25, stdin);

                    __fpurge(stdin);
                    printf("Insira o curso: ");
                    fgets(curso, 30, stdin);

                    __fpurge(stdin);
                    printf("Insira a especialização: ");
                    fgets(esp, 25, stdin);

                    __fpurge(stdin);
                    printf("Insira o ano atual: ");
                    scanf("%u", &ano);

                    __fpurge(stdin);
                    printf("Insira a senha: ");
                    scanf("%u", &senha);
                    __fpurge(stdin);

                    ID = ID + 1;

                    remove_quebra_linha(nome);
                    remove_quebra_linha(CPF);
                    remove_quebra_linha(curso);
                    remove_quebra_linha(esp);

                    insere_agenda(&LISTA_AGENDA, ID, ano, nome);
                    insere_professor(&LISTA_PROFESSOR, nome, curso, esp, CPF, idade, senha, ID);
                    
                    printf("\n");
                    printf("CADASTRO CONCLUIDO COM SUCESSO\n");
                    printf("\n");
                    system("sleep 2");
                }       

                if (opcao_professor == 3){

                    int ID_professor_agenda; // ID do professor e da agenda
                    int senha;

                    celula_professor *PROFESSOR;
                    celula_agenda *AGENDA;

                    printf("Insira o ID do professor: ");
                    scanf("%d", &ID_professor_agenda);

                    printf("Insira a senha: ");
                    scanf("%d", &senha);


                    PROFESSOR = procura_professor_id(&LISTA_PROFESSOR, ID_professor_agenda);
                    AGENDA = procura_agenda_id(&LISTA_AGENDA, ID_professor_agenda);
                    
                    /*
                        Caso for passado um ID inválido a função retornará que PROFESSOR e AGENDA são nulos
                    */

                    if (PROFESSOR == NULL || AGENDA == NULL){

                        opcao_professor = 0;

                        printf("\n");
                        printf("ERRO: PROFESSOR/AGENDA NÃO CADASTRADO\n\n");
                        system("sleep 2");

                    }


                    else if (PROFESSOR -> dados.senha == senha){

                        tipo_compromisso COMPROMISSO;

                        printf("LOGIN EFETUADO COM SUCESSO !!!\n");

                        while (1){

                            opcao_agenda = menu_opcao_agenda();

                            if (opcao_agenda == 1){

                                int prioridade;
                                int dia, mes, ano;
                                int hora, minuto;
                                int duracao;
                                int ID_compromisso;

                                char descricao[100];

                                printf("::::::::::::: INSERINDO COMPROMISSO ::::::::::::::\n\n");

                                __fpurge(stdin);
                                printf("Insira a prioridade (1 a 5): ");
                                scanf("%d", &prioridade);

                                __fpurge(stdin);
                                printf("Insira o dia: ");
                                scanf("%d", &dia);

                                __fpurge(stdin);
                                printf("Insira o mes: ");
                                scanf("%d", &mes);

                                __fpurge(stdin);
                                printf("Insira o ano: ");
                                scanf("%d", &ano);

                                __fpurge(stdin);
                                printf("Insira o minuto: ");
                                scanf("%d", &minuto);

                                __fpurge(stdin);
                                printf("Insira a hora: ");
                                scanf("%d", &hora);

                                __fpurge(stdin);
                                printf("Insira a duração em minutos: ");
                                scanf("%d", &duracao);

                                __fpurge(stdin);
                                printf("Insira uma breve descrição: ");
                                fgets(descricao, 100, stdin);

                                
                                incializar_compromisso(&COMPROMISSO, prioridade, dia, mes, ano, hora, minuto, duracao, descricao);                
                                ID_compromisso = insere_compromisso(&LISTA_AGENDA, &COMPROMISSO, ID_professor_agenda);

                                printf("ID do compromisso cadastrado: %d\n", ID_compromisso);
                                printf("\n");
                                printf("Tecle para sair\n");
                                getchar();

                            }

                            if (opcao_agenda == 2){

                                int ID = 0;

                                printf("Insira o ID do compromisso: ");
                                scanf("%d", (&ID));
                                printf("\n");

                                imprime_compromisso(&LISTA_AGENDA, ID_professor_agenda, ID);

                                printf("Tecle para sair\n");
                                getchar();
                                getchar();

                            }

                            if (opcao_agenda == 3){

                                imprime_agenda(&LISTA_AGENDA, ID_professor_agenda);
                                
                                printf("Tecle para sair\n");
                                getchar();
                                getchar();

                            }

                            if (opcao_agenda == 4){

                                int dia, mes, ano;

                                __fpurge(stdin);
                                printf("Insira o dia: ");
                                scanf("%d", &dia);

                                __fpurge(stdin);
                                printf("Insira o mes: ");
                                scanf("%d", &mes);

                                __fpurge(stdin);
                                printf("Insira o ano: ");
                                scanf("%d", &ano);

                                imprime_agenda_por_data(&LISTA_AGENDA, ID_professor_agenda, dia, mes, ano);

                                printf("Tecle para sair\n");
                                getchar();
                                getchar();

                            }

                            if (opcao_agenda == 5){

                                imprime_numero_compromissos(&LISTA_AGENDA, ID_professor_agenda);

                                printf("\n");
                                printf("Tecle para sair\n");
                                getchar();
                                getchar();

                            }

                            if (opcao_agenda == 6){

                                int dia, mes, ano;

                                __fpurge(stdin);
                                printf("Insira o dia: ");
                                scanf("%d", &dia);

                                __fpurge(stdin);
                                printf("Insira o mes: ");
                                scanf("%d", &mes);

                                __fpurge(stdin);
                                printf("Insira o ano: ");
                                scanf("%d", &ano);

                                imprime_numero_compromissos_por_data(&LISTA_AGENDA, ID_professor_agenda, dia, mes, ano);

                                printf("Tecle para sair\n");
                                getchar();
                                getchar();

                            }

                            if (opcao_agenda == 7){

                                int ID = 0;

                                printf("Insira o ID do compromisso a ser deletado: ");
                                scanf("%d", (&ID));

                                remove_compromisso(&LISTA_AGENDA, ID, ID_professor_agenda);

                            }

                            if (opcao_agenda == 8){

                                int ID = 0;
                                int nova_prioridade;

                                printf("Insira o ID do compromisso: ");
                                scanf("%d", (&ID));

                                printf("Insira a nova prioridade: ");
                                scanf("%d", &nova_prioridade);

                                altera_prioridade(&LISTA_AGENDA, nova_prioridade, ID, ID_professor_agenda);

                            }

                            if (opcao_agenda == 9){

                                int ID = 0;
                                int nova_prioridade;

                                printf("Insira o ID do compromisso: ");
                                scanf("%d", (&ID));

                                imprime_prioridade(&LISTA_AGENDA, ID, ID_professor_agenda);

                            }

                            if (opcao_agenda == 10){

                                imprime_professor(&LISTA_PROFESSOR, ID_professor_agenda);
                                printf("Tecle para sair\n");
                                getchar();
                                getchar();

                            }

                            if (opcao_agenda == 11){

                                opcao_contato = menu_opcao_contato();

                                if (opcao_contato == 1){

                                    char nome[20];
                                    char sobrenome[30];
                                    char email[100];
                                    char telefone[50];
                                    char comentario[150];

                                    printf(":::::::::::::: INSERINDO CONTATO :::::::::::::\n\n");

                                    __fpurge(stdin);
                                    printf("Insira o primeiro nome: ");
                                    fgets(nome, 20, stdin);

                                    __fpurge(stdin);
                                    printf("Insira o sobrenome: ");
                                    fgets(sobrenome, 30, stdin);

                                    __fpurge(stdin);
                                    printf("Insira o e-mail: ");
                                    fgets(email, 100, stdin);

                                    __fpurge(stdin);
                                    printf("Insira o telefone: ");
                                    fgets(telefone, 50, stdin);

                                    __fpurge(stdin);
                                    printf("Insira algum comentário: ");
                                    fgets(comentario, 150, stdin);

                                    remove_quebra_linha(nome);
                                    remove_quebra_linha(sobrenome);
                                    remove_quebra_linha(email);
                                    remove_quebra_linha(telefone);
                                    remove_quebra_linha(comentario);

                                    ID_contato = ID_contato + 1;

                                    insere_contato(&LISTA_AGENDA, nome, sobrenome, comentario, email, telefone, ID_contato);

                                    printf("\n");
                                    printf("CONTATO INSERIDO COM SUCESSO !!!\n");
                                    
                                    system("sleep 2");

                                }

                                if (opcao_contato == 2){

                                    imprime_contatos(&LISTA_AGENDA, ID_professor_agenda);

                                    printf("Tecle para sair\n");
                                    getchar();
                                    getchar();

                                }

                                if (opcao_contato == 3){

                                    char nome[20];
                                    char sobrenome[30];

                                    __fpurge(stdin);
                                    printf("Insira o primeiro nome: ");
                                    fgets(nome, 20, stdin);

                                    __fpurge(stdin);
                                    printf("Insira o sobrenome: ");
                                    fgets(sobrenome, 30, stdin);

                                    remove_quebra_linha(nome);
                                    remove_quebra_linha(sobrenome);

                                    remove_contato(&LISTA_AGENDA,nome, sobrenome, ID_professor_agenda);

                                }

                            }

                            if (opcao_agenda == 99){

                                return 1;

                            }

                        }
                    }

                    else if (PROFESSOR -> dados.senha != senha){

                        opcao_professor = 0;
                        printf("\n");
                        printf("SENHA INCORRETA !!!\n");
                        system("sleep 2");

                    }

                } 
            
                if (opcao_professor == 9){

                    return 1;

                }
            }
        }

        if (opcao_entrada == 2){

            FILE *arquivo;


            int numero_professores;
            

            arquivo = fopen("entrada.txt", "r");

            fscanf(arquivo, "%d", &numero_professores);

            /* Percorrerá o arquivo até o final */            
            
            for (int i = 0; i < numero_professores; i++){

                int numero_compromissos;
                int ID_professor;
                int ano;

                char nome[50];


                fscanf(arquivo, "%d", &numero_compromissos);
                fscanf(arquivo, "%d", &ID_professor);

                fscanf(arquivo, "%s", nome);
                fscanf(arquivo, "%d", &ano);


                insere_agenda(&LISTA_AGENDA, ID_professor, ano, nome);
                insere_professor(&LISTA_PROFESSOR, nome, "N/A", "N/A", "N/A", 1, 1, ID_professor);

                for (int j = 0; j < numero_compromissos; j++){

                    int prioridade;
                    int dia, mes, ano;
                    int hora, minuto;
                    int duracao;
                    char descricao[100];

                    tipo_compromisso COMPROMISSO;


                    fscanf(arquivo, "%d", &prioridade);
                    fscanf(arquivo, "%d", &dia);
                    fscanf(arquivo, "%d", &mes);
                    fscanf(arquivo, "%d", &ano);
                    fscanf(arquivo, "%d", &hora);
                    fscanf(arquivo, "%d", &minuto);
                    fscanf(arquivo, "%d", &duracao);
                    fscanf(arquivo, "%s", descricao);


                    incializar_compromisso(&COMPROMISSO, prioridade, dia, mes, ano, hora, minuto, duracao, descricao);                
                    insere_compromisso(&LISTA_AGENDA, &COMPROMISSO, ID_professor);

                }    

            }

            flag_entrada_por_arquivo = 1;
            opcao_entrada = 1;
        }

        if (opcao_entrada == 9){

            return 1;

        }

    }

    return 1; // Sucesso

}
