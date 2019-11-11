//
// Created by ratob on 25/05/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

#include "headers/player.h"
#include "headers/mobs.h"
#include "headers/mobsSkill.h"
#include "headers/inventory.h"
#include "headers/fightSystem.h"

void pause_fight(){
    printf("Aperte qualquer tecla para continuar. . . \n");
    getch();
}

void delay_in_fight(int number_of_seconds) {
    // Convertendo o tempo em milisegundos
    int milli_seconds = 1000 * number_of_seconds;

    // Inicia o contador
    clock_t start_time = clock();

    // Loop ate o tempo pedido
    while (clock() < start_time + milli_seconds);
}

int RNG_GAME_FIGHT(int n) {
    int limit;
    int r;
    srand(time(NULL));
    limit = RAND_MAX - (RAND_MAX % n);

    while((r = rand()) >= limit);

    return r % n;
}

int DisplayFightMenu (int choice) {
    printf("1) Atacar\n");
    printf("2) Habilidades\n");
    printf("3) Inventario\n");
    printf("4) Fugir do combate\n");
    printf(">>: ");
    scanf("%d", &choice);

    return choice;
}

int ItemOption(){
    int op;
    printf("\n*Digite o ID do item a sua escolha* (digite -1 , para nao escolher um item)\n");
    printf(">>: "); scanf("%d", &op);
    return op;
}

skill* searchSkill(skill *pointer_skill, int op){
    if (pointer_skill == NULL) return  NULL;
    if (pointer_skill->skill_id == op) return pointer_skill;
    return searchSkill(pointer_skill, op);
}

skill_prop* DisplaySkills(skill *pointer_skill, skill_prop *prop_skill_pointer){
    int op;
    skill *aux = (skill*)malloc(sizeof(skill));
    skill *aux2 = (skill*)malloc(sizeof(skill));
    aux = pointer_skill;
    aux2 = pointer_skill;
    printf("\n");
    printf("[========================Habilidades que podem ser usadas========================]\n");
    while(aux != NULL){
        printf(" ID:%d:\n",aux->skill_id);
        printf(" Nome da Skill: %s\n", aux->skill_name);
        printf(" Descricao: %s\n", aux->skill_description);
        printf(" Dano ao oponente: %d de dano a vida\n", aux->skill_dmg);
        printf(" Custo da skill: %d\n\n", aux->skill_use);
        aux = aux->proximo;
    }
    printf("[================================================================================]\n");;
    printf("Digite o ID da skill que voce quer usar:");
    printf("\n>>: ");
    scanf("%d", &op);

    while(aux2 != NULL){
        if(aux2->skill_id == op){
            prop_skill_pointer->skill_prop_id = aux2->skill_id;
            strcpy(prop_skill_pointer->skill_prop_name, aux2->skill_name);
            strcpy(prop_skill_pointer->skill_prop_description, aux2->skill_description);
            prop_skill_pointer->skill_prop_dmg = aux2->skill_dmg;
            prop_skill_pointer->skill_prop_use = aux2->skill_use;
        }
        aux2 = aux2->proximo;
    }


    return prop_skill_pointer;
}

player* Fight(player* attacker, mobs* monster, skill *pointer_skill, skill_prop *prop_skill_pointer, inventory *inv_pointer){
    int EffectiveAttack_player = attacker->attack - monster->defense;
    int EffectiveAttack_monster = monster->attack - attacker->defense;
    inventory *aux_inv = (inventory*)malloc(sizeof(inventory));
    skill_prop *aux = (skill_prop*)malloc(sizeof(skill_prop));

	int max_health = attacker->health;
	int max_mana = attacker->max_mana;
	int mini_rng;
	
    if(attacker->agility >= monster->agility){ // se a agilidade da classe do jogador for maior, ele comeca atacando, caso contratio o monstro tem o primeiro ataque
        int choice = 0; // variavel que representa a escolha do jogador dentre as 4 disponiveis.
        int choosen = -1; // variavel que representa a escolha do jogador sobre qual item ele vai usar.
        int turno = 0; // variavel para o turno, quando o turno troca de valor, eh a vez do monstro atacar.
        int rng_skill;
        while(attacker->health > 0 && monster->health > 0) {
            system("cls");

            if(attacker->xp_total <= attacker->xp_now){
                attacker = level_up(attacker);
                skills_add(attacker, pointer_skill);
                if(attacker->xp_now >= attacker->xp_total){
                    while(attacker->xp_now >= attacker->xp_total){
                        attacker = level_up(attacker);
                        skills_add(attacker, pointer_skill);
                    }
                }
            }

            time_t t;
            srand((unsigned) time(&t));
            //int rng_attack = rand()%2; // rng pro tipo do ataque do monstro, 0 ataque normal, 1 ataque usando uma habilidade.
            int rng_attack = 1;
            DisplayMobStats(monster); // status do monstro
            DisplayStats(attacker); // status do player


            if(turno == 0){ // turno do jogador
                choice = DisplayFightMenu(choice); // mostrando as opcoes da luta
                switch(attacker->id_classe){
                    case 1: // Caso a classe seja guerreiro
                        switch (choice){
                            case 1:
                                if(EffectiveAttack_player <= 0 ){ // caso o ataque do jogador seja muito fraco, o ataque eh setado para 0, para evitar numeros negativos
                                    EffectiveAttack_player = 0; 
                                }
                                monster->health = monster->health - EffectiveAttack_player; // vida do monstro eh modificada conforme o dano que ele recebe do jogador
                                printf("\n%s causou %d de dano a %s...\n", attacker->name, EffectiveAttack_player, monster->name); // print de quem atacou quem e o dano causado
                                pause_fight();
                                turno = 1; // passa o turno
                                break;
                            case 2:
                                aux = DisplaySkills(pointer_skill, prop_skill_pointer);
                                if(aux == NULL){
                                    printf("\n > Opcao invalida!\n");
                                    turno = 1;
                                }

                                if(attacker->rage >= aux->skill_prop_use){
                                    attacker->rage = attacker->rage - aux->skill_prop_use;

                                    if(attacker->rage <= 0){
                                        attacker->rage = 0;
                                    }

                                    monster->health = monster->health - aux->skill_prop_dmg;
                                    printf("\n%s causou %d de dano com %s a %s...\n", attacker->name, aux->skill_prop_dmg, aux->skill_prop_name, monster->name);
                                    turno = 1;
                                }

                                else{
                                    printf("\n > %s nao tem raiva suficiente para usar %s\n", attacker->name, aux->skill_prop_name);
                                    turno = 1;
                                }
                                pause_fight();
                                break;
                            case 3:
                                system("cls");
                                DisplayItems(inv_pointer);
                                choosen = ItemOption();
								switch(choosen){
								    case 0:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s\n",attacker->name ,aux_inv->current->item_name);
								        attacker->health = aux_inv->current->health + attacker->health;

								        if(attacker->health > max_health)
								            attacker->health = max_health;

								        printf("%s Recuperou %d.\n", attacker->name, aux_inv->current->health);
                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
										break;
									case 1:
										printf("\n\nGuerreiros nao podem usar mana...!\n");
										pause_fight();
										break;
									case 2:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s",attacker->name ,aux_inv->current->item_name);
                                        attacker->health = aux_inv->current->health + attacker->health;

                                        if(attacker->health > max_health)
                                            attacker->health = max_health;

                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
										break;
									case 3:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        attacker->rage = aux_inv->current->rage + attacker->rage;

                                        if(attacker->rage > 100)
                                            attacker->rage = 100;

                                        printf("\n %s usou %s",attacker->name ,aux_inv->current->item_name);
                                        RemoveItem(inv_pointer, choosen);
                                        pause_fight();
										break;
									case 4:
										printf("\n\nGuerreiros não tem combo para recuperar...!\n");
										break;
									case 5:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s\n",attacker->name ,aux_inv->current->item_name);
                                        attacker->health = aux_inv->current->health + attacker->health;

                                        if(attacker->health > max_health)
                                            attacker->health = max_health;

                                        printf("%s Recuperou %d.\n", attacker->name, aux_inv->current->health);
                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
										break;
									case 6:
                                        printf("\n\nGuerreiros nao podem usar mana...!\n");
                                        pause_fight();
										break;
								    case 7:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s",attacker->name ,aux_inv->current->item_name);
                                        attacker->attack = aux_inv->current->attack + attacker->attack;

                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
								    case 8:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s",attacker->name ,aux_inv->current->item_name);
                                        attacker->health = aux_inv->current->health + attacker->health;

                                        if(attacker->health > max_health)
                                            attacker->health = max_health;

                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
								        break;
								    case 9:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s",attacker->name ,aux_inv->current->item_name);
                                        attacker->defense = aux_inv->current->defense + attacker->defense;

                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
								        break;
                                    default:
                                        printf("\n >>Saindo do Display<<");
                                        delay_in_fight(1); printf(". ");
                                        delay_in_fight(1); printf(". ");
                                        delay_in_fight(1); printf(".\n");
                                        break;
								}
                                break;
                            case 4:// fugindo da luta
                            	mini_rng = RNG(2);
								if(mini_rng == 1) {
									printf("**> %s desistiu do combate e esta fugindo...\n", attacker->name);
                                	return attacker;	
								}
								
								else if(mini_rng == 0) {
									printf("**> %s fracassou a sua fuga",attacker->name); delay_in_fight(1);
									turno = 1;
								}
                                break;
                            default:
                                printf("*>Erro na escolha, tente de novo<*\n");
                                break;
                        }
                        break;
                    case 2: // Caso a classe seja vigilante
                        switch (choice){
                            case 1:// ataque normal
                                if(EffectiveAttack_player <= 0 ){
                                    EffectiveAttack_player = 0;
                                }
                                monster->health = monster->health - EffectiveAttack_player;
                                printf("\n%s causou %d de dano a %s...\n", attacker->name, EffectiveAttack_player, monster->name);
                                pause_fight();
                                turno = 1;
                                break;
                            case 2:
                                aux = DisplaySkills(pointer_skill, prop_skill_pointer);
                                if(attacker->combo >= aux->skill_prop_use){
                                    attacker->combo = attacker->combo - aux->skill_prop_use;

                                    if(attacker->combo <= 0){
                                        attacker->combo = 0;
                                    }

                                    monster->health = monster->health - aux->skill_prop_dmg;
                                    printf("\n%s causou %d de dano com %s a %s...\n", attacker->name, aux->skill_prop_dmg, aux->skill_prop_name, monster->name);
                                    turno = 1;
                                }

                                else{
                                    printf("\n > %s nao tem combo suficiente para usar %s\n", attacker->name, aux->skill_prop_name);
                                    turno = 1;
                                }
                                pause_fight();
                                break;
                            case 3:
                                system("cls");
                                DisplayItems(inv_pointer);
                                choosen = ItemOption();
                                switch(choosen){
                                    case 0:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s\n",attacker->name ,aux_inv->current->item_name);
                                        attacker->health = aux_inv->current->health + attacker->health;

                                        if(attacker->health > max_health)
                                            attacker->health = max_health;

                                        printf("%s Recuperou %d.\n", attacker->name, aux_inv->current->health);
                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 1:
                                        printf("\n\nVigilantes nao podem usar mana...!\n");
                                        pause_fight();
                                        break;
                                    case 2:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s",attacker->name ,aux_inv->current->item_name);
                                        attacker->health = aux_inv->current->health + attacker->health;

                                        if(attacker->health > max_health)
                                            attacker->health = max_health;

                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 3:
                                        printf("\n\nVigilantes não tem raiva para ganhar...!\n");
                                        pause_fight();
                                        break;
                                    case 4:
                                        attacker->combo = aux_inv->current->combo + attacker->combo;

                                        if(attacker->combo > 15)
                                            attacker->combo = 15;

                                        printf("\n %s usou %s",attacker->name ,aux_inv->current->item_name);
                                        RemoveItem(inv_pointer, choosen);
                                        pause_fight();
                                        break;
                                    case 5:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s\n",attacker->name ,aux_inv->current->item_name);
                                        attacker->health = aux_inv->current->health + attacker->health;

                                        if(attacker->health > max_health)
                                            attacker->health = max_health;

                                        printf("%s Recuperou %d.\n", attacker->name, aux_inv->current->health);
                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 6:
                                        printf("\n\nVigilantes nao podem usar mana...!\n");
                                        pause_fight();
                                        break;
                                    case 7:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s",attacker->name ,aux_inv->current->item_name);
                                        attacker->attack = aux_inv->current->attack + attacker->attack;

                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 8:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s",attacker->name ,aux_inv->current->item_name);
                                        attacker->health = aux_inv->current->health + attacker->health;

                                        if(attacker->health > max_health)
                                            attacker->health = max_health;

                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 9:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s",attacker->name ,aux_inv->current->item_name);
                                        attacker->defense = aux_inv->current->defense + attacker->defense;

                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    default:
                                        printf("\n >>Saindo do Display<<");
                                        delay_in_fight(1); printf(". ");
                                        delay_in_fight(1); printf(". ");
                                        delay_in_fight(1); printf(".\n");
                                        break;
                                }
                                break;
                            case 4:// fugindo da luta
                                mini_rng = RNG(2);
                                if(mini_rng == 1) {
                                    printf("**> %s desistiu do combate e esta fugindo...\n", attacker->name);
                                    return attacker;
                                }

                                else if(mini_rng == 0) {
                                    printf("**> %s fracassou a sua fuga",attacker->name); delay_in_fight(1);
                                    turno = 1;
                                }
                                break;
                            default:
                                printf("*>Erro na escolha, tente de novo<*\n");
                                break;
                        }
                        break;
                    case 3: // Caso a classe seja Mago
                        switch (choice){
                            case 1:// ataque normal
                                if(EffectiveAttack_player <= 0 ){
                                    EffectiveAttack_player = 0;
                                }
                                monster->health = monster->health - EffectiveAttack_player;
                                printf("\n%s causou %d de dano a %s...\n", attacker->name, EffectiveAttack_player, monster->name);
                                pause_fight();
                                turno = 1;
                                break;
                            case 2:// usando habilidades
                                aux = DisplaySkills(pointer_skill, prop_skill_pointer);
                                if(attacker->mana >= pointer_skill->skill_use){
                                    attacker->mana = attacker->mana - pointer_skill->skill_use;
                                    if(attacker->mana <= 0){
                                        attacker->mana = 0;
                                    }
                                    monster->health = monster->health - aux->skill_prop_dmg;
                                    printf("\n%s causou %d de dano com %s a %s...\n", attacker->name, aux->skill_prop_dmg, aux->skill_prop_name, monster->name);
                                    turno = 1;
                                }

                                else{
                                    printf("%s nao tem mana para usar %s\n", attacker->name, aux->skill_prop_name);
                                    turno = 1;
                                }
                                pause_fight();
                                break;
                            case 3: // usando inventario
                                system("cls");
                                DisplayItems(inv_pointer);
                                choosen = ItemOption();
                                switch(choosen){
                                    case 0:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s\n",attacker->name ,aux_inv->current->item_name);
                                        attacker->health = aux_inv->current->health + attacker->health;

                                        if(attacker->health > max_health)
                                            attacker->health = max_health;

                                        printf("%s Recuperou %d.\n", attacker->name, aux_inv->current->health);
                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 1:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s\n",attacker->name ,aux_inv->current->item_name);
                                        attacker->mana = aux_inv->current->mana + attacker->mana;

                                        if(attacker->mana > max_mana)
                                            attacker->mana = max_mana;

                                        printf("%s Recuperou %d.\n", attacker->name, aux_inv->current->mana);
                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 2:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s",attacker->name ,aux_inv->current->item_name);
                                        attacker->health = aux_inv->current->health + attacker->health;
                                        attacker->mana = aux_inv->current->mana + attacker->mana;

                                        if(attacker->health > max_health)
                                            attacker->health = max_health;

                                        if(attacker->mana > max_mana)
                                            attacker->mana = max_mana;

                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 3:
                                        printf("\nMagos nao podem usar raiva...\n");
                                        pause_fight();
                                        break;
                                    case 4:
                                        printf("\nMagos nao podem usar combos...\n");
                                        pause_fight();
                                        break;
                                    case 5:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s\n",attacker->name ,aux_inv->current->item_name);
                                        attacker->health = aux_inv->current->health + attacker->health;

                                        if(attacker->health > max_health)
                                            attacker->health = max_health;

                                        printf("%s Recuperou %d.\n", attacker->name, aux_inv->current->health);
                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 6:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s\n",attacker->name ,aux_inv->current->item_name);
                                        attacker->mana = aux_inv->current->mana + attacker->mana;

                                        if(attacker->mana > max_mana)
                                            attacker->mana = max_mana;

                                        printf("%s Recuperou %d.\n", attacker->name, aux_inv->current->mana);
                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 7:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s",attacker->name ,aux_inv->current->item_name);
                                        attacker->attack = aux_inv->current->attack + attacker->attack;

                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 8:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s",attacker->name ,aux_inv->current->item_name);
                                        attacker->health = aux_inv->current->health + attacker->health;
                                        attacker->mana = aux_inv->current->mana + attacker->mana;

                                        if(attacker->health > max_health)
                                            attacker->health = max_health;

                                        if(attacker->mana > max_mana)
                                            attacker->mana = max_mana;

                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 9:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s",attacker->name ,aux_inv->current->item_name);
                                        attacker->defense = aux_inv->current->defense + attacker->defense;

                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    default:
                                        printf("\n >>Saindo do Display<<");
                                        delay_in_fight(1); printf(". ");
                                        delay_in_fight(1); printf(". ");
                                        delay_in_fight(1); printf(".\n");
                                        break;
                                }
                                break;
                            case 4:// fugindo da luta
                                mini_rng = RNG(2);
                                if(mini_rng == 1) {
                                    printf("**> %s desistiu do combate e esta fugindo...\n", attacker->name);
                                    return attacker;
                                }

                                else if(mini_rng == 0) {
                                    printf("**> %s fracassou a sua fuga",attacker->name); delay_in_fight(1);
                                    turno = 1;
                                }
                                break;
                            default:
                                printf("*>Erro na escolha, tente de novo<*\n");
                                break;
                        }
                        break;
                    case 4: // Caso a classe seja bruxo
                        switch (choice){
                            case 1: // ataque normal
                                if(EffectiveAttack_player <= 0 ){
                                    EffectiveAttack_player = 0;
                                }
                                monster->health = monster->health - EffectiveAttack_player;
                                printf("\n%s causou %d de dano a %s...\n", attacker->name, EffectiveAttack_player, monster->name);
                                pause_fight();
                                turno = 1;
                                break;
                            case 2: // usando habilidades
                                aux = DisplaySkills(pointer_skill, prop_skill_pointer);
                                if(attacker->mana >= pointer_skill->skill_use){
                                    attacker->mana = attacker->mana - pointer_skill->skill_use;
                                    if(attacker->mana <= 0){
                                        attacker->mana = 0;
                                    }
                                    monster->health = monster->health - aux->skill_prop_dmg;
                                    printf("\n%s causou %d de dano com %s a %s...\n", attacker->name, aux->skill_prop_dmg, aux->skill_prop_name, monster->name);
                                    turno = 1;
                                }

                                else{
                                    printf("%s nao tem mana para usar %s\n", attacker->name, aux->skill_prop_name);
                                    turno = 1;
                                }
                                break;
                            case 3: // usando o inventario
                                system("cls");
                                DisplayItems(inv_pointer);
                                choosen = ItemOption();
                                switch(choosen){
                                    case 0:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s\n",attacker->name ,aux_inv->current->item_name);
                                        attacker->health = aux_inv->current->health + attacker->health;

                                        if(attacker->health > max_health)
                                            attacker->health = max_health;

                                        printf("%s Recuperou %d.\n", attacker->name, aux_inv->current->health);
                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 1:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s\n",attacker->name ,aux_inv->current->item_name);
                                        attacker->mana = aux_inv->current->mana + attacker->mana;

                                        if(attacker->mana > max_mana)
                                            attacker->mana = max_mana;

                                        printf("%s Recuperou %d.\n", attacker->name, aux_inv->current->mana);
                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 2:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s",attacker->name ,aux_inv->current->item_name);
                                        attacker->health = aux_inv->current->health + attacker->health;
                                        attacker->mana = aux_inv->current->mana + attacker->mana;

                                        if(attacker->health > max_health)
                                            attacker->health = max_health;

                                        if(attacker->mana > max_mana)
                                            attacker->mana = max_mana;

                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 3:
                                        printf("\nBruxos nao podem usar raiva...\n");
                                        pause_fight();
                                        break;
                                    case 4:
                                        printf("\nBruxos nao podem usar combos...\n");
                                        pause_fight();
                                        break;
                                    case 5:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s\n",attacker->name ,aux_inv->current->item_name);
                                        attacker->health = aux_inv->current->health + attacker->health;

                                        if(attacker->health > max_health)
                                            attacker->health = max_health;

                                        printf("%s Recuperou %d.\n", attacker->name, aux_inv->current->health);
                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 6:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s\n",attacker->name ,aux_inv->current->item_name);
                                        attacker->mana = aux_inv->current->mana + attacker->mana;

                                        if(attacker->mana > max_mana)
                                            attacker->mana = max_mana;

                                        printf("%s Recuperou %d.\n", attacker->name, aux_inv->current->mana);
                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 7:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s",attacker->name ,aux_inv->current->item_name);
                                        attacker->attack = aux_inv->current->attack + attacker->attack;

                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 8:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s",attacker->name ,aux_inv->current->item_name);
                                        attacker->health = aux_inv->current->health + attacker->health;
                                        attacker->mana = aux_inv->current->mana + attacker->mana;

                                        if(attacker->health > max_health)
                                            attacker->health = max_health;

                                        if(attacker->mana > max_mana)
                                            attacker->mana = max_mana;

                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 9:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s",attacker->name ,aux_inv->current->item_name);
                                        attacker->defense = aux_inv->current->defense + attacker->defense;

                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    default:
                                        printf("\n >>Saindo do Display<<");
                                        delay_in_fight(1); printf(". ");
                                        delay_in_fight(1); printf(". ");
                                        delay_in_fight(1); printf(".\n");
                                        break;
                                }
                                break;
                            case 4:// fugindo da luta
                                mini_rng = RNG(2);
                                if(mini_rng == 1) {
                                    printf("**> %s desistiu do combate e esta fugindo...\n", attacker->name);
                                    return attacker;
                                }

                                else if(mini_rng == 0) {
                                    printf("**> %s fracassou a sua fuga",attacker->name); delay_in_fight(1);
                                    turno = 1;
                                }
                                break;
                            default:
                                printf("*>Erro na escolha, tente de novo<*\n");
                                break;
                        }
                        break;
                    case 5:
                        switch (choice){
                            case 1:
                                if(EffectiveAttack_player <= 0 ){
                                    EffectiveAttack_player = 0;
                                }
                                monster->health = monster->health - EffectiveAttack_player;
                                printf("\n%s causou %d de dano a %s...\n", attacker->name, EffectiveAttack_player, monster->name);
                                pause_fight();
                                turno = 0;
                                break;
                            case 2:
                                aux = DisplaySkills(pointer_skill, prop_skill_pointer);
                                if(attacker->mana >= aux->skill_prop_use){
                                    attacker->mana = attacker->mana - pointer_skill->skill_use;
                                    if(attacker->mana <= 0){
                                        attacker->mana = 0;
                                    }
                                    monster->health = monster->health - aux->skill_prop_dmg;
                                    printf("\n%s causou %d de dano com %s a %s...\n", attacker->name, aux->skill_prop_dmg, aux->skill_prop_name, monster->name);
                                    turno = 0;
                                }

                                else{
                                    printf("%s nao tem mana para usar %s\n", attacker->name, aux->skill_prop_name);
                                    turno = 0;
                                }
                                pause_fight();
                                break;
                            case 3:
                                system("cls");
                                DisplayItems(inv_pointer);
                                choosen = ItemOption();
                                switch(choosen){
                                    case 0:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s\n",attacker->name ,aux_inv->current->item_name);
                                        attacker->health = aux_inv->current->health + attacker->health;

                                        if(attacker->health > max_health)
                                            attacker->health = max_health;

                                        printf("%s Recuperou %d.\n", attacker->name, aux_inv->current->health);
                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 1:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s\n",attacker->name ,aux_inv->current->item_name);
                                        attacker->mana = aux_inv->current->mana + attacker->mana;

                                        if(attacker->mana > max_mana)
                                            attacker->mana = max_mana;

                                        printf("%s Recuperou %d.\n", attacker->name, aux_inv->current->mana);
                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 2:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s",attacker->name ,aux_inv->current->item_name);
                                        attacker->health = aux_inv->current->health + attacker->health;
                                        attacker->mana = aux_inv->current->mana + attacker->mana;

                                        if(attacker->health > max_health)
                                            attacker->health = max_health;

                                        if(attacker->mana > max_mana)
                                            attacker->mana = max_mana;

                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 3:
                                        printf("\nPaladinos nao podem usar raiva...\n");
                                        pause_fight();
                                        break;
                                    case 4:
                                        printf("\nPaladinos nao podem usar combos...\n");
                                        pause_fight();
                                        break;
                                    case 5:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s\n",attacker->name ,aux_inv->current->item_name);
                                        attacker->health = aux_inv->current->health + attacker->health;

                                        if(attacker->health > max_health)
                                            attacker->health = max_health;

                                        printf("%s Recuperou %d.\n", attacker->name, aux_inv->current->health);
                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 6:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s\n",attacker->name ,aux_inv->current->item_name);
                                        attacker->mana = aux_inv->current->mana + attacker->mana;

                                        if(attacker->mana > max_mana)
                                            attacker->mana = max_mana;

                                        printf("%s Recuperou %d.\n", attacker->name, aux_inv->current->mana);
                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 7:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s",attacker->name ,aux_inv->current->item_name);
                                        attacker->attack = aux_inv->current->attack + attacker->attack;

                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 8:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s",attacker->name ,aux_inv->current->item_name);
                                        attacker->health = aux_inv->current->health + attacker->health;
                                        attacker->mana = aux_inv->current->mana + attacker->mana;

                                        if(attacker->health > max_health)
                                            attacker->health = max_health;

                                        if(attacker->mana > max_mana)
                                            attacker->mana = max_mana;

                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 9:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s",attacker->name ,aux_inv->current->item_name);
                                        attacker->defense = aux_inv->current->defense + attacker->defense;

                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    default:
                                        printf("\n >>Saindo do Display<<");
                                        delay_in_fight(1); printf(". ");
                                        delay_in_fight(1); printf(". ");
                                        delay_in_fight(1); printf(".\n");
                                        break;
                                }
                                break;
                            case 4:
                                mini_rng = RNG(2);
                                if(mini_rng == 1) {
                                    printf("**> %s desistiu do combate e esta fugindo...\n", attacker->name);
                                    return attacker;
                                }

                                else if(mini_rng == 0) {
                                    printf("**> %s fracassou a sua fuga",attacker->name); delay_in_fight(1);
                                    turno = 0;
                                }
                                break;
                            default:
                                printf("*>Erro na escolha, tente de novo<*\n");
                                break;
                        }
                        break;
                }

                if(monster->combo < 15)
                    monster->combo = monster->combo + 2;
            }

            else{ // turno do monstro
                if(EffectiveAttack_monster <= 0){ // Caso o ataque seja negativo e evitar curar o jogador...
                    EffectiveAttack_monster = 0;
                }

                if( monster->id_type <= 4) {
                    if(attacker->id_classe == 1){ // aumenta a raiva do guerreiro conforme ele leva dano
                        if(attacker->rage <=100)
                            attacker->rage = attacker->rage + 4;
                    }

                    if(attacker->id_classe == 2){ // Recupera o combo do vigilante
                        if(attacker->combo < 15 && attacker->combo > 0)
                            attacker->combo = attacker->combo + 2;
                    }

                    attacker->health = attacker->health - EffectiveAttack_monster;
                    printf("\n%s causou %d de dano a %s...\n", monster->name, EffectiveAttack_monster, attacker->name);
                    pause_fight();
                }

                else {
                    srand(time(NULL));
                    int rng_lord = rand()%2;
                    int rng_boss = rand()%5;
                    int rng_lastboss = rand()%6;

                    switch(monster->id_type){
                        case 5:
                            switch(rng_lord){
                                case 0:
                                    attacker->health = attacker->health - EffectiveAttack_monster;
                                    printf("\n%s causou %d de dano a %s...\n", monster->name, EffectiveAttack_monster, attacker->name);
                                    pause_fight();
                                    break;
                                case 1:
                                    if(monster->mana == 45 ){
                                        attacker->health = (attacker->health + attacker->defense) - 120;
                                        printf("\n%s causou %d de dano a %s com Golpe abismal\n", monster->name, ((attacker->health + attacker->defense) - 120), attacker->name);
                                        monster->mana = 0;
                                        pause_fight();
                                    }

                                    else{
                                        attacker->health = attacker->health - EffectiveAttack_monster;
                                        printf("\n%s causou %d de dano a %s...\n", monster->name, EffectiveAttack_monster, attacker->name);
                                        monster->mana = monster->mana + 10;
                                        pause_fight();
                                    }

                                    break;
                                default:
                                    attacker->health = attacker->health - EffectiveAttack_monster;
                                    printf("\n%s causou %d de dano a %s...\n", monster->name, EffectiveAttack_monster, attacker->name);
                                    pause_fight();
                                    break;
                            }
                            break;
                        case 6:
                            switch(rng_boss){
                                case 0:
                                    attacker->health = attacker->health - EffectiveAttack_monster;
                                    printf("\n%s causou %d de dano a %s...\n", monster->name, EffectiveAttack_monster, attacker->name);
                                    pause_fight();
                                    break;
                                case 1:
                                    if(monster->mana >= 45 ){
                                        attacker->health = attacker->health - 80;
                                        printf("\n%s causou %d de dano a %s com Golpe abismal\n", monster->name, (attacker->health - 80), attacker->name);
                                        monster->mana = monster->mana - 45;
                                        pause_fight();
                                    }

                                    else{
                                        attacker->health = attacker->health - EffectiveAttack_monster;
                                        printf("\n%s causou %d de dano a %s...\n", monster->name, EffectiveAttack_monster, attacker->name);
                                        monster->mana = monster->mana + 100;
                                        pause_fight();
                                    }
                                    break;
                                case 2:
                                    if(monster->mana >= 120 ){
                                        attacker->health = attacker->health - 180;
                                        printf("\n%s causou %d de dano a %s com Fogo d'alma obscura\n", monster->name, (attacker->health - 180), attacker->name);
                                        monster->mana = monster->mana - 120;
                                        pause_fight();
                                    }

                                    else{
                                        attacker->health = attacker->health - EffectiveAttack_monster;
                                        printf("\n%s causou %d de dano a %s...\n", monster->name, EffectiveAttack_monster, attacker->name);
                                        monster->mana = monster->mana + 100;
                                        pause_fight();
                                    }
                                    break;
                                case 3:
                                        printf("\n%s passa a vez e recupera %d de mana.\n", monster->name, (monster->mana + 120));
                                        monster->mana = monster->mana + 120;
                                        pause_fight();
                                    break;
                                case 4:
                                    if(monster->mana >= 300 ){
                                        attacker->health = attacker->health - 200;
                                        printf("\n%s causou %d de dano a %s com Aniquilacao\n", monster->name, (attacker->health - 200), attacker->name);
                                        monster->mana = monster->mana - 300;
                                        pause_fight();
                                    }

                                    else{
                                        attacker->health = attacker->health - EffectiveAttack_monster;
                                        printf("\n%s causou %d de dano a %s...\n", monster->name, EffectiveAttack_monster, attacker->name);
                                        pause_fight();
                                    }
                                    break;
                                default:
                                    attacker->health = attacker->health - EffectiveAttack_monster;
                                    printf("\n%s causou %d de dano a %s...\n", monster->name, EffectiveAttack_monster, attacker->name);
                                    monster->mana = monster->mana + 100;
                                    pause_fight();
                                    break;
                            }
                            break;
                        case 7:
                            switch(rng_lastboss){
                                case 0:
                                    attacker->health = attacker->health - EffectiveAttack_monster;
                                    printf("\n%s causou %d de dano a %s...\n", monster->name, EffectiveAttack_monster, attacker->name);
                                    pause_fight();
                                    break;
                                case 1:
                                    if(monster->mana >= 400 ){
                                        attacker->health = attacker->health - 220;
                                        printf("\n%s causou %d de dano a %s com Sussuro Antigo\n", monster->name, (attacker->health - 220), attacker->name);
                                        monster->mana = monster->mana - 220;
                                        pause_fight();
                                    }

                                    else{
                                        attacker->health = attacker->health - EffectiveAttack_monster;
                                        printf("\n%s causou %d de dano a %s...\n", monster->name, EffectiveAttack_monster, attacker->name);
                                        pause_fight();
                                    }
                                    break;
                                case 2:
                                    if(monster->mana == 1080 ){
                                        attacker->health = (attacker->health + attacker->defense) - 400;
                                        printf("\n%s causou %d de dano a %s com Loucura mental\n", monster->name, ((attacker->health + attacker->defense) - 300), attacker->name);
                                        monster->mana = monster->mana - 1080;
                                        pause_fight();
                                    }

                                    else{
                                        attacker->health = attacker->health - EffectiveAttack_monster;
                                        printf("\n%s causou %d de dano a %s...\n", monster->name, EffectiveAttack_monster, attacker->name);
                                        pause_fight();
                                    }
                                    break;
                                case 3:
                                    if(monster->mana >= 180 ){
                                        attacker->health = (attacker->health) - 100 + attacker->defense;
                                        printf("\n%s causou %d de dano a %s com Esmagar\n", monster->name, ((attacker->health) - 100 + attacker->defense), attacker->name);
                                        monster->mana = monster->mana - 180;
                                        pause_fight();
                                    }

                                    else{
                                        attacker->health = attacker->health - EffectiveAttack_monster;
                                        printf("\n%s causou %d de dano a %s...\n", monster->name, EffectiveAttack_monster, attacker->name);
                                        pause_fight();
                                    }
                                    break;
                                case 4:
                                    monster->health = monster->health + 100;
                                    monster->mana = monster->mana + 180;
                                    printf("%s se regenera...", monster->name);
                                    break;
                                case 5:
                                    if(monster->mana >= 600 ){
                                        attacker->health = (attacker->health) - 300 + attacker->defense;
                                        printf("\n%s causou %d de dano a %s com Aniquilacao\n", monster->name, ((attacker->health) - 300 + attacker->defense), attacker->name);
                                        monster->mana = monster->mana - 600;
                                        pause_fight();
                                    }

                                    else{
                                        attacker->health = attacker->health - EffectiveAttack_monster;
                                        printf("\n%s causou %d de dano a %s...\n", monster->name, EffectiveAttack_monster, attacker->name);
                                        pause_fight();
                                    }
                                    break;
                                default:
                                    attacker->health = attacker->health - EffectiveAttack_monster;
                                    printf("\n%s causou %d de dano a %s...\n", monster->name, EffectiveAttack_monster, attacker->name);
                                    pause_fight();
                                    break;
                            }
                            monster->mana = monster->mana + 90;
                            break;
                        default:
                            break;
                    }
                    pause_fight();
                }
                turno = 0;
            }
        }
    }

    else if (attacker->agility <= monster->agility) { // segue o mesmo padrao do codigo acima, dando prioridade
        // a maior agilidade
        int choice = 0; // variavel que representa a escolha do jogador dentre as 4 disponiveis.
        int choosen = -1; // variavel que representa a escolha do jogador sobre qual item ele vai usar.
        int turno = 0; // variavel para o turno, quando o turno troca de valor, eh a vez do monstro atacar.
        int rng_skill;

        while (attacker->health > 0 && monster->health > 0) {
            system("cls");

            if(attacker->xp_total <= attacker->xp_now){
                attacker = level_up(attacker);
                skills_add(attacker, pointer_skill);
                if(attacker->xp_now >= attacker->xp_total){
                    while(attacker->xp_now >= attacker->xp_total){
                        attacker = level_up(attacker);
                        skills_add(attacker, pointer_skill);
                    }
                }
            }

            time_t t;
            srand((unsigned) time(&t));
            //int rng_attack = rand()%2; // rng pro tipo do ataque do monstro, 1 ataque normal, 2 ataque usando uma habilidade.
            int rng_attack = 1;
            DisplayMobStats(monster); // status do monstro
            DisplayStats(attacker); // status do player

            if (turno == 1) {
                choice = DisplayFightMenu(choice); // mostrando as opcoes da luta
                switch (attacker->id_classe) {
                    case 1:
                        switch (choice){
                            case 1:
                                if(EffectiveAttack_player <= 0 ){
                                    EffectiveAttack_player = 0;
                                }
                                monster->health = monster->health - EffectiveAttack_player;
                                printf("\n%s causou %d de dano a %s...\n", attacker->name, EffectiveAttack_player, monster->name);
                                pause_fight();
                                turno = 0;
                                break;
                            case 2:
                                aux = DisplaySkills(pointer_skill, prop_skill_pointer);
                                if(attacker->rage >= aux->skill_prop_use){
                                    attacker->rage = attacker->rage - aux->skill_prop_use;

                                    if(attacker->rage <= 0){
                                        attacker->rage = 0;
                                    }

                                    monster->health = monster->health - aux->skill_prop_dmg;
                                    printf("\n%s causou %d de dano com %s a %s...\n", attacker->name, aux->skill_prop_dmg, aux->skill_prop_name, monster->name);
                                    turno = 0;
                                }

                                else{
                                    printf("\n > %s nao tem raiva suficiente para usar %s\n", attacker->name, aux->skill_prop_name);
                                    turno = 0;
                                }
                                pause_fight();
                                break;
                            case 3:
                                system("cls");
                                DisplayItems(inv_pointer);
                                choosen = ItemOption();
                                switch(choosen){
                                    case 0:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s\n",attacker->name ,aux_inv->current->item_name);
                                        attacker->health = aux_inv->current->health + attacker->health;

                                        if(attacker->health > max_health)
                                            attacker->health = max_health;

                                        printf("%s Recuperou %d.\n", attacker->name, aux_inv->current->health);
                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 1:
                                        printf("\n\nGuerreiros nao podem usar mana...!\n");
                                        pause_fight();
                                        break;
                                    case 2:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s",attacker->name ,aux_inv->current->item_name);
                                        attacker->health = aux_inv->current->health + attacker->health;

                                        if(attacker->health > max_health)
                                            attacker->health = max_health;

                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 3:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        attacker->rage = aux_inv->current->rage + attacker->rage;

                                        if(attacker->rage > 100)
                                            attacker->rage = 100;

                                        printf("\n %s usou %s",attacker->name ,aux_inv->current->item_name);
                                        RemoveItem(inv_pointer, choosen);
                                        pause_fight();
                                        break;
                                    case 4:
                                        printf("\n\nGuerreiros nao tem combo para recuperar...!\n");
                                        break;
                                    case 5:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s\n",attacker->name ,aux_inv->current->item_name);
                                        attacker->health = aux_inv->current->health + attacker->health;

                                        if(attacker->health > max_health)
                                            attacker->health = max_health;

                                        printf("%s Recuperou %d.\n", attacker->name, aux_inv->current->health);
                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 6:
                                        printf("\n\nGuerreiros nao podem usar mana...!\n");
                                        pause_fight();
                                        break;
                                    case 7:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s",attacker->name ,aux_inv->current->item_name);
                                        attacker->attack = aux_inv->current->attack + attacker->attack;

                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 8:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s",attacker->name ,aux_inv->current->item_name);
                                        attacker->health = aux_inv->current->health + attacker->health;

                                        if(attacker->health > max_health)
                                            attacker->health = max_health;

                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 9:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s",attacker->name ,aux_inv->current->item_name);
                                        attacker->defense = aux_inv->current->defense + attacker->defense;

                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    default:
                                        printf("\n >>Saindo do Display<<");
                                        delay_in_fight(1); printf(". ");
                                        delay_in_fight(1); printf(". ");
                                        delay_in_fight(1); printf(".\n");
                                        break;
                                }
                                break;
                            case 4:
                                mini_rng = RNG(2);
                                if(mini_rng == 1) {
                                    printf("**> %s desistiu do combate e esta fugindo...\n", attacker->name);
                                    return attacker;
                                }

                                else if(mini_rng == 0) {
                                    printf("**> %s fracassou a sua fuga",attacker->name); delay_in_fight(1);
                                    turno = 0;
                                }
                                break;
                            default:
                                printf("*>Erro na escolha, tente de novo<*\n");
                                break;
                        }
                        break;
                    case 2:
                        switch (choice){
                            case 1:
                                if(EffectiveAttack_player <= 0 ){
                                    EffectiveAttack_player = 0;
                                }
                                monster->health = monster->health - EffectiveAttack_player;
                                printf("\n%s causou %d de dano a %s...\n", attacker->name, EffectiveAttack_player, monster->name);
                                pause_fight();
                                turno = 0;
                                break;
                            case 2:
                                aux = DisplaySkills(pointer_skill, prop_skill_pointer);
                                if(attacker->combo >= aux->skill_prop_use){
                                    attacker->combo = attacker->combo - aux->skill_prop_use;

                                    if(attacker->combo <= 0){
                                        attacker->combo = 15;
                                    }

                                    monster->health = monster->health - aux->skill_prop_dmg;
                                    printf("\n%s causou %d de dano com %s a %s...\n", attacker->name, aux->skill_prop_dmg, aux->skill_prop_name, monster->name);
                                    turno = 0;
                                }

                                else{
                                    printf("\n > %s nao tem combo suficiente para usar %s\n", attacker->name, aux->skill_prop_name);
                                    turno = 0;
                                }
                                pause_fight();
                            case 3:
                                system("cls");
                                DisplayItems(inv_pointer);
                                choosen = ItemOption();
                                switch(choosen){
                                    case 0:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s\n",attacker->name ,aux_inv->current->item_name);
                                        attacker->health = aux_inv->current->health + attacker->health;

                                        if(attacker->health > max_health)
                                            attacker->health = max_health;

                                        printf("%s Recuperou %d.\n", attacker->name, aux_inv->current->health);
                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 1:
                                        printf("\n\nVigilantes nao podem usar mana...!\n");
                                        pause_fight();
                                        break;
                                    case 2:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s",attacker->name ,aux_inv->current->item_name);
                                        attacker->health = aux_inv->current->health + attacker->health;

                                        if(attacker->health > max_health)
                                            attacker->health = max_health;

                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 3:
                                        printf("\n\nVigilantes não tem raiva para ganhar...!\n");
                                        pause_fight();
                                        break;
                                    case 4:
                                        attacker->combo = aux_inv->current->combo + attacker->combo;

                                        if(attacker->combo > 15)
                                            attacker->combo = 15;

                                        printf("\n %s usou %s",attacker->name ,aux_inv->current->item_name);
                                        RemoveItem(inv_pointer, choosen);
                                        pause_fight();
                                        break;
                                    case 5:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s\n",attacker->name ,aux_inv->current->item_name);
                                        attacker->health = aux_inv->current->health + attacker->health;

                                        if(attacker->health > max_health)
                                            attacker->health = max_health;

                                        printf("%s Recuperou %d.\n", attacker->name, aux_inv->current->health);
                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 6:
                                        printf("\n\nVigilantes nao podem usar mana...!\n");
                                        pause_fight();
                                        break;
                                    case 7:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s",attacker->name ,aux_inv->current->item_name);
                                        attacker->attack = aux_inv->current->attack + attacker->attack;

                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 8:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s",attacker->name ,aux_inv->current->item_name);
                                        attacker->health = aux_inv->current->health + attacker->health;

                                        if(attacker->health > max_health)
                                            attacker->health = max_health;

                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 9:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s",attacker->name ,aux_inv->current->item_name);
                                        attacker->defense = aux_inv->current->defense + attacker->defense;

                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    default:
                                        printf("\n >>Saindo do Display<<");
                                        delay_in_fight(1); printf(". ");
                                        delay_in_fight(1); printf(". ");
                                        delay_in_fight(1); printf(".\n");
                                        break;
                                }
                                break;
                            case 4:
                                mini_rng = RNG(2);
                                if(mini_rng == 1) {
                                    printf("**> %s desistiu do combate e esta fugindo...\n", attacker->name);
                                    return attacker;
                                }

                                else if(mini_rng == 0) {
                                    printf("**> %s fracassou a sua fuga",attacker->name); delay_in_fight(1);
                                    turno = 0;
                                }
                                break;
                            default:
                                printf("*>Erro na escolha, tente de novo<*\n");
                                break;
                        }
                        break;
                    case 3: // Caso a classe seja Mago
                        switch (choice){
                            case 1:
                                if(EffectiveAttack_player <= 0 ){
                                    EffectiveAttack_player = 0;
                                }
                                monster->health = monster->health - EffectiveAttack_player;
                                printf("\n%s causou %d de dano a %s...\n", attacker->name, EffectiveAttack_player, monster->name);
                                pause_fight();
                                turno = 0;
                                break;
                            case 2:
                                aux = DisplaySkills(pointer_skill, prop_skill_pointer);
                                if(attacker->mana >= aux->skill_prop_use){
                                    attacker->mana = attacker->mana - pointer_skill->skill_use;
                                    if(attacker->mana <= 0){
                                        attacker->mana = 0;
                                    }
                                    monster->health = monster->health - aux->skill_prop_dmg;
                                    printf("\n%s causou %d de dano com %s a %s...\n", attacker->name, aux->skill_prop_dmg, aux->skill_prop_name, monster->name);
                                    turno = 0;
                                }

                                else{
                                    printf("%s nao tem mana para usar %s\n", attacker->name, aux->skill_prop_name);
                                    turno = 0;
                                }
                                pause_fight();
                                break;
                            case 3:
                                system("cls");
                                DisplayItems(inv_pointer);
                                choosen = ItemOption();
                                switch(choosen){
                                    case 0:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s\n",attacker->name ,aux_inv->current->item_name);
                                        attacker->health = aux_inv->current->health + attacker->health;

                                        if(attacker->health > max_health)
                                            attacker->health = max_health;

                                        printf("%s Recuperou %d.\n", attacker->name, aux_inv->current->health);
                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 1:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s\n",attacker->name ,aux_inv->current->item_name);
                                        attacker->mana = aux_inv->current->mana + attacker->mana;

                                        if(attacker->mana > max_mana)
                                            attacker->mana = max_mana;

                                        printf("%s Recuperou %d.\n", attacker->name, aux_inv->current->mana);
                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 2:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s",attacker->name ,aux_inv->current->item_name);
                                        attacker->health = aux_inv->current->health + attacker->health;
                                        attacker->mana = aux_inv->current->mana + attacker->mana;

                                        if(attacker->health > max_health)
                                            attacker->health = max_health;

                                        if(attacker->mana > max_mana)
                                            attacker->mana = max_mana;

                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 3:
                                        printf("\nMagos nao podem usar raiva...\n");
                                        pause_fight();
                                        break;
                                    case 4:
                                        printf("\nMagos nao podem usar combos...\n");
                                        pause_fight();
                                        break;
                                    case 5:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s\n",attacker->name ,aux_inv->current->item_name);
                                        attacker->health = aux_inv->current->health + attacker->health;

                                        if(attacker->health > max_health)
                                            attacker->health = max_health;

                                        printf("%s Recuperou %d.\n", attacker->name, aux_inv->current->health);
                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 6:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s\n",attacker->name ,aux_inv->current->item_name);
                                        attacker->mana = aux_inv->current->mana + attacker->mana;

                                        if(attacker->mana > max_mana)
                                            attacker->mana = max_mana;

                                        printf("%s Recuperou %d.\n", attacker->name, aux_inv->current->mana);
                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 7:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s",attacker->name ,aux_inv->current->item_name);
                                        attacker->attack = aux_inv->current->attack + attacker->attack;

                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 8:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s",attacker->name ,aux_inv->current->item_name);
                                        attacker->health = aux_inv->current->health + attacker->health;
                                        attacker->mana = aux_inv->current->mana + attacker->mana;

                                        if(attacker->health > max_health)
                                            attacker->health = max_health;

                                        if(attacker->mana > max_mana)
                                            attacker->mana = max_mana;

                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 9:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s",attacker->name ,aux_inv->current->item_name);
                                        attacker->defense = aux_inv->current->defense + attacker->defense;

                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    default:
                                        printf("\n >>Saindo do Display<<");
                                        delay_in_fight(1); printf(". ");
                                        delay_in_fight(1); printf(". ");
                                        delay_in_fight(1); printf(".\n");
                                        break;
                                }
                                break;
                            case 4:
                                mini_rng = RNG(2);
                                if(mini_rng == 1) {
                                    printf("**> %s desistiu do combate e esta fugindo...\n", attacker->name);
                                    return attacker;
                                }

                                else if(mini_rng == 0) {
                                    printf("**> %s fracassou a sua fuga",attacker->name); delay_in_fight(1);
                                    turno = 0;
                                }
                                break;
                            default:
                                printf("*>Erro na escolha, tente de novo<*\n");
                                break;
                        }
                        break;
                    case 4:
                        switch (choice){
                            case 1:
                                if(EffectiveAttack_player <= 0 ){
                                    EffectiveAttack_player = 0;
                                }
                                monster->health = monster->health - EffectiveAttack_player;
                                printf("\n%s causou %d de dano a %s...\n", attacker->name, EffectiveAttack_player, monster->name);
                                pause_fight();
                                turno = 0;
                                break;
                            case 2:
                                aux = DisplaySkills(pointer_skill, prop_skill_pointer);
                                if(attacker->mana >= aux->skill_prop_use){
                                    attacker->mana = attacker->mana - pointer_skill->skill_use;
                                    if(attacker->mana <= 0){
                                        attacker->mana = 0;
                                    }
                                    monster->health = monster->health - aux->skill_prop_dmg;
                                    printf("\n%s causou %d de dano com %s a %s...\n", attacker->name, aux->skill_prop_dmg, aux->skill_prop_name, monster->name);
                                    turno = 0;
                                }

                                else{
                                    printf("%s nao tem mana para usar %s\n", attacker->name, aux->skill_prop_name);
                                    turno = 0;
                                }
                                pause_fight();
                                break;
                            case 3:
                                system("cls");
                                DisplayItems(inv_pointer);
                                choosen = ItemOption();
                                switch(choosen){
                                    case 0:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s\n",attacker->name ,aux_inv->current->item_name);
                                        attacker->health = aux_inv->current->health + attacker->health;

                                        if(attacker->health > max_health)
                                            attacker->health = max_health;

                                        printf("%s Recuperou %d.\n", attacker->name, aux_inv->current->health);
                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 1:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s\n",attacker->name ,aux_inv->current->item_name);
                                        attacker->mana = aux_inv->current->mana + attacker->mana;

                                        if(attacker->mana > max_mana)
                                            attacker->mana = max_mana;

                                        printf("%s Recuperou %d.\n", attacker->name, aux_inv->current->mana);
                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 2:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s",attacker->name ,aux_inv->current->item_name);
                                        attacker->health = aux_inv->current->health + attacker->health;
                                        attacker->mana = aux_inv->current->mana + attacker->mana;

                                        if(attacker->health > max_health)
                                            attacker->health = max_health;

                                        if(attacker->mana > max_mana)
                                            attacker->mana = max_mana;

                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 3:
                                        printf("\nBruxos nao podem usar raiva...\n");
                                        pause_fight();
                                        break;
                                    case 4:
                                        printf("\nBruxos nao podem usar combos...\n");
                                        pause_fight();
                                        break;
                                    case 5:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s\n",attacker->name ,aux_inv->current->item_name);
                                        attacker->health = aux_inv->current->health + attacker->health;

                                        if(attacker->health > max_health)
                                            attacker->health = max_health;

                                        printf("%s Recuperou %d.\n", attacker->name, aux_inv->current->health);
                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 6:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s\n",attacker->name ,aux_inv->current->item_name);
                                        attacker->mana = aux_inv->current->mana + attacker->mana;

                                        if(attacker->mana > max_mana)
                                            attacker->mana = max_mana;

                                        printf("%s Recuperou %d.\n", attacker->name, aux_inv->current->mana);
                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 7:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s",attacker->name ,aux_inv->current->item_name);
                                        attacker->attack = aux_inv->current->attack + attacker->attack;

                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 8:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s",attacker->name ,aux_inv->current->item_name);
                                        attacker->health = aux_inv->current->health + attacker->health;
                                        attacker->mana = aux_inv->current->mana + attacker->mana;

                                        if(attacker->health > max_health)
                                            attacker->health = max_health;

                                        if(attacker->mana > max_mana)
                                            attacker->mana = max_mana;

                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 9:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s",attacker->name ,aux_inv->current->item_name);
                                        attacker->defense = aux_inv->current->defense + attacker->defense;

                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    default:
                                        printf("\n >>Saindo do Display<<");
                                        delay_in_fight(1); printf(". ");
                                        delay_in_fight(1); printf(". ");
                                        delay_in_fight(1); printf(".\n");
                                        break;
                                }
                                break;
                            case 4:
                                mini_rng = RNG(2);
                                if(mini_rng == 1) {
                                    printf("**> %s desistiu do combate e esta fugindo...\n", attacker->name);
                                    return attacker;
                                }

                                else if(mini_rng == 0) {
                                    printf("**> %s fracassou a sua fuga",attacker->name); delay_in_fight(1);
                                    turno = 0;
                                }
                                break;
                            default:
                                printf("*>Erro na escolha, tente de novo<*\n");
                                break;
                        }
                        break;
                    case 5:
                        switch (choice){
                            case 1:
                                if(EffectiveAttack_player <= 0 ){
                                    EffectiveAttack_player = 0;
                                }
                                monster->health = monster->health - EffectiveAttack_player;
                                printf("\n%s causou %d de dano a %s...\n", attacker->name, EffectiveAttack_player, monster->name);
                                pause_fight();
                                turno = 0;
                                break;
                            case 2:
                                aux = DisplaySkills(pointer_skill, prop_skill_pointer);
                                if(attacker->mana >= aux->skill_prop_use){
                                    attacker->mana = attacker->mana - pointer_skill->skill_use;
                                    if(attacker->mana <= 0){
                                        attacker->mana = 0;
                                    }
                                    monster->health = monster->health - aux->skill_prop_dmg;
                                    printf("\n%s causou %d de dano com %s a %s...\n", attacker->name, aux->skill_prop_dmg, aux->skill_prop_name, monster->name);
                                    turno = 0;
                                }

                                else{
                                    printf("%s nao tem mana para usar %s\n", attacker->name, aux->skill_prop_name);
                                    turno = 0;
                                }
                                pause_fight();
                                break;
                            case 3:
                                system("cls");
                                DisplayItems(inv_pointer);
                                choosen = ItemOption();
                                switch(choosen){
                                    case 0:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s\n",attacker->name ,aux_inv->current->item_name);
                                        attacker->health = aux_inv->current->health + attacker->health;

                                        if(attacker->health > max_health)
                                            attacker->health = max_health;

                                        printf("%s Recuperou %d.\n", attacker->name, aux_inv->current->health);
                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 1:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s\n",attacker->name ,aux_inv->current->item_name);
                                        attacker->mana = aux_inv->current->mana + attacker->mana;

                                        if(attacker->mana > max_mana)
                                            attacker->mana = max_mana;

                                        printf("%s Recuperou %d.\n", attacker->name, aux_inv->current->mana);
                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 2:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s",attacker->name ,aux_inv->current->item_name);
                                        attacker->health = aux_inv->current->health + attacker->health;
                                        attacker->mana = aux_inv->current->mana + attacker->mana;

                                        if(attacker->health > max_health)
                                            attacker->health = max_health;

                                        if(attacker->mana > max_mana)
                                            attacker->mana = max_mana;

                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 3:
                                        printf("\nPaladinos nao podem usar raiva...\n");
                                        pause_fight();
                                        break;
                                    case 4:
                                        printf("\nPaladinos nao podem usar combos...\n");
                                        pause_fight();
                                        break;
                                    case 5:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s\n",attacker->name ,aux_inv->current->item_name);
                                        attacker->health = aux_inv->current->health + attacker->health;

                                        if(attacker->health > max_health)
                                            attacker->health = max_health;

                                        printf("%s Recuperou %d.\n", attacker->name, aux_inv->current->health);
                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 6:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s\n",attacker->name ,aux_inv->current->item_name);
                                        attacker->mana = aux_inv->current->mana + attacker->mana;

                                        if(attacker->mana > max_mana)
                                            attacker->mana = max_mana;

                                        printf("%s Recuperou %d.\n", attacker->name, aux_inv->current->mana);
                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 7:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s",attacker->name ,aux_inv->current->item_name);
                                        attacker->attack = aux_inv->current->attack + attacker->attack;

                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 8:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s",attacker->name ,aux_inv->current->item_name);
                                        attacker->health = aux_inv->current->health + attacker->health;
                                        attacker->mana = aux_inv->current->mana + attacker->mana;

                                        if(attacker->health > max_health)
                                            attacker->health = max_health;

                                        if(attacker->mana > max_mana)
                                            attacker->mana = max_mana;

                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    case 9:
                                        aux_inv = findItem(choosen, inv_pointer);
                                        printf("\n %s usou %s",attacker->name ,aux_inv->current->item_name);
                                        attacker->defense = aux_inv->current->defense + attacker->defense;

                                        RemoveItem(aux_inv, choosen);
                                        pause_fight();
                                        break;
                                    default:
                                        printf("\n >>Saindo do Display<<");
                                        delay_in_fight(1); printf(". ");
                                        delay_in_fight(1); printf(". ");
                                        delay_in_fight(1); printf(".\n");
                                        break;
                                }
                                break;
                            case 4:
                                mini_rng = RNG(2);
                                if(mini_rng == 1) {
                                    printf("**> %s desistiu do combate e esta fugindo...\n", attacker->name);
                                    return attacker;
                                }

                                else if(mini_rng == 0) {
                                    printf("**> %s fracassou a sua fuga",attacker->name); delay_in_fight(1);
                                    turno = 0;
                                }
                                break;
                            default:
                                printf("*>Erro na escolha, tente de novo<*\n");
                                break;
                        }
                        break;
                }
            }

            else{
                if(EffectiveAttack_monster <= 0){ // Caso o ataque seja negativo e evitar curar o jogador...
                    EffectiveAttack_monster = 0;
                }

                if( rng_attack >= 1) {
                    if(attacker->id_classe == 1) { // aumenta a raiva do guerreiro conforme ele leva dano
                        if (attacker->rage <= 100)
                            attacker->rage = attacker->rage + 4;
                    }

                    if(attacker->id_classe == 2){ // Recupera o combo do vigilante
                        if(attacker->combo < 15 && attacker->combo > 0)
                            attacker->combo = attacker->combo + 2;
                    }

                    attacker->health = attacker->health - EffectiveAttack_monster;
                    printf("\n%s causou %d de dano a %s...\n", monster->name, EffectiveAttack_monster, attacker->name);
                    pause_fight();
                }

                else {
                    srand(time(NULL));
                    int rng_lord = rand()%2;
                    int rng_boss = rand()%5;
                    int rng_lastboss = rand()%6;
                    switch(monster->id_type){
                        case 5:
                            switch(rng_lord){
                                case 0:
                                    attacker->health = attacker->health - EffectiveAttack_monster;
                                    printf("\n%s causou %d de dano a %s...\n", monster->name, EffectiveAttack_monster, attacker->name);
                                    pause_fight();
                                    break;
                                case 1:
                                    if(monster->mana == 45 ){
                                        attacker->health = (attacker->health + attacker->defense) - 120;
                                        printf("\n%s causou %d de dano a %s com Golpe abismal\n", monster->name, ((attacker->health + attacker->defense) - 120), attacker->name);
                                        monster->mana = 0;
                                        pause_fight();
                                    }

                                    else{
                                        attacker->health = attacker->health - EffectiveAttack_monster;
                                        printf("\n%s causou %d de dano a %s...\n", monster->name, EffectiveAttack_monster, attacker->name);
                                        monster->mana = monster->mana + 10;
                                        pause_fight();
                                    }

                                    break;
                                default:
                                    attacker->health = attacker->health - EffectiveAttack_monster;
                                    printf("\n%s causou %d de dano a %s...\n", monster->name, EffectiveAttack_monster, attacker->name);
                                    pause_fight();
                                    break;
                            }
                            break;
                        case 6:
                            switch(rng_boss){
                                case 0:
                                    attacker->health = attacker->health - EffectiveAttack_monster;
                                    printf("\n%s causou %d de dano a %s...\n", monster->name, EffectiveAttack_monster, attacker->name);
                                    pause_fight();
                                    break;
                                case 1:
                                    if(monster->mana >= 45 ){
                                        attacker->health = attacker->health - 80;
                                        printf("\n%s causou %d de dano a %s com Golpe abismal\n", monster->name, (attacker->health - 80), attacker->name);
                                        monster->mana = monster->mana - 45;
                                        pause_fight();
                                    }

                                    else{
                                        attacker->health = attacker->health - EffectiveAttack_monster;
                                        printf("\n%s causou %d de dano a %s...\n", monster->name, EffectiveAttack_monster, attacker->name);
                                        monster->mana = monster->mana + 100;
                                        pause_fight();
                                    }
                                    break;
                                case 2:
                                    if(monster->mana >= 120 ){
                                        attacker->health = attacker->health - 180;
                                        printf("\n%s causou %d de dano a %s com Fogo d'alma obscura\n", monster->name, (attacker->health - 180), attacker->name);
                                        monster->mana = monster->mana - 120;
                                        pause_fight();
                                    }

                                    else{
                                        attacker->health = attacker->health - EffectiveAttack_monster;
                                        printf("\n%s causou %d de dano a %s...\n", monster->name, EffectiveAttack_monster, attacker->name);
                                        monster->mana = monster->mana + 100;
                                        pause_fight();
                                    }
                                    break;
                                case 3:
                                    printf("\n%s passa a vez e recupera %d de mana.\n", monster->name, (monster->mana + 120));
                                    monster->mana = monster->mana + 120;
                                    pause_fight();
                                    break;
                                case 4:
                                    if(monster->mana >= 300 ){
                                        attacker->health = attacker->health - 200;
                                        printf("\n%s causou %d de dano a %s com Aniquilacao\n", monster->name, (attacker->health - 200), attacker->name);
                                        monster->mana = monster->mana - 300;
                                        pause_fight();
                                    }

                                    else{
                                        attacker->health = attacker->health - EffectiveAttack_monster;
                                        printf("\n%s causou %d de dano a %s...\n", monster->name, EffectiveAttack_monster, attacker->name);
                                        pause_fight();
                                    }
                                    break;
                                default:
                                    attacker->health = attacker->health - EffectiveAttack_monster;
                                    printf("\n%s causou %d de dano a %s...\n", monster->name, EffectiveAttack_monster, attacker->name);
                                    monster->mana = monster->mana + 100;
                                    pause_fight();
                                    break;
                            }
                            break;
                        case 7:
                            switch(rng_lastboss){
                                case 0:
                                    attacker->health = attacker->health - EffectiveAttack_monster;
                                    printf("\n%s causou %d de dano a %s...\n", monster->name, EffectiveAttack_monster, attacker->name);
                                    pause_fight();
                                    break;
                                case 1:
                                    if(monster->mana >= 400 ){
                                        attacker->health = attacker->health - 220;
                                        printf("\n%s causou %d de dano a %s com Sussuro Antigo\n", monster->name, (attacker->health - 220), attacker->name);
                                        monster->mana = monster->mana - 220;
                                        pause_fight();
                                    }

                                    else{
                                        attacker->health = attacker->health - EffectiveAttack_monster;
                                        printf("\n%s causou %d de dano a %s...\n", monster->name, EffectiveAttack_monster, attacker->name);
                                        pause_fight();
                                    }
                                    break;
                                case 2:
                                    if(monster->mana == 1080 ){
                                        attacker->health = (attacker->health + attacker->defense) - 400;
                                        printf("\n%s causou %d de dano a %s com Loucura mental\n", monster->name, ((attacker->health + attacker->defense) - 300), attacker->name);
                                        monster->mana = monster->mana - 1080;
                                        pause_fight();
                                    }

                                    else{
                                        attacker->health = attacker->health - EffectiveAttack_monster;
                                        printf("\n%s causou %d de dano a %s...\n", monster->name, EffectiveAttack_monster, attacker->name);
                                        pause_fight();
                                    }
                                    break;
                                case 3:
                                    if(monster->mana >= 180 ){
                                        attacker->health = (attacker->health) - 100 + attacker->defense;
                                        printf("\n%s causou %d de dano a %s com Esmagar\n", monster->name, ((attacker->health) - 100 + attacker->defense), attacker->name);
                                        monster->mana = monster->mana - 180;
                                        pause_fight();
                                    }

                                    else{
                                        attacker->health = attacker->health - EffectiveAttack_monster;
                                        printf("\n%s causou %d de dano a %s...\n", monster->name, EffectiveAttack_monster, attacker->name);
                                        pause_fight();
                                    }
                                    break;
                                case 4:
                                    monster->health = monster->health + 100;
                                    monster->mana = monster->mana + 180;
                                    printf("%s se regenera...", monster->name);
                                    break;
                                case 5:
                                    if(monster->mana >= 600 ){
                                        attacker->health = (attacker->health) - 300 + attacker->defense;
                                        printf("\n%s causou %d de dano a %s com Aniquilacao\n", monster->name, ((attacker->health) - 300 + attacker->defense), attacker->name);
                                        monster->mana = monster->mana - 600;
                                        pause_fight();
                                    }

                                    else{
                                        attacker->health = attacker->health - EffectiveAttack_monster;
                                        printf("\n%s causou %d de dano a %s...\n", monster->name, EffectiveAttack_monster, attacker->name);
                                        pause_fight();
                                    }
                                    break;
                                default:
                                    attacker->health = attacker->health - EffectiveAttack_monster;
                                    printf("\n%s causou %d de dano a %s...\n", monster->name, EffectiveAttack_monster, attacker->name);
                                    pause_fight();
                                    break;
                            }
                            monster->mana = monster->mana + 90;
                            break;
                        default:
                            break;
                    }

                    pause_fight();
                }
                turno = 1;
            }
        }
    }

    if(monster->health <= 0 ){
        printf("\n%s derrotou %s em combate\n", attacker->name, monster->name);
        printf("%s ganhou [%d]XP por ter derrotado %s\n", attacker->name, monster->xp_drop, monster->name);
        attacker->xp_now = monster->xp_drop + attacker->xp_now;
        attacker->gold = attacker->gold + monster->gold_drop;
        printf("\nPressione qualquer tecla para continuar o jogo. ");
        getch();

        return attacker;
    }

    else if(attacker->health <= 0){
        printf("\n%s perceu em combate...", attacker->name);
        attacker->alive = 0;
        printf("\nPressione qualquer tecla para continuar o jogo. ");
        getch();

        return attacker;
    }

}
