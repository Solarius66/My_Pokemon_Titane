/*
** EPITECH PROJECT, 2018
** SCENE_MAIN_BOAT.C
** File description:
** Manages boat scene from main scope
*/

#include "declaration.h"

void load_scene_main_boat(game_t *game)
{
	game->mains[3].type = BOAT;
	game->mains[3].name = "Boat";
	game->mains[3].map_file = "maps/mains/boat.map";
}
