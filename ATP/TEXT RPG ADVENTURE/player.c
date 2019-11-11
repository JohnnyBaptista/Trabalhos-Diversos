//
// Created by ratob on 23/05/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>

#include "headers/player.h"
#include "headers/skill.h"

player* NewPlayer(classes classe, char name[50]) {
    setlocale(LC_ALL, "Portuguese");
    // Alocando memoria para o ponteiro jogador.
    player *tempPlayer = malloc(sizeof(player));
    SetName(tempPlayer, name);

    static int PlayersCreated = 0; // Variavel para acompanhar o progresso dos players criados.

    ++PlayersCreated;

    // Associa os status conforme a classe.
    switch(classe) {
        case WARRIOR:
            tempPlayer->health = 60;
            tempPlayer->max_health = 60;
            tempPlayer->rage = 0;
            tempPlayer->agility = 5;
            tempPlayer->attack = 9;
            tempPlayer->defense = 7;
            tempPlayer->level = 0;
            tempPlayer->xp_now = 0;
            tempPlayer->xp_total = 30;
            tempPlayer->id_classe = 1;
            tempPlayer->classe = WARRIOR;
            tempPlayer->alive = 1;
            tempPlayer->gold = 30;
            break;
        case RANGER:
            tempPlayer->health = 50;
            tempPlayer->max_health = 50;
            tempPlayer->combo = 15;
            tempPlayer->agility = 6;
            tempPlayer->attack = 8;
            tempPlayer->defense = 5;
            tempPlayer->level = 0;
            tempPlayer->xp_now = 0;
            tempPlayer->xp_total = 30;
            tempPlayer->id_classe = 2;
            tempPlayer->classe = RANGER;
            tempPlayer->alive = 1;
            tempPlayer->gold = 30;
            break;
        case MAGE:
            tempPlayer->health = 40;
            tempPlayer->max_health = 40;
            tempPlayer->mana = 60;
            tempPlayer->max_mana = 60;
            tempPlayer->agility = 3;
            tempPlayer->attack = 4;
            tempPlayer->defense = 3;
            tempPlayer->level = 0;
            tempPlayer->xp_now = 0;
            tempPlayer->xp_total = 30;
            tempPlayer->id_classe = 3;
            tempPlayer->classe = MAGE;
            tempPlayer->alive = 1;
            tempPlayer->gold = 30;
            break;
        case WARLOCK:
            tempPlayer->health = 45;
            tempPlayer->max_health = 45;
            tempPlayer->mana = 50;
            tempPlayer->max_mana = 50;
            tempPlayer->agility = 4;
            tempPlayer->attack = 6;
            tempPlayer->defense = 5;
            tempPlayer->level = 0;
            tempPlayer->xp_now = 0;
            tempPlayer->xp_total = 30;
            tempPlayer->id_classe = 4;
            tempPlayer->classe = WARLOCK;
            tempPlayer->alive = 1;
            tempPlayer->gold = 30;
            break;
        case PALADIN:
            tempPlayer->health = 55;
            tempPlayer->max_health = 55;
            tempPlayer->mana = 60;
            tempPlayer->max_mana = 60;
            tempPlayer->agility = 5;
            tempPlayer->attack = 9;
            tempPlayer->defense = 8;
            tempPlayer->level = 0;
            tempPlayer->xp_now = 0;
            tempPlayer->xp_total = 30;
            tempPlayer->id_classe = 5;
            tempPlayer->classe = PALADIN;
            tempPlayer->alive = 1;
            tempPlayer->gold = 30;
            break;
        default:
            tempPlayer->health = 10;
            tempPlayer->mana = 0;
            tempPlayer->max_mana = 50;
            tempPlayer->agility = 1;
            tempPlayer->attack = 0;
            tempPlayer->defense = 0;
            tempPlayer->level = 0;
            tempPlayer->xp_now = 0;
            tempPlayer->xp_total = 30;
            tempPlayer->id_classe = 0;
            tempPlayer->alive = 1;
            tempPlayer->gold = 30;
            break;
    }

    return(tempPlayer); // Retorna a enderesso de memoria do jogador.
}

// Passando o Player como argumento e mostrando sua vida, mana e nome.
void DisplayStats(player *target) {
    setlocale(LC_ALL, "Portuguese");
    // Nao eh uma boa ideia ficar repetindo isso, por isso a funcao.
    switch(target->id_classe) {
        case 1:
            printf("\n[==============================]\n");
            printf("  Nome: %s\n", target->name);
            printf("  Classe: WARRIOR\n");
            printf("  Level: %d\n",target->level);
            printf("  Vida: %d\n",target->health);
            printf("  Raiva: %d\n",target->rage);
            printf("  Poder de ataque: %d\n",target->attack);
            printf("  Agilidade: %d\n",target->agility);
            printf("  Defesa: %d\n",target->defense);
            printf("  XP [%d/%d]\n",target->xp_now,target->xp_total);
            printf("  Ouro: %dg\n",target->gold);
            printf("[==============================]\n\n");
            break;
        case 2:
            printf("\n[==============================]\n");
            printf("  Nome: %s\n", target->name);
            printf("  Classe: RANGER\n");
            printf("  Level: %d\n",target->level);
            printf("  Vida: %d\n",target->health);
            printf("  Pontos para combo: %d\n",target->combo);
            printf("  Poder de ataque: %d\n",target->attack);
            printf("  Agilidade: %d\n",target->agility);
            printf("  Defesa: %d\n",target->defense);
            printf("  XP [%d/%d]\n",target->xp_now,target->xp_total);
            printf("  Ouro: %dg\n",target->gold);
            printf("[==============================]\n\n");
            break;
        case 3:
            printf("\n[==============================]\n");
            printf("  Nome: %s\n", target->name);
            printf("  Classe: MAGE\n");
            printf("  Level: %d\n",target->level);
            printf("  Vida: %d\n",target->health);
            printf("  Mana: %d\n",target->mana);
            printf("  Poder de ataque: %d\n",target->attack);
            printf("  Agilidade: %d\n",target->agility);
            printf("  Defesa: %d\n",target->defense);
            printf("  XP [%d/%d]\n",target->xp_now,target->xp_total);
            printf("  Ouro: %dg\n",target->gold);
            printf("[==============================]\n\n");
            break;
        case 4:
            printf("\n[==============================]\n");
            printf(" Nome: %s\n", target->name);
            printf(" Classe: WARLOCK\n");
            printf(" Level: %d\n",target->level);
            printf(" Vida: %d\n",target->health);
            printf(" Mana: %d\n",target->mana);
            printf(" Poder de ataque: %d\n",target->attack);
            printf(" Agilidade: %d\n",target->agility);
            printf(" Defesa: %d\n",target->defense);
            printf(" XP [%d/%d]\n",target->xp_now,target->xp_total);
            printf(" Ouro: %dg\n",target->gold);
            printf("[==============================]\n\n");
            break;
        case 5:
            printf("\n[==============================]\n");
            printf(" Nome: %s\n", target->name);
            printf(" Classe: PALADINO\n");
            printf(" Level: %d\n",target->level);
            printf(" Vida: %d\n",target->health);
            printf(" Mana: %d\n",target->mana);
            printf(" Poder de ataque: %d\n",target->attack);
            printf(" Agilidade: %d\n",target->agility);
            printf(" Defesa: %d\n",target->defense);
            printf(" XP [%d/%d]\n",target->xp_now,target->xp_total);
            printf(" Ouro: %dg\n",target->gold);
            printf("[==============================]\n\n");
            break;
        default:
            printf("ERRO!\n");
            break;
    }

}

//Setando seu nome
int SetName(player *target, char name[50]) {
    strcpy(target->name, name);
    return(0);
}
