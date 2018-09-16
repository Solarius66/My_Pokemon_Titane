/*
** EPITECH PROJECT, 2018
** SCENE_ROADS_ROAD_7
** File description:
** Manages road_7 scene from roads scope
*/

#include "declaration.h"

void load_scene_roads_road_7(game_t *game)
{
	game->roads[6].type = ROAD_7;
	game->roads[6].name = "Road 7";
	game->roads[6].map_file = "maps/roads/road_7.map";
}
