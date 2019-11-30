#include <stdio.h>
#include <stdlib.h>

#include "headers/grafos.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
    printf("          ** Trabalho de Estrutura de Dados II **          \n");
    printf("Desenvolvido por:\n");
    printf(" Juan Cardoso da Silva.\n");
    printf(" Pedro Takahashi\n");
    printf(" Version 1.1\n\n");
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("read -p 'Press Enter to continue...' var");
#endif

#if defined(_WIN32) || defined(_WIN64)
    system("pause");
#endif

    __Menu__();
}
