/*
** EPITECH PROJECT, 2018
** SCENE_ROADS_ROAD_8
** File description:
** Manages road_8 scene from roads scope
*/

#include "declaration.h"

void load_scene_roads_road_8(game_t *game)
{
	game->roads[7].type = ROAD_8;
	game->roads[7].name = "Road 8";
	game->roads[7].map_file = "maps/roads/road_8.map";
}
