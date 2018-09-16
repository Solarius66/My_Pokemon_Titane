/*
** EPITECH PROJECT, 2018
** SCENE_LIGUES_LIGUE_1
** File description:
** Manages ligue_1 scene from ligues scope
*/

#include "declaration.h"

void load_scene_ligues_ligue_1(game_t *game)
{
	game->ligues[0].type = LIGUE_1;
	game->ligues[0].name = "Ligue master : Philippe Costes";
	game->ligues[0].map_file = "maps/ligues/ligue_1.map";
}
