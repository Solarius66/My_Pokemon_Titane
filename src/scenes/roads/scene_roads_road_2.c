/*
** EPITECH PROJECT, 2018
** SCENE_ROADS_ROAD_2
** File description:
** Manages road_2 scene from roads scope
*/

#include "declaration.h"

void load_scene_roads_road_2(game_t *game)
{
	game->roads[1].type = ROAD_2;
	game->roads[1].name = "Road 2";
	game->roads[1].map_file = "maps/roads/road_2.map";
}
