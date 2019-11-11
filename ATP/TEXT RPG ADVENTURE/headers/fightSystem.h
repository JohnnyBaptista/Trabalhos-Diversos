//
// Created by ratob on 23/05/2019.
//

#ifndef TEXT_RPG_ADVENTURE_FIGHTSYSTEM_H
#define TEXT_RPG_ADVENTURE_FIGHTSYSTEM_H


#include "skill.h"
#include "mobsSkill.h"

void pause_fight();
void delay_in_fight(int number_of_seconds);

int DisplayFightMenu (int choice);
int ItemOption();
skill_prop* DisplaySkills(skill *pointer_skill, skill_prop *prop_skill_pointer);
player* Fight(player* attacker, mobs* monster, skill *pointer_skill, skill_prop *prop_skill_pointer,inventory *inv_pointer);

#endif //TEXT_RPG_ADVENTURE_FIGHTSYSTEM_H
