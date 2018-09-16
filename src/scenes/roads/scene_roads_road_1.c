/*
** EPITECH PROJECT, 2018
** SCENE_ROADS_ROAD_1
** File description:
** Manages road_1 scene from roads scope
*/

#include "declaration.h"

void load_scene_roads_road_1(game_t *game)
{
	game->roads[0].type = ROAD_1;
	game->roads[0].name = "Road 1";
	game->roads[0].map_file = "maps/roads/ROAD_1";
	load_map_from_path(&game->roads[0]);
}

void load_interface_road_1(scene_t *road_1)
{
	(void)road_1;
}
