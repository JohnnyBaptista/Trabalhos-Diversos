//
// Created by ratob on 23/05/2019.
//

#ifndef TEXT_RPG_ADVENTURE_DELAY_H
#define TEXT_RPG_ADVENTURE_DELAY_H

#include <time.h>
#include <conio.h>

int RNG_GAME(int n);

void delay(int number_of_seconds);
void delay_start(int number_of_seconds);
void pause();

int RNG_GAME(int n) {
    int limit;
    int r;
    srand(time(NULL));
    limit = RAND_MAX - (RAND_MAX % n);

    while((r = rand()) >= limit);

    return r % n;
}

void delay(int number_of_seconds){
    // Convertendo o tempo em milisegundos
    int milli_seconds = 100 * number_of_seconds;

    // Inicia o contador
    clock_t start_time = clock();

    // Loop ate o tempo pedido
    while (clock() < start_time + milli_seconds);
}

void pause(){
    printf("Aperte qualquer tecla para continuar. . .");
    getch();
    fflush(stdin);
    printf("\n");
}

void delay_start(int number_of_seconds) {
    // Convertendo o tempo em milisegundos
    int milli_seconds = 1000 * number_of_seconds;

    // Inicia o contador
    clock_t start_time = clock();

    // Loop ate o tempo pedido
    while (clock() < start_time + milli_seconds);
}

#endif //TEXT_RPG_ADVENTURE_DELAY_H
