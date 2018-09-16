/*
** EPITECH PROJECT, 2018
** SCENE_ROADS_ROAD_6
** File description:
** Manages road_6 scene from roads scope
*/

#include "declaration.h"

void load_scene_roads_road_6(game_t *game)
{
	game->roads[5].type = ROAD_6;
	game->roads[5].name = "Road 6";
	game->roads[5].map_file = "maps/roads/road_6.map";
}
