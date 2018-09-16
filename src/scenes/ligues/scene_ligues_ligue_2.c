/*
** EPITECH PROJECT, 2018
** SCENE_LIGUES_LIGUE_2
** File description:
** Manages ligue_2 scene from ligues scope
*/

#include "declaration.h"

void load_scene_ligues_ligue_2(game_t *game)
{
	game->ligues[1].type = LIGUE_2;
	game->ligues[1].name = "Council 4 : Gildas";
	game->ligues[1].map_file = "maps/ligues/ligue_2.map";
}
