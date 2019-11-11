//
// Created by ratob on 02/06/2019.
//

#include "headers/dungeon_tutorial.h"

void start_stack() {
    top = NULL;
    counter = 0;
}

int stack_vazia() {
    if (top == NULL)return 1;

    else return 0;
}

int stack_tamanho() {
    return counter;
}

int push_stack(int value) {
    p *novo_node = (p *) malloc(sizeof(p));

    if (novo_node == NULL) return 0;

    else {
        novo_node->info = value;
        novo_node->next = top;

        top = novo_node;
        counter++;

        return 1;
    }
}

void pop_stack(int value) {
    p *temp;

    if (stack_vazia())
        printf("\nERRO\n");

    else {
        value = top->info;
        temp = top;
        top = top->next;

        free(temp);
        counter--;

    }

}

int stack_get(int value) {
    if (stack_vazia()) return 0;

    else {
        value = top->info;
        top = top->next;
        return value;
    }
}

int destroy_stack() {
    int aux;
    p *temp;

    if (stack_vazia()) return 0;

    else {
        while (top != NULL) {
            temp = top;
            temp->next = NULL;
            top = top->next;

            free(temp);
        }
        counter = 0;
        return 1;
    }
}


int stacks(int option, int count) {
    setlocale(LC_ALL, "Portuguese");

    start_stack();

    push_stack(1);
    push_stack(0);

    int i = 0;

    if (option == 1) {
        for (i = 0; i < 2; i++) {
            if (stack_get(count) == count) {
                return count;
            }
        }
    }

    else if(option == 2) {
        for (i = 2; i > 0; i--) {
            if (stack_get(count) == count) {
                return count;
            }
        }
    }
}
