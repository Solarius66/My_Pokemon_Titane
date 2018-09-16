/*
** EPITECH PROJECT, 2018
** SCENE_ARENAS_ARENA_4.C
** File description:
** Manages arena_4 scene from arenas scope
*/

#include "declaration.h"

void load_scene_arenas_arena_4(game_t *game)
{
	game->arenas[3].type = ARENA_4;
	game->arenas[3].name = "Rousseau's Arena";
	game->arenas[3].map_file = "maps/arenas/arena_4.map";
}
