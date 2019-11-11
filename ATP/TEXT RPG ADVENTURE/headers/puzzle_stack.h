//
// Created by ratob on 20/06/2019.
//

#ifndef TEXT_RPG_ADVENTURE_PUZZLE_STACK_H
#define TEXT_RPG_ADVENTURE_PUZZLE_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct stack_main{
    int info; 				 // Os inteiros onde a resposta do puzzle fica
    struct stack_main *next; // Ponteiro para o proximo
}p_main;

// Varaiveis globais
p_main *top_main;
int counter_main;

int puzzle_stacks();
void start_stack_main();
int stack_vazia_main();
int push_stack_main(int value);
int stack_get_main(int value);
int destroy_stack_main();

#endif //TEXT_RPG_ADVENTURE_PUZZLE_STACK_H
