//
// Created by ratob on 29/05/2019.
//

#include "headers/mobsSkill.h"

skill_monster* CreateMonsterPointer(){
    skill_monster *pointer_monster_skill = (skill_monster*)malloc(sizeof(skill_monster));
    pointer_monster_skill->proximo = NULL;
    return pointer_monster_skill;
}


skill_monster* CreateMonsterSkill(int id_type, skill_monster *pointer_monster_skill){
    skill_monster *node = (skill_monster*)malloc(sizeof(skill_monster));
    node = pointer_monster_skill;
    switch (id_type){
        case 1:
            pointer_monster_skill = NULL;
            break;
        case 2:
            node->skill_dmg = 16;
            strcpy(node->skill_name, "Ruptura");
            node->skill_use = 4;
            node->skill_id = 1;
            node->proximo = pointer_monster_skill->proximo;
            pointer_monster_skill = node;
            break;
        case 3:
            node->skill_dmg = 36;
            strcpy(node->skill_name, "Imolacao");
            node->skill_use = 30;
            node->skill_id = 1;
            node->proximo = pointer_monster_skill->proximo;
            pointer_monster_skill = node;
            break;
        case 4:
            node->skill_dmg = 80;
            strcpy(node->skill_name, "Lança das sombras");
            node->skill_use = 60;
            node->skill_id = 1;
            node->proximo = pointer_monster_skill->proximo;
            pointer_monster_skill = node;
            break;
        case 5:
            node->skill_dmg = 120;
            strcpy(node->skill_name, "Fervor de sangue");
            node->skill_use = 45;
            node->skill_id = 1;
            node->proximo = pointer_monster_skill->proximo;
            pointer_monster_skill = node;
            break;
        case 6:
            node->skill_dmg = 200;
            strcpy(node->skill_name, "Impacto mental");
            node->skill_use = 300;
            node->skill_id = 1;
            node->proximo = pointer_monster_skill->proximo;
            pointer_monster_skill = node;
            break;
        case 7:
            node->skill_dmg = 100;
            strcpy(node->skill_name, "Bola de Fogovill");
            node->skill_use = 30;
            node->skill_id = 1;
            node->proximo = pointer_monster_skill->proximo;
            pointer_monster_skill = node;
            break;
        default:
            printf("ERROR - na geracao de skill do monstro");
            break;
    }

}

skill_monster* addSkillMonster(int id_type, skill_monster *pointer_monster_skill, char name[15], int dmg , int skill_use, int skill_id) {
    skill_monster *node = (skill_monster*)malloc(sizeof(skill_monster));
    switch (id_type){
        case 1:

            break;
        case 2:
            node->skill_dmg = dmg;
            strcpy(node->skill_name, name);
            node->skill_use = skill_use;
            node->skill_id = skill_id;
            node->proximo = NULL;
            break;
        case 3:
            node->skill_dmg = dmg;
            strcpy(node->skill_name, name);
            node->skill_use = skill_use;
            node->skill_id = skill_id;
            node->proximo = NULL;
            break;
        case 4:
            node->skill_dmg = dmg;
            strcpy(node->skill_name, name);
            node->skill_use = skill_use;
            node->skill_id = skill_id;
            node->proximo = NULL;
            break;
        case 5:
            node->skill_dmg = dmg;
            strcpy(node->skill_name, name);
            node->skill_use = skill_use;
            node->skill_id = skill_id;
            node->proximo = NULL;
            break;
        case 6:
            node->skill_dmg = dmg;
            strcpy(node->skill_name, name);
            node->skill_use = skill_use;
            node->skill_id = skill_id;
            node->proximo = NULL;
            break;
        case 7:
            node->skill_dmg = dmg;
            strcpy(node->skill_name, name);
            node->skill_use = skill_use;
            node->skill_id = skill_id;
            node->proximo = NULL;
            break;
        default:
            printf("\n --ERROR AO ADICIONAR HABILIDADE DO MONSTRO-- \n");
            break;
    }

    if(pointer_monster_skill == NULL){
        pointer_monster_skill = node;
    }

    else {
        while (pointer_monster_skill->proximo != NULL) {
            pointer_monster_skill = pointer_monster_skill->proximo;
        }
        pointer_monster_skill->proximo = node;
    }
}
