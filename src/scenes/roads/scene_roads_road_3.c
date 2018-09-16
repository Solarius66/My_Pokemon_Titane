/*
** EPITECH PROJECT, 2018
** SCENE_ROADS_ROAD_3
** File description:
** Manages road_3 scene from roads scope
*/

#include "declaration.h"

void load_scene_roads_road_3(game_t *game)
{
	game->roads[2].type = ROAD_3;
	game->roads[2].name = "Road 3";
	game->roads[2].map_file = "maps/roads/road_3.map";
}
