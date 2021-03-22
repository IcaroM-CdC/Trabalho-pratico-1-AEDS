#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *preenche_string(int tamanho){

    char *string = (char*) calloc(tamanho + 1, sizeof(char));

    string[tamanho] = '\0';

    return string;
}

int remove_quebra_linha(char *string){

    int len = strlen(string);

    if (string[len - 1] == '\n'){

        string[len - 1] = '\0';

    }

    return 1;

}