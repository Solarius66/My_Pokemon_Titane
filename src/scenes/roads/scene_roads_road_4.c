/*
** EPITECH PROJECT, 2018
** SCENE_ROADS_ROAD_4
** File description:
** Manages road_4 scene from roads scope
*/

#include "declaration.h"

void load_scene_roads_road_4(game_t *game)
{
	game->roads[3].type = ROAD_4;
	game->roads[3].name = "Road 4";
	game->roads[3].map_file = "maps/roads/road_4.map";
}
