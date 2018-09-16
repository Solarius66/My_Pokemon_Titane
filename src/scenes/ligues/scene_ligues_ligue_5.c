/*
** EPITECH PROJECT, 2018
** SCENE_LIGUES_LIGUE_5
** File description:
** Manages ligue_5 scene from ligues scope
*/

#include "declaration.h"

void load_scene_ligues_ligue_5(game_t *game)
{
	game->ligues[4].type = LIGUE_5;
	game->ligues[4].name = "Council 4 : Théo";
	game->ligues[4].map_file = "maps/ligues/ligue_5.map";
}
