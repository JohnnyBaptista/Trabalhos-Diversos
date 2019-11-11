//
// Created by ratob on 24/05/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "headers/mobs.h"

int RNG(int n) {
    int limit;
    int r;
    srand(time(NULL));
    limit = RAND_MAX - (RAND_MAX % n);

    while((r = rand()) >= limit);

    return r % n;
}

mobs* NewMob(type type_mob, char name[50]) {
    // Alocando memoria para o ponteiro Monstro.
    mobs *tempMob = malloc(sizeof(mobs));
    SetMobName(tempMob, name);

    static int MobsCreated = 0; // Variavel para acompanhar o progresso dos monstros criados.

    ++MobsCreated;

    int tipo_minion = RNG(4);
    int tipo_scourge = RNG(4);
    int tipo_plague = RNG(2);
    int tipo_dark = RNG(4);
    int tipo_lord = RNG(3);
    int tipo_boss = RNG(3);
    // Associa os status conforme o tipo de monstro.
    switch(type_mob) {
        case MINION:
            switch(tipo_minion){
                case 0:
                    tempMob->health = 15;
                    tempMob->rage = 0;
                    tempMob->agility = 2;
                    tempMob->attack = 6;
                    tempMob->defense = 2;
                    tempMob->level = 1;
                    tempMob->xp_drop = 5;
                    tempMob->id_type = 1;
                    tempMob->gold_drop = 5;
                    tempMob->type_mob = MINION;
                    break;
                case 1:
                    tempMob->health = 20;
                    tempMob->rage = 0;
                    tempMob->agility = 3;
                    tempMob->attack = 7;
                    tempMob->defense = 1;
                    tempMob->level = 1;
                    tempMob->xp_drop = 10;
                    tempMob->id_type = 1;
                    tempMob->gold_drop = 5;
                    tempMob->type_mob = MINION;
                    break;
                case 2:
                    tempMob->health = 21;
                    tempMob->rage = 0;
                    tempMob->agility = 2;
                    tempMob->attack = 8;
                    tempMob->defense = 5;
                    tempMob->level = 1;
                    tempMob->xp_drop = 5;
                    tempMob->id_type = 1;
                    tempMob->gold_drop = 5;
                    tempMob->type_mob = MINION;
                    break;
                case 3:
                    tempMob->health = 29;
                    tempMob->rage = 0;
                    tempMob->agility = 5;
                    tempMob->attack = 9;
                    tempMob->defense = 2;
                    tempMob->level = 1;
                    tempMob->xp_drop = 10;
                    tempMob->id_type = 1;
                    tempMob->gold_drop = 10;
                    tempMob->type_mob = MINION;
                    break;
                default:
                    printf("      Error\n");
            }
            break;
        case SCOURGE:
            switch(tipo_scourge){
                case 0:
                    tempMob->health = 95;
                    tempMob->combo = 15;
                    tempMob->agility = 6;
                    tempMob->attack = 16;
                    tempMob->defense = 20;
                    tempMob->level = 1;
                    tempMob->xp_drop = 15;
                    tempMob->id_type= 2;
                    tempMob->gold_drop = 12;
                    tempMob->type_mob = SCOURGE;
                    break;
                case 1:
                    tempMob->health = 81;
                    tempMob->combo = 15;
                    tempMob->agility = 24;
                    tempMob->attack = 20;
                    tempMob->defense = 15;
                    tempMob->level = 2;
                    tempMob->xp_drop = 15;
                    tempMob->id_type= 2;
                    tempMob->gold_drop = 12;
                    tempMob->type_mob = SCOURGE;
                    break;
                case 2:
                    tempMob->health = 61;
                    tempMob->combo = 15;
                    tempMob->agility = 12;
                    tempMob->attack = 27;
                    tempMob->defense = 11;
                    tempMob->level = 2;
                    tempMob->xp_drop = 20;
                    tempMob->id_type = 2;
                    tempMob->gold_drop = 11;
                    tempMob->type_mob = SCOURGE;
                    break;
                case 3:
                    tempMob->health = 37;
                    tempMob->combo = 15;
                    tempMob->agility = 6;
                    tempMob->attack = 13;
                    tempMob->defense = 9;
                    tempMob->level = 3;
                    tempMob->xp_drop = 25;
                    tempMob->id_type = 2;
                    tempMob->gold_drop = 14;
                    tempMob->type_mob = SCOURGE;
                    break;
                default:
                    printf("      Error\n");

            }
            break;
        case PLAGUE:
            switch (tipo_plague){
                case 0:
                    tempMob->health = 190;
                    tempMob->mana = 65;
                    tempMob->agility = 13;
                    tempMob->attack = 31;
                    tempMob->defense = 9;
                    tempMob->level = 4;
                    tempMob->xp_drop = 100;
                    tempMob->id_type = 3;
                    tempMob->gold_drop = 20;
                    tempMob->type_mob = PLAGUE;
                    break;
                case 1:
                    tempMob->health = 205;
                    tempMob->mana = 80;
                    tempMob->agility = 24;
                    tempMob->attack = 40;
                    tempMob->defense = 15;
                    tempMob->level = 4;
                    tempMob->xp_drop = 90;
                    tempMob->id_type = 3;
                    tempMob->gold_drop = 20;
                    tempMob->type_mob = PLAGUE;
                    break;
                default:
                    tempMob->health = 60;
                    tempMob->mana = 40;
                    tempMob->agility = 2;
                    tempMob->attack = 4;
                    tempMob->defense = 6;
                    tempMob->level = 4;
                    tempMob->xp_drop = 30;
                    tempMob->id_type = 3;
                    tempMob->type_mob = PLAGUE;
            }
            break;
        case DARK:
            switch(tipo_dark){
                case 0:
                    tempMob->health = 345;
                    tempMob->mana = 0;
                    tempMob->agility = 12;
                    tempMob->attack = 50;
                    tempMob->defense = 20;
                    tempMob->level = 5;
                    tempMob->xp_drop = 200;
                    tempMob->id_type = 4;
                    tempMob->gold_drop = 30;
                    tempMob->type_mob = DARK;
                    break;
                case 1:
                    tempMob->health = 420;
                    tempMob->mana = 200;
                    tempMob->agility = 20;
                    tempMob->attack = 60;
                    tempMob->defense = 19;
                    tempMob->level = 5;
                    tempMob->xp_drop = 220;
                    tempMob->id_type = 4;
                    tempMob->gold_drop = 30;
                    tempMob->type_mob = DARK;
                    break;
                case 2:
                    tempMob->health = 520;
                    tempMob->mana = 100;
                    tempMob->agility = 12;
                    tempMob->attack = 64;
                    tempMob->defense = 0;
                    tempMob->level = 6;
                    tempMob->xp_drop = 190;
                    tempMob->id_type = 4;
                    tempMob->gold_drop = 30;
                    tempMob->type_mob = DARK;
                    break;
                case 3:
                    tempMob->health = 390;
                    tempMob->mana = 300;
                    tempMob->agility = 30;
                    tempMob->attack = 80;
                    tempMob->defense = 20;
                    tempMob->level = 7;
                    tempMob->xp_drop = 300;
                    tempMob->id_type = 4;
                    tempMob->gold_drop = 30;
                    tempMob->type_mob = DARK;
                    break;
                default:
                    tempMob->health = 30;
                    tempMob->mana = 45;
                    tempMob->agility = 3;
                    tempMob->attack = 4;
                    tempMob->defense = 2;
                    tempMob->level = 0;
                    tempMob->xp_drop = 150;
                    tempMob->id_type = 4;
                    tempMob->type_mob = DARK;
            }
            break;
        case LORD:
            switch(tipo_lord){
                case 0:
                    tempMob->health = 360;
                    tempMob->mana = 0;
                    tempMob->agility = 24;
                    tempMob->attack = 90;
                    tempMob->defense = 31;
                    tempMob->level = 6;
                    tempMob->xp_drop = 640;
                    tempMob->id_type = 5;
                    tempMob->gold_drop = 50;
                    tempMob->type_mob = LORD;
                    break;
                case 1:
                    tempMob->health = 365;
                    tempMob->mana = 45;
                    tempMob->agility = 35;
                    tempMob->attack = 84;
                    tempMob->defense = 23;
                    tempMob->level = 6;
                    tempMob->xp_drop = 700;
                    tempMob->id_type = 5;
                    tempMob->gold_drop = 50;
                    tempMob->type_mob = LORD;
                    break;
                case 2:
                    tempMob->health = 500;
                    tempMob->mana = 45;
                    tempMob->agility = 40;
                    tempMob->attack = 70;
                    tempMob->defense = 22;
                    tempMob->level = 7;
                    tempMob->xp_drop = 1200;
                    tempMob->id_type = 5;
                    tempMob->gold_drop = 50;
                    tempMob->type_mob = LORD;
                    break;
                default:
                    tempMob->health = 30;
                    tempMob->mana = 45;
                    tempMob->agility = 3;
                    tempMob->attack = 4;
                    tempMob->defense = 2;
                    tempMob->level = 0;
                    tempMob->xp_drop = 320;
                    tempMob->id_type = 5;
                    tempMob->type_mob = LORD;
                    break;
            }
            break;
        case BOSS:
            switch (tipo_boss){
                case 0:
                    tempMob->health = 1850;
                    tempMob->mana = 0;
                    tempMob->agility = 19;
                    tempMob->attack = 78;
                    tempMob->defense = 40;
                    tempMob->level = 8;
                    tempMob->xp_drop = 2000;
                    tempMob->id_type = 6;
                    tempMob->gold_drop = 150;
                    tempMob->type_mob = BOSS;
                    break;
                case 1:
                    tempMob->health = 2000;
                    tempMob->mana = 450;
                    tempMob->agility = 60;
                    tempMob->attack = 100;
                    tempMob->defense = 51;
                    tempMob->level = 8;
                    tempMob->xp_drop = 5000;
                    tempMob->id_type = 6;
                    tempMob->gold_drop = 150;
                    tempMob->type_mob = BOSS;
                    break;
                case 2:
                    tempMob->health = 2800;
                    tempMob->mana = 0;
                    tempMob->agility = 66;
                    tempMob->attack = 110;
                    tempMob->defense = 19;
                    tempMob->level = 8;
                    tempMob->xp_drop = 8000;
                    tempMob->id_type = 6;
                    tempMob->gold_drop = 150;
                    tempMob->type_mob = BOSS;
                    break;
                default:
                    break;

            }

            break;
        case LASTBOSS:
            tempMob->health = 4500;
            tempMob->mana = 1080;
            tempMob->rage = 0;
            tempMob->agility = 100;
            tempMob->attack = 160;
            tempMob->defense = 20;
            tempMob->level = 9;
            tempMob->xp_drop = 14500;
            tempMob->id_type = 7;
            tempMob->gold_drop = 5000;
            tempMob->type_mob = BOSS;
            break;
        default:
            tempMob->health = 10;
            tempMob->mana = 0;
            tempMob->agility = 1;
            tempMob->attack = 0;
            tempMob->defense = 0;
            tempMob->level = 0;
            tempMob->xp_drop = 1;
            tempMob->id_type = 0;
            break;
    }

    return(tempMob); // Retorna a enderesso de memoria do jogador.
}

void DisplayMobStats(mobs *target) {
    // Nao eh uma boa ideia ficar repetindo isso, por isso a funcao.

    switch(target->id_type) {
        case 1:
            printf("\n[==============================]\n");
            printf("  Monstro: %s\n", target->name);
            printf("  Tipo: MINION\n");
            printf("  Level: %d\n",target->level);
            printf("  Vida: %d\n",target->health);
            printf("  Raiva: %d\n",target->rage);
            printf("  Poder de ataque: %d\n",target->attack);
            printf("  Agilidade: %d\n",target->agility);
            printf("  Defesa: %d\n",target->defense);
            printf("  Ganha [%dXP] ao derrotar\n",target->xp_drop);
            printf("  Deixa  %dg ao derrotar\n",target->gold_drop);
            printf("[==============================]\n\n");
            break;
        case 2:
            printf("\n[==============================]\n");
            printf("  Monstro: %s\n", target->name);
            printf("  Tipo: SCOURGE\n");
            printf("  Level: %d\n",target->level);
            printf("  Vida: %d\n",target->health);
            printf("  Pontos para combo: %d\n",target->combo);
            printf("  Poder de ataque: %d\n",target->attack);
            printf("  Agilidade: %d\n",target->agility);
            printf("  Defesa: %d\n",target->defense);
            printf("  Ganha [%dXP] ao derrotar\n",target->xp_drop);
            printf("  Deixa  %dg ao derrotar\n",target->gold_drop);
            printf("[==============================]\n\n");
            break;
        case 3:
            printf("\n[==============================]\n");
            printf("  Monstro: %s\n", target->name);
            printf("  Tipo: PLAGUE\n");
            printf("  Level: %d\n",target->level);
            printf("  Vida: %d\n",target->health);
            printf("  Mana: %d\n",target->mana);
            printf("  Poder de ataque: %d\n",target->attack);
            printf("  Agilidade: %d\n",target->agility);
            printf("  Defesa: %d\n",target->defense);
            printf("  Ganha [%dXP] ao derrotar\n",target->xp_drop);
            printf("  Deixa  %dg ao derrotar\n",target->gold_drop);
            printf("[==============================]\n\n");
            break;
        case 4:
            printf("\n[==============================]\n");
            printf("  Monstro: %s\n", target->name);
            printf("  Tipo: DARK\n");
            printf("  Level: %d\n",target->level);
            printf("  Vida: %d\n",target->health);
            printf("  Mana: %d\n",target->mana);
            printf("  Poder de ataque: %d\n",target->attack);
            printf("  Agilidade: %d\n",target->agility);
            printf("  Defesa: %d\n",target->defense);
            printf("  Ganha [%dXP] ao derrotar\n",target->xp_drop);
            printf("  Deixa  %dg ao derrotar\n",target->gold_drop);
            printf("[==============================]\n\n");
            break;
        case 5:
            printf("\n[==============================]\n");
            printf("  Monstro: %s\n", target->name);
            printf("  Tipo: LORD\n");
            printf("  Level: %d\n",target->level);
            printf("  Vida: %d\n",target->health);
            printf("  Mana: %d\n",target->mana);
            printf("  Poder de ataque: %d\n",target->attack);
            printf("  Agilidade: %d\n",target->agility);
            printf("  Defesa: %d\n",target->defense);
            printf("  Ganha [%dXP] ao derrotar\n",target->xp_drop);
            printf("  Deixa  %dg ao derrotar\n",target->gold_drop);
            printf("[==============================]\n\n");
            break;
        case 6:
            printf("\n[==============================]\n");
            printf("  Monstro: %s\n", target->name);
            printf("  Tipo: BOSS\n");
            printf("  Level: %d\n",target->level);
            printf("  Vida: %d\n",target->health);
            printf("  Mana: %d\n",target->mana);
            printf("  Poder de ataque: %d\n",target->attack);
            printf("  Agilidade: %d\n",target->agility);
            printf("  Defesa: %d\n",target->defense);
            printf("  Ganha [%dXP] ao derrotar\n",target->xp_drop);
            printf("  Deixa  %dg ao derrotar\n",target->gold_drop);
            printf("[==============================]\n\n");
            break;
        case 7:
            printf("\n[==============================]\n");
            printf("  Monstro: %s\n", target->name);
            printf("  Tipo: LASTBOSS\n");
            printf("  Level: %d\n",target->level);
            printf("  Vida: %d\n",target->health);
            printf("  Mana: %d\n",target->mana);
            printf("  Raiva: %d\n", target->rage);
            printf("  Poder de ataque: %d\n",target->attack);
            printf("  Agilidade: %d\n",target->agility);
            printf("  Defesa: %d\n",target->defense);
            printf("  Ganha [%dXP] ao derrotar\n",target->xp_drop);
            printf("  Deixa  %dg ao derrotar\n",target->gold_drop);
            printf("[==============================]\n\n");
            break;
        default:
            printf("INIMIGO NAO ENCONTRADO ERRO!\n");
            break;
    }
}

int SetMobName(mobs *target, char name[50]) {
    strcpy(target->name, name);
    return(0);
}
