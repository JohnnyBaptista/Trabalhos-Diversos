//
// Created by ratob on 23/05/2019.
//

#ifndef TEXT_RPG_ADVENTURE_SKILL_H
#define TEXT_RPG_ADVENTURE_SKILL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct skillStructure{
    char skill_name[25];
    char skill_description[100];
    int skill_use;
    int skill_dmg;
    int skill_id;
    struct skillStructure *proximo;
}skill;

typedef struct skillProprieties{
    char skill_prop_name[25];
    char skill_prop_description[100];
    int skill_prop_use;
    int skill_prop_dmg;
    int skill_prop_id;
}skill_prop;

player* level_up(player *target);
player *level_up_save(player *target);

skill* CreatePointer();
skill* CreateHeroSkill(int id_classe, skill *pointer_skill);
skill* skills_add(player *hero, skill *pointer_skill);




#endif //TEXT_RPG_ADVENTURE_SKILL_H
