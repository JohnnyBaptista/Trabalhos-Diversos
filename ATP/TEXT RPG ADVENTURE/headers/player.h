//
// Created by ratob on 23/05/2019.
//

#ifndef TEXT_RPG_ADVENTURE_PLAYER_H
#define TEXT_RPG_ADVENTURE_PLAYER_H

#include <stdbool.h>
#include "inventory.h"

// As classeses sao enumeradas. WARRIOR = 0; RANGER = 1, MAGE = 2, WARLOCK = 3, PALADIN 4.
typedef enum classesEnum  {
    WARRIOR, //Guerreiro
    RANGER,  //Vigilante
    MAGE,    //Mago
    WARLOCK, //Bruxo
    PALADIN  //Paladino
} classes;

//Estrutura do jogador
typedef struct playerStructure {
    classes classe; //variavel do tipo enumeravel classe para o jogador escolher uma classe.

    char name[50];  // nome do jogador.
    int id_classe;  //id para sua classe.
    int level;      //variavel para o nivel do jogador.
    int health;     //pontos de vida, se ele chegar a zero, a variavel alive zera.
    int max_health; //vida maxima.
    int mana;       //status usado por bruxos e magos para efetuar suas magias.
    int max_mana;   //mana maxima.
    int gold;
    int alive;      //variavel pra verificar o status do jogador, se ela for 0, faremos free(Hero).

    int rage;       //status que o guerreiro usa para efetuar ataques mortais.
    int combo;      //status que o vigilante usa para efetuar ataques potentes.
    int agility;    //Determina quem ataca primeiro.
    int attack;     //Poder de ataque.
    int defense;    //Resistencia a um ataque.

    int xp_total;   //xp total de um nivel.
    int xp_now;     //xp atual do jogador.

} player;


// Prototipos de funcoes
void DisplayStats(player *target);                   //Monstra o status do player
int SetName(player *target, char name[50]);          //Seta o nome do jogador
player* NewPlayer(classes classe, char name[50]);    // Cria um jogador e escolhe a classe.


#endif //TEXT_RPG_ADVENTURE_PLAYER_H
