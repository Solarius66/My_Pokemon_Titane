/*
** EPITECH PROJECT, 2018
** SCENE_MAIN_BATTLE.C
** File description:
** Manages battle scene from main scope
*/

#include "declaration.h"

void load_scene_main_battle(game_t *game)
{
	game->mains[1].type = BATTLE;
	game->mains[1].name = "Battle";
	game->mains[1].map_file = "maps/mains/battle.map";
}
