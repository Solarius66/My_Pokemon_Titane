/*
** EPITECH PROJECT, 2018
** SCENE_ARENAS_ARENA_2.C
** File description:
** Manages arena_2 scene from arenas scope
*/

#include "declaration.h"

void load_scene_arenas_arena_2(game_t *game)
{
	game->arenas[1].type = ARENA_2;
	game->arenas[1].name = "Anglade's Arena";
	game->arenas[1].map_file = "maps/arenas/arena_2.map";
}
