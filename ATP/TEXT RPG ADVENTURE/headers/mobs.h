//
// Created by ratob on 24/05/2019.
//

#ifndef TEXT_RPG_ADVENTURE_MOBS_H
#define TEXT_RPG_ADVENTURE_MOBS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum mobEnum{
    MINION,
    SCOURGE,
    PLAGUE,
    DARK,
    LORD,
    BOSS,
    LASTBOSS
}type;

typedef struct mobsStrucutre{
    type type_mob;
    char name[50]; //nome do monstro
    int id_type;   //tipo do mosntro
    int level;     //nivel do monstro
    int health;    //mana do monstro
    int mana;
    int rage;
    int combo;
    int agility;    //Determina quem ataca primeiro
    int attack;     // Poder de ataque.
    int defense;    // Resistencia a um ataque.
    int xp_drop;    // quantidade de xp que deixa a ser derrotado
    int gold_drop;  //quantidade de ouro que deixa ao ser derrotado
}mobs;


mobs* NewMob(type type_mob, char name[50]); // Cria novo monstro
int SetMobName(mobs *target, char name[50]); // Seta o nome do monstro
void DisplayMobStats(mobs *target); // Monstra os monstros

int RNG(int n);

#endif //TEXT_RPG_ADVENTURE_MOBS_H
