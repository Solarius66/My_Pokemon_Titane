/*
** EPITECH PROJECT, 2018
** SCENE_ARENAS_ARENA_3.C
** File description:
** Manages arena_3 scene from arenas scope
*/

#include "declaration.h"

void load_scene_arenas_arena_3(game_t *game)
{
	game->arenas[2].type = ARENA_3;
	game->arenas[2].name = "Perez's Arena";
	game->arenas[2].map_file = "maps/arenas/arena_3.map";
}
