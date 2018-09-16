/*
** EPITECH PROJECT, 2018
** SCENE_LIGUES_LIGUE_3
** File description:
** Manages ligue_3 scene from ligues scope
*/

#include "declaration.h"

void load_scene_ligues_ligue_3(game_t *game)
{
	game->ligues[2].type = LIGUE_3;
	game->ligues[2].name = "Council 4 : Rodolphe";
	game->ligues[2].map_file = "maps/ligues/ligue_3.map";
}
