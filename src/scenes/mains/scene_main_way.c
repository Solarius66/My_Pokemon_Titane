/*
** EPITECH PROJECT, 2018
** SCENE_MAIN_WAY.C
** File description:
** Manages way scene from main scope
*/

#include "declaration.h"

void load_scene_main_way(game_t *game)
{
	game->mains[2].type = WAY;
	game->mains[2].name = "Way";
	game->mains[2].map_file = "maps/mains/way.map";
}
