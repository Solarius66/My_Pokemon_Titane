/*
** EPITECH PROJECT, 2018
** SCENE_ROADS_ROAD_5
** File description:
** Manages road_5 scene from roads scope
*/

#include "declaration.h"

void load_scene_roads_road_5(game_t *game)
{
	game->roads[4].type = ROAD_5;
	game->roads[4].name = "Road 5";
	game->roads[4].map_file = "maps/roads/road_5.map";
}
