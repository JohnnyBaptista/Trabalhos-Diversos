//
// Created by ratob on 26/05/2019.
//

#include <stdbool.h>
#include "headers/inventory.h"

inventory* CreateInventory(){ // Criando o ponteiro para os node.
    inventory *inv_pointer = (inventory*)malloc(sizeof(inventory)); // ponteiro
    inv_pointer->current = (item*)malloc(sizeof(item)); //uma varaivel para o node item
    inv_pointer->previous = NULL; // aponta para NULL
    inv_pointer->next = NULL;// aponta para NULL
    return inv_pointer; // Retorna o ponteiro criado para o ponteiro principal
}

inventory* DisplayItems(inventory *inv_pointer){ // funcao que mostra o inventario
    inventory *auxiliar_inv_pointer = (inventory*)malloc(sizeof(inventory));
    auxiliar_inv_pointer = inv_pointer; /* auxiliar para imprimir os items e manter a
										 * lista intacta
										 */

    if(!auxiliar_inv_pointer){
        printf("   >* --INVENTARIO VAZIO-- *<\n");
    }

    else {
        system("cls");
        printf("\n  >***************************Display de itens***************************<\n\n");
        while(auxiliar_inv_pointer->next != NULL){ // enquanto o elemento da direita nao for nulo
            auxiliar_inv_pointer = auxiliar_inv_pointer->next; // passa para o próximo elemento
        }

        while(auxiliar_inv_pointer != NULL){ //enquanto nao houver objetos nulos, da direita
            switch(auxiliar_inv_pointer->current->item_id){ // Usando o item_id para dar print do item certo
                case 0:
                    printf("|==========================================================================|\n");
                    printf("|		Nome do item: %s\n", auxiliar_inv_pointer->current->item_name);
                    printf("|		Descricao: %s\n", auxiliar_inv_pointer->current->item_description);
                    printf("|		Vida a recuperar: %d\n", auxiliar_inv_pointer->current->health);
                    printf("|		Quantidade: %d\n", auxiliar_inv_pointer->current->quantity);
                    printf("|		Item ID: %d\n", auxiliar_inv_pointer->current->item_id);
                    printf("|		Preco de venda: %dgp\n", auxiliar_inv_pointer->current->price);
                    break;
                case 1:
                    printf("|==========================================================================|\n");
                    printf("|		Nome do item: %s\n", auxiliar_inv_pointer->current->item_name);
                    printf("|		Descricao: %s\n", auxiliar_inv_pointer->current->item_description);
                    printf("|		Mana a recuperar: %d\n", auxiliar_inv_pointer->current->mana);
                    printf("|		Quantidade: %d\n", auxiliar_inv_pointer->current->quantity);
                    printf("|		Item ID: %d\n", auxiliar_inv_pointer->current->item_id);
                    printf("|		Preco de venda: %dgp\n", auxiliar_inv_pointer->current->price);
                    break;
                case 2:
                    printf("|==========================================================================|\n");
                    printf("|		Nome do item: %s\n", auxiliar_inv_pointer->current->item_name);
                    printf("|		Descricao: %s\n", auxiliar_inv_pointer->current->item_description);
                    printf("|		Vida a recuperar: %d\n", auxiliar_inv_pointer->current->health);
                    printf("|		Mana a recuperar: %d\n", auxiliar_inv_pointer->current->mana);
                    printf("|		Quantidade: %d\n", auxiliar_inv_pointer->current->quantity);
                    printf("|		Item ID: %d\n", auxiliar_inv_pointer->current->item_id);
                    printf("|		Preco de venda: %dgp\n", auxiliar_inv_pointer->current->price);
                    break;
                case 3:
                    printf("|==========================================================================|\n");
                    printf("|		Nome do item: %s\n", auxiliar_inv_pointer->current->item_name);
                    printf("|		Descricao: %s\n", auxiliar_inv_pointer->current->item_description);
                    printf("|		Raiva a ganhar: %d\n", auxiliar_inv_pointer->current->rage);
                    printf("|		Quantidade: %d\n", auxiliar_inv_pointer->current->quantity);
                    printf("|		Item ID: %d\n", auxiliar_inv_pointer->current->item_id);
                    printf("|		Preco de venda: %dgp\n", auxiliar_inv_pointer->current->price);
                    break;
                case 4:
                    printf("|==========================================================================|\n");
                    printf("|		Nome do item: %s\n", auxiliar_inv_pointer->current->item_name);
                    printf("|		Descricao: %s\n", auxiliar_inv_pointer->current->item_description);
                    printf("|		Combo a ganhar: %d\n", auxiliar_inv_pointer->current->combo);
                    printf("|		Quantidade: %d\n", auxiliar_inv_pointer->current->quantity);
                    printf("|		Item ID: %d\n", auxiliar_inv_pointer->current->item_id);
                    printf("|		Preco de venda: %dgp\n", auxiliar_inv_pointer->current->price);
                    break;
                case 5:
                    printf("|==========================================================================|\n");
                    printf("|		Nome do item: %s\n", auxiliar_inv_pointer->current->item_name);
                    printf("|		Descricao: %s\n", auxiliar_inv_pointer->current->item_description);
                    printf("|		Vida a recuperar: %d\n", auxiliar_inv_pointer->current->health);
                    printf("|		Quantidade: %d\n", auxiliar_inv_pointer->current->quantity);
                    printf("|		Item ID: %d\n", auxiliar_inv_pointer->current->item_id);
                    printf("|		Preco de venda: %dgp\n", auxiliar_inv_pointer->current->price);
                    break;
                case 6:
                    printf("|==========================================================================|\n");
                    printf("|		Nome do item: %s\n", auxiliar_inv_pointer->current->item_name);
                    printf("|		Descricao: %s\n", auxiliar_inv_pointer->current->item_description);
                    printf("|		Mana a recuperar: %d\n", auxiliar_inv_pointer->current->mana);
                    printf("|		Quantidade: %d\n", auxiliar_inv_pointer->current->quantity);
                    printf("|		Item ID: %d\n", auxiliar_inv_pointer->current->item_id);
                    printf("|		Preco de venda: %dgp\n", auxiliar_inv_pointer->current->price);
                    break;
                case 7:
                    printf("|==========================================================================|\n");
                    printf("|		Nome do item: %s\n", auxiliar_inv_pointer->current->item_name);
                    printf("|		Descricao: %s\n", auxiliar_inv_pointer->current->item_description);
                    printf("|		Ataque a ganhar: %d\n", auxiliar_inv_pointer->current->attack);
                    printf("|		Quantidade: %d\n", auxiliar_inv_pointer->current->quantity);
                    printf("|		Item ID: %d\n", auxiliar_inv_pointer->current->item_id);
                    printf("|		Preco de venda: %dgp\n", auxiliar_inv_pointer->current->price);
                    break;
                case 8:
                    printf("|==========================================================================|\n");
                    printf("|		Nome do item: %s\n", auxiliar_inv_pointer->current->item_name);
                    printf("|		Descricao: %s\n", auxiliar_inv_pointer->current->item_description);
                    printf("|		Vida a recuperar: %d\n", auxiliar_inv_pointer->current->health);
                    printf("|		Mana a recuperar: %d\n", auxiliar_inv_pointer->current->mana);
                    printf("|		Quantidade: %d\n", auxiliar_inv_pointer->current->quantity);
                    printf("|		Item ID: %d\n", auxiliar_inv_pointer->current->item_id);
                    printf("|		Preco de venda: %dgp\n", auxiliar_inv_pointer->current->price);
                    break;
                case 9:
                    printf("|==========================================================================|\n");
                    printf("|		Nome do item: %s\n", auxiliar_inv_pointer->current->item_name);
                    printf("|		Descricao: %s\n", auxiliar_inv_pointer->current->item_description);
                    printf("|		Defesa a ganhar: %d\n", auxiliar_inv_pointer->current->defense);
                    printf("|		Quantidade: %d\n", auxiliar_inv_pointer->current->quantity);
                    printf("|		Item ID: %d\n", auxiliar_inv_pointer->current->item_id);
                    printf("|		Preco de venda: %dgp\n", auxiliar_inv_pointer->current->price);
                    break;
            }
            auxiliar_inv_pointer = auxiliar_inv_pointer->previous; //o ponteiro volta imprimindo
        }
        printf("|==========================================================================|\n");

    }
}

inventory* findItem(int item_id, inventory *inv_pointer) {
    if (inv_pointer == NULL) {
        return(NULL);
    }

    // Evita nodes nao utilizados.
    while (inv_pointer->current != NULL) {
        if (inv_pointer->current->item_id== item_id) {
            return(inv_pointer);
        }

        if (inv_pointer->next != NULL) {
            inv_pointer = inv_pointer->next;
        }

        else {
            return(NULL);
        }
    }
    return(NULL);
}

inventory* AddItem(int item_id, inventory *inv_pointer){
    item *item_node = (item*)malloc(sizeof(item)); // alocamento de memoria pra noode de item, uma auxiliar nesse caso.
    inventory *aux_inv,*aux_inv_nav; // auxiliares para percorrer a lista.
    inventory *searchResult; // pointer pra lista pra usar ela para verificar se o item existe.
    aux_inv = (inventory*)malloc(sizeof(inventory)); //
    aux_inv->current = (item*)malloc(sizeof(item)); // alocamento de memoria pro node item.

    aux_inv_nav = inv_pointer; //usando a aux para manter a lista intacta.

    searchResult = findItem(item_id, inv_pointer);
    if (searchResult != NULL) {
        searchResult->current->quantity += 1;
    }

    else{
        switch(item_id){// case para todos os tipos de items
            case 0:
                strcpy(item_node->item_name,"Pocao de Vida");
                strcpy(item_node->item_description,"Recupera 20 pontos de vida.");
                item_node->health = 20;
                item_node->quantity = item_node->quantity = 1;
                item_node->item_id = item_id;
                item_node->price = 10;
                break;
            case 1:
                strcpy(item_node->item_name,"Pocao de mana");
                strcpy(item_node->item_description,"Recupera 30 pontos de mana.");
                item_node->mana = 20;
                item_node->quantity = item_node->quantity = 1;
                item_node->item_id = item_id;
                item_node->price = 10;
                break;
            case 2:
                strcpy(item_node->item_name,"Pocao do rejuvenescimento");
                strcpy(item_node->item_description,"Recupero 20 pontos de vida e mana.");
                item_node->health = 20;
                item_node->mana = 20;
                item_node->quantity = item_node->quantity = 1;
                item_node->item_id = item_id;
                item_node->price = 20;
                break;
            case 3:
                strcpy(item_node->item_name,"Pocao do Berserk");
                strcpy(item_node->item_description,"Aumenta a raiva do guerreiro.");
                item_node->rage = 20;
                item_node->quantity = item_node->quantity = 1;
                item_node->item_id = item_id;
                item_node->price = 15;
                break;
            case 4:
                strcpy(item_node->item_name,"Pocao de Capacidade");
                strcpy(item_node->item_description,"Aumenta os pontos de combo temporariamente.");
                item_node->combo = 15;
                item_node->quantity = item_node->quantity = 1;
                item_node->item_id = item_id;
                item_node->price = 15;
                break;
            case 5:
                strcpy(item_node->item_name,"Pocao Grande de Vida.");
                strcpy(item_node->item_description,"Recupera 150 pontos de vida.");
                item_node->health = 150;
                item_node->quantity = item_node->quantity = 1;
                item_node->item_id = item_id;
                item_node->price = 120;
                break;
            case 6:
                strcpy(item_node->item_name,"Pocao Grande de Mana.");
                strcpy(item_node->item_description,"Recupera 120 pontos de mana.");
                item_node->mana = 120;
                item_node->quantity = item_node->quantity = 1;
                item_node->item_id = item_id;
                item_node->price = 160;
                break;
            case 7:
                strcpy(item_node->item_name,"Pocao de forca");
                strcpy(item_node->item_description,"Recupera 120 pontos de mana.");
                item_node->attack = 12;
                item_node->quantity = item_node->quantity = 1;
                item_node->item_id = item_id;
                item_node->price = 300;
                break;
            case 8:
                strcpy(item_node->item_name,"Pocao Grande do rejuvenescimento");
                strcpy(item_node->item_description,"Recupera 120 pontos de mana.");
                item_node->health = 130;
                item_node->mana = 90;
                item_node->quantity = item_node->quantity = 1;
                item_node->item_id = item_id;
                item_node->price = 200;
                break;
            case 9:
                strcpy(item_node->item_name,"Papiro da defesa");
                strcpy(item_node->item_description,"Aumenta a defesa do Heroi.");
                item_node->defense = 15;
                item_node->quantity = item_node->quantity = 1;
                item_node->item_id = item_id;
                item_node->price = 500;
                break;
            default:
                printf("   >* --ERRO-- *<\n");
                break;
        }

        /*
        printf("Display de itens\n");
        printf("Nome do item: %s\n", item_node->item_name);
        printf("Descricao: %s\n", item_node->item_description);
        printf("Vida a recuperar: %d\n", item_node->health);
        printf("Mana a recuperar: %d\n", item_node->mana);
        printf("Quantidade: %d\n", item_node->quantity);
        printf("Item ID: %d\n", item_node->item_id);
        */

        if(aux_inv == NULL){
            printf("ERRO NA MEMORIA");

        }

        else{
            aux_inv->current = item_node;
            aux_inv->next = NULL;
            aux_inv->previous = NULL;

            if(inv_pointer == NULL){
                inv_pointer = aux_inv;
            }

            else{
                while(aux_inv_nav->next != NULL){
                    aux_inv_nav = aux_inv_nav->next;
                }

                aux_inv_nav->next = aux_inv;
                aux_inv->previous = aux_inv_nav;
            }

        }
    }

}

void RemoveItem(inventory *inv_pointer, int item_id) {
    inventory *searchResult = (inventory*)malloc(sizeof(inventory));
    inventory *previous = (inventory*)malloc(sizeof(inventory));
    inventory *next = (inventory*)malloc(sizeof(inventory));

    // Verifica se o item ja existe.
    searchResult = findItem(item_id, inv_pointer);

    // Se existir, reduz a quantidade por 1.
    if (searchResult != NULL) {
        searchResult->current->quantity -= 1;

        // Se chegar a 0 a reducao, remove o item por completo.
        if (searchResult->current->quantity <= 0) {
            previous = searchResult->previous;
            next = searchResult->next;

            // Libera o item e depois o node que ele pertence.
            free(searchResult->current);
            free(searchResult);

            // Troca a lista de items.
            if (previous != NULL) {
                searchResult = previous;
                searchResult->next = next;
            }
            if (next != NULL) {
                searchResult = next;
                searchResult->previous = previous;
            }
        }
    }
}

