/*
** EPITECH PROJECT, 2018
** SCENES_ARENAS_ARENA_5.C
** File description:
** Manages arena_5 scene from arenas scope
*/

#include "declaration.h"

void load_scene_arenas_arena_5(game_t *game)
{
	game->arenas[4].type = ARENA_5;
	game->arenas[4].name = "Chicha's Arena";
	game->arenas[4].map_file = "maps/arenas/arena_5.map";
}
