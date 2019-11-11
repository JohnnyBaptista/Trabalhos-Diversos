//
// Created by ratob on 02/06/2019.
//

#ifndef TEXT_RPG_ADVENTURE_DUNGEON_TUTORIAL_H
#define TEXT_RPG_ADVENTURE_DUNGEON_TUTORIAL_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

#define max 2

typedef struct stack{
    int info;
    struct stack *next;
}p;

// Varaiveis globais
p *top;
int counter;

int stacks(int option, int count);
int push_stack(int value);
int stack_vazia();
void start_stack();
void pop_stack(int value);


#endif //TEXT_RPG_ADVENTURE_DUNGEON_TUTORIAL_H
