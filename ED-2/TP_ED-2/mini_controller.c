//
// Created by ratob on 09/11/2019.
//

#include "headers/mini_controller.h"

char *replaceWord(const char *s, const char *oldW, const char *newW) {
    char *result;
    int i, cnt = 0;
    int newWlen = strlen(newW);
    int oldWlen = strlen(oldW);

    // Contando o total de ocorrencias do char a ser substituido
    for (i = 0; s[i] != '\0'; i++) {
        if (strstr(&s[i], oldW) == &s[i]) {
            cnt++;

            // saltando de um indice ate o outro na string antiga.
            i += oldWlen - 1;
        }
    }

    // Criando uma nova string com tamanho necessario
    result = (char *)malloc(i + cnt * (newWlen - oldWlen) + 1);

    i = 0;
    while (*s) {
        // comparando a substring com o resultado
        if (strstr(s, oldW) == s) {
            strcpy(&result[i], newW);
            i += newWlen;
            s += oldWlen;
        }
        else
            result[i++] = *s++;
    }

    result[i] = '\0';
    return result;
}

void __registrar_log__(char __function_flow__[50],char log_name[50]){
    FILE *f3; // variavel para o arquivo de text que contera o log

    if( (f3 = fopen(log_name,"w+")) != NULL){

        fprintf(f3,"Execution: ");
        fprintf(f3,"%s",__function_flow__);

        fclose(f3);

    } else {
        printf("Erro ao criar o arquivo de log.");
        fclose(f3);

    }
}