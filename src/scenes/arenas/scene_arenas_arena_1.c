/*
** EPITECH PROJECT, 2018
** SCENE_ARENAS_ARENA_1.C
** File description:
** Manages arena_1 scene from arenas scope
*/

#include "declaration.h"

void load_scene_arenas_arena_1(game_t *game)
{
	game->arenas[0].type = ARENA_1;
	game->arenas[0].name = "Robin's Arena";
	game->arenas[0].map_file = "maps/arenas/arena_1.map";
}
