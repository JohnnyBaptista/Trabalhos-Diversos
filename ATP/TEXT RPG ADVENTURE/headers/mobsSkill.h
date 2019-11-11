//
// Created by ratob on 29/05/2019.
//

#ifndef TEXT_RPG_ADVENTURE_MOBSSKILL_H
#define TEXT_RPG_ADVENTURE_MOBSSKILL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct monsterSkillStructure{
    char skill_name[15];
    int skill_use;
    int skill_dmg;
    int skill_id;
    struct monsterSkillStructure *proximo;
}skill_monster;

skill_monster* CreateMonsterPointer();
skill_monster* CreateMonsterSkill(int id_type, skill_monster *pointer_skill);
skill_monster* addSkillMonster(int id_type, skill_monster *pointer_monster_skill, char name[15], int dmg , int skill_use, int skill_id);

#endif //TEXT_RPG_ADVENTURE_MOBSSKILL_H
