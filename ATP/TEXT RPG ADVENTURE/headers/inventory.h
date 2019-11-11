//
// Created by ratob on 26/05/2019.
//

#ifndef TEXT_RPG_ADVENTURE_INVENTORY_H
#define TEXT_RPG_ADVENTURE_INVENTORY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item{ // struct contendo o conteudo do node.
    char item_name[35];			// Nome do item.
    char item_description[100]; // Descricao.
    int  health;				// Vida que ganha ao usar o item.
    int  mana;					// Mana que ganha ao usar o item.
    int  attack;				// Ataque que ganha ao usar o item.
    int  rage;					// Raiva que ganha ao usar o item.
    int  combo;					// Combo que ganha ao usar o item.
    int  quantity;				// Quantidade do item.
    int  defense;				// Defesa que ganha ao usar o item.
    int  price;					// Preço de venda/compra o item.
    int  item_id;				// ID do item.

}item;

typedef struct Inventory{ // A lista duplamente encadeada
    item *current; // o node.
    struct Inventory *previous; // ponteiro para proximo node.
    struct Inventory *next; // ponteiro para o node anterior.
}inventory;

// Prototipos de funcoes
inventory* CreateInventory(); // Cria o ponteiro para a lista
inventory* DisplayItems(inventory *inv_pointer); // Mostra os items da lista
inventory* findItem(int item_id, inventory *inv_pointer); // Acha um item na lista
inventory* AddItem(int item_id, inventory *inv_pointer); // Adiciona um item na lista
void RemoveItem(inventory *inv_pointer, int item_id); // Remove um item da lista

#endif //TEXT_RPG_ADVENTURE_INVENTORY_H
