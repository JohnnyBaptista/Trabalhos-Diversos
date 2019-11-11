cmake_minimum_required(VERSION 3.14)
project(TEXT_RPG_ADVENTURE C)

set(CMAKE_C_STANDARD 11)

add_executable(TEXT_RPG_ADVENTURE main.c game.c headers/game.h delay.h player.c headers/player.h headers/fightSystem.h skill.c headers/skill.h mobs.c headers/mobs.h headers/mobs_name.h fightSystem.c inventory.c headers/inventory.h mobsSkill.c headers/mobsSkill.h headers/lore.h dungeon_tutorial.c headers/dungeon_tutorial.h puzzle_stack.c headers/puzzle_stack.h game_functions.h)