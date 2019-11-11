//
// Created by ratob on 23/05/2019.
//


#include "headers/player.h"
#include "headers/skill.h"

player *level_up_save(player *target) {
    int xp_before = target->xp_total;
    if (target->xp_now >= target->xp_total) {
        switch (target->id_classe) {
            case 1:
                target->health = target->max_health + 35;
                target->max_health = target->health;
                target->rage = target->rage;
                target->agility = target->agility + 5;
                target->attack = target->attack + 7;
                target->defense = target->defense + 5;
                target->level = target->level + 1;
                target->xp_now = target->xp_now - target->xp_total;
                target->xp_total = 2 * target->xp_total;
                break;
            case 2:
                target->health = target->max_health + 30;
                target->max_health = target->health;
                target->combo = 15;
                target->agility = target->agility + 5;
                target->attack = target->attack + 5;
                target->defense = target->defense + 5;
                target->level = target->level + 1;
                target->xp_now = target->xp_now - target->xp_total;
                target->xp_total = 2 * target->xp_total;
                break;
            case 3:
                target->health = target->max_health + 20;
                target->max_health = target->health;
                target->mana = target->mana + 20;
                target->max_mana = target->max_mana;
                target->agility = target->agility + 3;
                target->attack = target->attack + 4;
                target->defense = target->defense + 3;
                target->level = target->level + 1;
                target->xp_now = target->xp_now - target->xp_total;
                target->xp_total = 2 * target->xp_total;
                break;
            case 4:
                target->health = target->max_health + 25;
                target->max_health = target->health;
                target->mana = target->mana + 15;
                target->max_mana = target->max_mana;
                target->agility = target->agility + 4;
                target->attack = target->attack + 5;
                target->defense = target->defense + 4;
                target->level = target->level + 1;
                target->xp_now = target->xp_now - target->xp_total;
                target->xp_total = 2 * target->xp_total;
                break;
            case 5:
                target->health = target->max_health + 31;
                target->max_health = target->health;
                target->mana = target->mana + 18;
                target->max_mana = target->max_mana;
                target->agility = target->agility + 6;
                target->attack = target->attack + 7;
                target->defense = target->defense + 9;
                target->level = target->level + 1;
                target->xp_now = target->xp_now - target->xp_total;
                target->xp_total = 2 * target->xp_total;
                break;
            default:
                target->health = target->max_health + 25;
                target->max_health = target->health;
                target->mana = target->mana + 15;
                target->agility = target->agility + 4;
                target->attack = target->attack + 5;
                target->defense = target->defense + 4;
                target->level = target->level + 1;
                target->xp_now = target->xp_now - target->xp_total;
                target->xp_total = 2 * target->xp_total;
                break;
        }
    }
    return target;
}

player *level_up(player *target) {
    int xp_before = target->xp_total;
    if (target->xp_now >= target->xp_total) {
        switch (target->id_classe) {
            case 1:
                target->health = target->max_health + 35;
                target->max_health = target->health;
                target->rage = target->rage;
                target->agility = target->agility + 5;
                target->attack = target->attack + 7;
                target->defense = target->defense + 5;
                target->level = target->level + 1;
                target->xp_now = target->xp_now - target->xp_total;
                target->xp_total = 2 * target->xp_total;
                break;
            case 2:
                target->health = target->max_health + 30;
                target->max_health = target->health;
                target->combo = 15;
                target->agility = target->agility + 5;
                target->attack = target->attack + 5;
                target->defense = target->defense + 5;
                target->level = target->level + 1;
                target->xp_now = target->xp_now - target->xp_total;
                target->xp_total = 2 * target->xp_total;
                break;
            case 3:
                target->health = target->max_health + 20;
                target->max_health = target->health;
                target->mana = target->mana + 20;
                target->max_mana = target->max_mana;
                target->agility = target->agility + 3;
                target->attack = target->attack + 4;
                target->defense = target->defense + 3;
                target->level = target->level + 1;
                target->xp_now = target->xp_now - target->xp_total;
                target->xp_total = 2 * target->xp_total;
                break;
            case 4:
                target->health = target->max_health + 25;
                target->max_health = target->health;
                target->mana = target->mana + 15;
                target->max_mana = target->max_mana;
                target->agility = target->agility + 4;
                target->attack = target->attack + 5;
                target->defense = target->defense + 4;
                target->level = target->level + 1;
                target->xp_now = target->xp_now - target->xp_total;
                target->xp_total = 2 * target->xp_total;
                break;
            case 5:
                target->health = target->max_health + 31;
                target->max_health = target->health;
                target->mana = target->mana + 18;
                target->max_mana = target->max_mana;
                target->agility = target->agility + 6;
                target->attack = target->attack + 7;
                target->defense = target->defense + 9;
                target->level = target->level + 1;
                target->xp_now = target->xp_now - target->xp_total;
                target->xp_total = 2 * target->xp_total;
                break;
            default:
                target->health = target->max_health + 25;
                target->max_health = target->health;
                target->mana = target->mana + 15;
                target->agility = target->agility + 4;
                target->attack = target->attack + 5;
                target->defense = target->defense + 4;
                target->level = target->level + 1;
                target->xp_now = target->xp_now - target->xp_total;
                target->xp_total = 2 * target->xp_total;
                break;
        }

        system("cls");
        printf("%s subiu de nivel!!, status aumentado:\n\n",target->name);
        switch(target->id_classe){
            case 1:
                printf("Vida: %d para %d\n",(target->health - 35),target->health);
                printf("Raiva: %d para %d\n",(target->rage), target->rage);
                printf("Agilidade: %d para %d\n",(target->agility - 5), target->agility);
                printf("Poder de ataque: %d para %d\n",(target->attack - 7), target->attack);
                printf("Defesa: %d para %d\n",(target->defense - 5), target->defense);
                printf("Level: %d para %d\n",(target->level - 1), target->level);
                printf("XP: %d para %d/%d\n",(xp_before), target->xp_now,target->xp_total);
                break;
            case 2:
                printf("Vida: %d para %d\n",(target->health - 30), target->health);
                printf("Combo: %d para %d\n",(target->combo) ,target->combo);
                printf("Agilidade: %d para %d\n",(target->agility - 5), target->agility);
                printf("Poder de ataque: %d para %d\n",(target->attack - 5), target->attack);
                printf("Defesa: %d para %d\n",(target->defense - 5), target->defense);
                printf("Level: %d para %d\n",(target->level - 1), target->level);
                printf("XP: %d para %d/%d\n",(xp_before), target->xp_now,target->xp_total);
                break;
            case 3:
                printf("Vida: %d para %d\n",(target->health - 20), target->health);
                printf("Mana: %d para %d\n",(target->mana - 20), target->mana);
                printf("Agilidade: %d para %d\n",(target->agility - 3), target->agility);
                printf("Poder de ataque: %d para %d\n",(target->attack - 4), target->attack);
                printf("Defesa: %d para %d\n",(target->defense - 3), target->defense);
                printf("Level: %d para %d\n",(target->level - 1), target->level);
                printf("XP: %d para %d/%d\n",(xp_before), target->xp_now,target->xp_total);
                break;
            case 4:
                printf("Vida: %d para %d\n",(target->health - 25), target->health);
                printf("Mana: %d para %d\n",(target->mana - 15), target->mana);
                printf("Agilidade: %d para %d\n",(target->agility - 4), target->agility);
                printf("Poder de ataque: %d para %d\n",(target->attack - 5), target->attack);
                printf("Defesa: %d para %d\n",(target->defense - 4), target->defense);
                printf("Level: %d para %d\n",(target->level - 1), target->level);
                printf("XP: %d para %d/%d\n",(xp_before), target->xp_now,target->xp_total);
                break;
            case 5:
                printf("Vida: %d para %d\n",(target->health - 31), target->health);
                printf("Mana: %d para %d\n",(target->mana - 18), target->mana);
                printf("Agilidade: %d para %d\n",(target->agility - 6), target->agility);
                printf("Poder de ataque: %d para %d\n",(target->attack - 6), target->attack);
                printf("Defesa: %d para %d\n",(target->defense - 9), target->defense);
                printf("Level: %d para %d\n",(target->level - 1), target->level);
                printf("XP: %d para %d/%d\n",(xp_before), target->xp_now,target->xp_total);
                break;
            default:
                printf("\n ERRO AO MONSTRAR O LEVEL UP\n");
                break;
        }
        printf("\n\n");
    }
    system("pause");

    return target;
}

skill *CreatePointer() {
    skill *pointer_skill = (skill *) malloc(sizeof(skill));
    pointer_skill->proximo = NULL;
    return pointer_skill;
}


skill *CreateHeroSkill(int id_classe, skill *pointer_skill) {
    skill *node = pointer_skill;
    switch (id_classe) {
        case 1:
            node->skill_dmg = 16;
            strcpy(node->skill_name, "Rasgar");
            strcpy(node->skill_description, "Um ataque preciso na vertical que resga o inimigo");
            node->skill_use = 12;
            node->skill_id = 1;
            break;
        case 2:
            node->skill_dmg = 12;
            strcpy(node->skill_name, "Golpe Sinistro");
            strcpy(node->skill_description, "uma pancada certeira no inimigo.");
            node->skill_use = 3;
            node->skill_id = 1;
            break;
        case 3:
            node->skill_dmg = 24;
            strcpy(node->skill_name, "Bola de fogo");
            strcpy(node->skill_description, "Uma bola de fogo mortal que pode ser arremessada.");
            node->skill_use = 20;
            node->skill_id = 1;
            break;
        case 4:
            node->skill_dmg = 20;
            strcpy(node->skill_name, "Conflagracao");
            strcpy(node->skill_description, "Cria uma combustao explosiva dentro de seu adversario.");
            node->skill_use = 15;
            node->skill_id = 1;
            break;
        case 5:
            node->skill_dmg = 20;
            strcpy(node->skill_name, "Julgamento");
            strcpy(node->skill_description, "Realiza um golpe de luz no seu oponente baseado nos seus pecados");
            node->skill_use = 10;
            node->skill_id = 1;
            break;
        default:
            printf("ERROR - na geracao de skill");
            break;
    }
}

skill *skills_add(player *hero, skill *pointer_skill) {
    skill *new_node = (skill *) malloc(sizeof(skill));
    switch (hero->id_classe) {
        case 1:
            switch (hero->level) {
                case 1:
                    new_node->skill_dmg = hero->attack + 10;
                    strcpy(new_node->skill_name, "Golpe de Heroi");
                    strcpy(new_node->skill_description, "Usando toda sua forca, um ataque mortal eh realizado.");
                    new_node->skill_use = 20;
                    new_node->skill_id = 2;
                    new_node->proximo = NULL;
                    break;
                case 2:
                    new_node->skill_dmg = hero->attack + hero->rage;
                    strcpy(new_node->skill_name, "Subjulgar");
                    strcpy(new_node->skill_description,
                           "Um ataque que o guerreiro canaliza sua raiva \n para o ataque (Poder de ataque + total de raiva).");
                    new_node->skill_use = 15;
                    new_node->skill_id = 3;
                    new_node->proximo = NULL;
                    break;
                case 3:
                    new_node->skill_dmg = hero->attack + hero->rage + hero->defense;
                    strcpy(new_node->skill_name, "Executar");
                    strcpy(new_node->skill_description, "Um ataque brutal que causa um dano macico.");
                    new_node->skill_use = 45;
                    new_node->skill_id = 4;
                    new_node->proximo = NULL;
                    break;
                case 4:
                    new_node->skill_dmg = 10 + hero->defense;
                    strcpy(new_node->skill_name, "Vinganca");
                    strcpy(new_node->skill_description,
                           "O guerreiro toma uma instancia defensiva e realiza uma ataque feroz \n (Defesa + 10 de dano).");
                    new_node->skill_use = 10;
                    new_node->skill_id = 5;
                    new_node->proximo = NULL;
                    break;
                case 5:
                    new_node->skill_dmg = hero->attack + 100;
                    strcpy(new_node->skill_name, "Porrada");
                    strcpy(new_node->skill_description,
                           "Uma porrada precisa na cabeca do oponente com dano devastador.");
                    new_node->skill_use = 55;
                    new_node->skill_id = 6;
                    new_node->proximo = NULL;
                    break;
                case 6:
                    new_node->skill_dmg = hero->attack + hero->rage * 2;
                    strcpy(new_node->skill_name, "Rachar");
                    strcpy(new_node->skill_description, "Ataque duplo que causa dobro de dano da raiva.");
                    new_node->skill_use = 45;
                    new_node->skill_id = 7;
                    new_node->proximo = NULL;
                    break;
                case 7:
                    new_node->skill_dmg = hero->attack + hero->rage * 10;
                    strcpy(new_node->skill_name, "Enfurecer");
                    strcpy(new_node->skill_description,
                           "Guerreiro causa uma grande quantidade de ataques, gerando dano alto.");
                    new_node->skill_use = 80;
                    new_node->skill_id = 8;
                    new_node->proximo = NULL;
                    break;
                case 8:
                    new_node->skill_dmg = hero->attack + hero->rage + 200;
                    strcpy(new_node->skill_name, "Empunhalada");
                    strcpy(new_node->skill_description, "Guerreiro concentra todo sua forca num ataque absoluto.");
                    new_node->skill_use = 50;
                    new_node->skill_id = 9;
                    new_node->proximo = NULL;
                    break;
                default:
                    break;
            }
            break;
        case 2:
            switch (hero->level) {
                case 1:
                    new_node->skill_dmg = hero->combo + 10;
                    strcpy(new_node->skill_name, "Eviscerar");
                    strcpy(new_node->skill_description, "Um ataque que abre uma ferida forte em seu oponente.");
                    new_node->skill_use = 3;
                    new_node->skill_id = 2;
                    new_node->proximo = NULL;
                    break;
                case 2:
                    new_node->skill_dmg = hero->combo + 25;
                    strcpy(new_node->skill_name, "Empunhalar");
                    strcpy(new_node->skill_description, "Um ataque letal nas costas do oponente.");
                    new_node->skill_use = 10;
                    new_node->skill_id = 3;
                    new_node->proximo = NULL;
                    break;
                case 3:
                    new_node->skill_dmg = hero->combo + 35;
                    strcpy(new_node->skill_name, "Arrancar");
                    strcpy(new_node->skill_description, "Um ataque letal e preciso no peitoral do oponente.");
                    new_node->skill_use = 6;
                    new_node->skill_id = 4;
                    new_node->proximo = NULL;
                    break;
                case 4:
                    new_node->skill_dmg = hero->combo + 60;
                    strcpy(new_node->skill_name, "Jogar adaga");
                    strcpy(new_node->skill_description, "O vigilante joga precisamente uma adaga em seu oponente.");
                    new_node->skill_use = 5;
                    new_node->skill_id = 5;
                    new_node->proximo = NULL;
                    break;
                case 5:
                    new_node->skill_dmg = hero->combo + 25 * hero->combo;
                    strcpy(new_node->skill_name, "Ruptura");
                    strcpy(new_node->skill_description,
                           "Um ataque finalizador que causa uma quantidade de dano baseado na quantidade de combo.");
                    new_node->skill_use = 12;
                    new_node->skill_id = 6;
                    new_node->proximo = NULL;
                    break;
                case 6:
                    new_node->skill_dmg = hero->combo + 80;
                    strcpy(new_node->skill_name, "Porrada letal");
                    strcpy(new_node->skill_description, "Um soco preciso nos orgaos vitais do oponente.");
                    new_node->skill_use = 8;
                    new_node->skill_id = 7;
                    new_node->proximo = NULL;
                    break;
                case 7:
                    new_node->skill_dmg = hero->attack + hero->combo * 12;
                    strcpy(new_node->skill_name, "Ataque exposto");
                    strcpy(new_node->skill_description, "Realiza um ataque no inimigo pelas sombras.");
                    new_node->skill_use = 10;
                    new_node->skill_id = 8;
                    new_node->proximo = NULL;
                    break;
                case 8:
                    new_node->skill_dmg = hero->combo * 10 + 5 * (hero->attack - hero->combo);
                    strcpy(new_node->skill_name, "Furia das laminas");
                    strcpy(new_node->skill_description, "Usa suas armas para um ataque devastador.");
                    new_node->skill_use = 15;
                    new_node->skill_id = 9;
                    new_node->proximo = NULL;
                    break;
                default:
                    break;
            }
            break;
        case 3:
            switch (hero->level) {
                case 1:
                    new_node->skill_dmg = 20;
                    strcpy(new_node->skill_name, "Explosao de fogo");
                    strcpy(new_node->skill_description, "Uma pequena explosao causada em seu oponente.");
                    new_node->skill_use = 15;
                    new_node->skill_id = 2;
                    new_node->proximo = NULL;
                    break;
                case 2:
                    new_node->skill_dmg = 40;
                    strcpy(new_node->skill_name, "Nova de Gelo");
                    strcpy(new_node->skill_description, "Um ataque em rasteiro de gelo causando aos oponentes.");
                    new_node->skill_use = 30;
                    new_node->skill_id = 3;
                    new_node->proximo = NULL;
                    break;
                case 3:
                    new_node->skill_dmg = 80;
                    strcpy(new_node->skill_name, "Lanca de Gelo");
                    strcpy(new_node->skill_description, "O mago de gelo joga uma lanca de gelo em seu opoenente.");
                    new_node->skill_use = 25;
                    new_node->skill_id = 4;
                    new_node->proximo = NULL;
                    break;
                case 4:
                    new_node->skill_dmg = 130;
                    strcpy(new_node->skill_name, "Explosao Arcana");
                    strcpy(new_node->skill_description, "Cria uma explosao arcana em seu oponente dando muito dano.");
                    new_node->skill_use = 80;
                    new_node->skill_id = 5;
                    new_node->proximo = NULL;
                    break;
                case 5:
                    new_node->skill_dmg = 200;
                    strcpy(new_node->skill_name, "Raio arcano");
                    strcpy(new_node->skill_description,
                           "Convoca um raio arcano das maos do mago e joga no seu oponente.");
                    new_node->skill_use = 90;
                    new_node->skill_id = 6;
                    new_node->proximo = NULL;
                    break;
                case 6:
                    new_node->skill_dmg = 220;
                    strcpy(new_node->skill_name, "Queimar");
                    strcpy(new_node->skill_description, "Cria e joga uma onda de chamas em seu oponente.");
                    new_node->skill_use = 120;
                    new_node->skill_id = 7;
                    new_node->proximo = NULL;
                    break;
                case 7:
                    new_node->skill_dmg = 300;
                    strcpy(new_node->skill_name, "Explosao");
                    strcpy(new_node->skill_description, "Uma pequena explosao causada em seu oponente.");
                    new_node->skill_use = 15;
                    new_node->skill_id = 8;
                    new_node->proximo = NULL;
                    break;
                case 8:
                    new_node->skill_dmg = 1200;
                    strcpy(new_node->skill_name, "Ignimpacto");
                    strcpy(new_node->skill_description,
                           "O mago canalisa toda sua mana para realizar um ataque com uma bola de fogo gigantesca.");
                    new_node->skill_use = hero->max_mana;
                    new_node->skill_id = 9;
                    new_node->proximo = NULL;
                    break;
                default:
                    break;
            }
            break;
        case 4:
            switch (hero->level) {
                case 1:
                    new_node->skill_dmg = 18;
                    strcpy(new_node->skill_name, "Maldicao de sangue");
                    strcpy(new_node->skill_description, "Amaldicoa seu adversario e causa dano.");
                    new_node->skill_use = 20;
                    new_node->skill_id = 2;
                    new_node->proximo = NULL;
                    break;
                case 2:
                    new_node->skill_dmg = 30;
                    strcpy(new_node->skill_name, "Calcinar");
                    strcpy(new_node->skill_description, "Usa fogo vill para queimar seu oponente.");
                    new_node->skill_use = 10;
                    new_node->skill_id = 3;
                    new_node->proximo = NULL;
                    break;
                case 3:
                    new_node->skill_dmg = 100;
                    strcpy(new_node->skill_name, "Lanca Sombria");
                    strcpy(new_node->skill_description, "Joga uma sombra feita de magia negra em seu oponente.");
                    new_node->skill_use = 35;
                    new_node->skill_id = 4;
                    new_node->proximo = NULL;
                    break;
                case 4:
                    new_node->skill_dmg = 60 + hero->health;
                    strcpy(new_node->skill_name, "Sacrificio de Sangue");
                    strcpy(new_node->skill_description,
                           "O bruxo usa o sangue que perdeu em combate como sacrificio\n e usa um ataque psiquico no oponente.");
                    new_node->skill_use = 40;
                    new_node->skill_id = 5;
                    new_node->proximo = NULL;
                    break;
                case 5:
                    new_node->skill_dmg = 90;
                    strcpy(new_node->skill_name, "Imolacao");
                    strcpy(new_node->skill_description,
                           "Um rastro de fogo verde sai do chao seguindo seu oponente, ao alcansa-lo realiza uma explocao");
                    new_node->skill_use = 30;
                    new_node->skill_id = 6;
                    new_node->proximo = NULL;
                    break;
                case 6:
                    new_node->skill_dmg = 500;
                    strcpy(new_node->skill_name, "Fogo infernal");
                    strcpy(new_node->skill_description, "Invoca fogo vill no seu oponente queimando-o.");
                    new_node->skill_use = 20 + hero->health;
                    new_node->skill_id = 7;
                    new_node->proximo = NULL;
                    break;
                case 7:
                    new_node->skill_dmg = 280;
                    strcpy(new_node->skill_name, "Alma negra");
                    strcpy(new_node->skill_description,
                           "A alma do bruxo eh imbuida com poder negro, logo em seguida ele joga uma alma negra.");
                    new_node->skill_use = 120;
                    new_node->skill_id = 8;
                    new_node->proximo = NULL;
                    break;
                case 8:
                    new_node->skill_dmg = 1800;
                    strcpy(new_node->skill_name, "Fogo d'Alma");
                    strcpy(new_node->skill_description, "Queima a alma do inimigo com fogo vill.");
                    new_node->skill_use = 170;
                    new_node->skill_id = 9;
                    new_node->proximo = NULL;
                    break;
                default:
                    break;
            }
            break;
        case 5:
            switch (hero->level) {
                case 1:
                    new_node->skill_dmg = 20;
                    strcpy(new_node->skill_name, "Punicao Sagrada");
                    strcpy(new_node->skill_description, "Abencoa sua arma, realiza um ataque punindo seu adversario");
                    new_node->skill_use = 11;
                    new_node->skill_id = 2;
                    new_node->proximo = NULL;
                    break;
                case 2:
                    new_node->skill_dmg = 45;
                    strcpy(new_node->skill_name, "Consagracao");
                    strcpy(new_node->skill_description, "Invoca um raio de luz no seu oponente");
                    new_node->skill_use = 20;
                    new_node->skill_id = 3;
                    new_node->proximo = NULL;
                    break;
                case 3:
                    new_node->skill_dmg = 100;
                    strcpy(new_node->skill_name, "Lanca da justica");
                    strcpy(new_node->skill_description, "Joga uma lanca de luz no seu oponente");
                    new_node->skill_use = 35;
                    new_node->skill_id = 4;
                    new_node->proximo = NULL;
                    break;
                case 4:
                    new_node->skill_dmg = 70 + hero->health;
                    strcpy(new_node->skill_name, "Escudada");
                    strcpy(new_node->skill_description,
                           "O paladino joga um escudo de luz para causar dano aos seus oponentes.");
                    new_node->skill_use = 40;
                    new_node->skill_id = 5;
                    new_node->proximo = NULL;
                    break;
                case 5:
                    new_node->skill_dmg = 100;
                    strcpy(new_node->skill_name, "Selo do Cruzado");
                    strcpy(new_node->skill_description,
                           "O paladino invoca um selo sagrado no seu oponente realizando dano");
                    new_node->skill_use = 30;
                    new_node->skill_id = 6;
                    new_node->proximo = NULL;
                    break;
                case 6:
                    new_node->skill_dmg = 350;
                    strcpy(new_node->skill_name, "Selo da justicar");
                    strcpy(new_node->skill_description,
                           "O paladino reza brevemente para deusa da Justica e realiza um ataque forte");
                    new_node->skill_use = 90;
                    new_node->skill_id = 7;
                    new_node->proximo = NULL;
                    break;
                case 7:
                    new_node->skill_dmg = 400;
                    strcpy(new_node->skill_name, "Martelo da Justica");
                    strcpy(new_node->skill_description, "Joga um martelo de luz nos seus oponentes");
                    new_node->skill_use = 120;
                    new_node->skill_id = 8;
                    new_node->proximo = NULL;
                    break;
                case 8:
                    new_node->skill_dmg = hero->max_mana + hero->health + 200;
                    strcpy(new_node->skill_name, "Purificar");
                    strcpy(new_node->skill_description, "Queima a alma do inimigo com a luz sagrada, purificando-o");
                    new_node->skill_use = hero->max_mana;
                    new_node->skill_id = 9;
                    new_node->proximo = NULL;
                    break;
                default:
                    break;
            }
    }
    if(hero->level <=8){
        if(pointer_skill == NULL){
            pointer_skill = new_node;
        }

        else{
            while( pointer_skill->proximo != NULL){
                pointer_skill = pointer_skill->proximo;
            }
            pointer_skill->proximo = new_node;
        }
    }
}


