#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "headers/game.h"


int main() {
    setlocale(LC_ALL, "Portuguese");
    start(); // inicia o jogo

    system("PAUSE");
    return 0;
}
