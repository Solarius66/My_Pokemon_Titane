/*
** EPITECH PROJECT, 2018
** SCENE_LIGUES_LIGUE_4
** File description:
** Manages ligue_4 scene from ligues scope
*/

#include "declaration.h"

void load_scene_ligues_ligue_4(game_t *game)
{
	game->ligues[3].type = LIGUE_4;
	game->ligues[3].name = "Council 4 : Marion";
	game->ligues[3].map_file = "maps/ligues/ligue_4.map";
}
