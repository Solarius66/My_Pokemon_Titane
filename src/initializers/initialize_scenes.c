/*
** EPITECH PROJECT, 2018
** INITIALIZE_SCENES.C
** File description:
** Initializes game's scenes
*/

#include "declaration.h"

int initialize_zones(game_t *game)
{
	scene_t **cursor = game->scenes->zones;

	for (int i = 0; i < 4; ++i)
		cursor[i] = malloc(sizeof(scene_t));
	initialize_scene("assets/maps/ZONE_1", cursor[0]);
	initialize_scene("assets/maps/ZONE_2", cursor[1]);
	initialize_scene("assets/maps/ZONE_3", cursor[2]);
	initialize_scene("assets/maps/ZONE_4", cursor[3]);
	return (0);
}

int initialize_cities(game_t *game)
{
	scene_t **cursor = game->scenes->cities;

	for (int i = 0; i < 8; ++i)
		cursor[i] = malloc(sizeof(scene_t));
	initialize_scene("assets/maps/CITY_1", cursor[0]);
	initialize_scene("assets/maps/CITY_2", cursor[1]);
	initialize_scene("assets/maps/CITY_3", cursor[2]);
	initialize_scene("assets/maps/CITY_4", cursor[3]);
	initialize_scene("assets/maps/CITY_5", cursor[4]);
	initialize_scene("assets/maps/CITY_6", cursor[5]);
	initialize_scene("assets/maps/CITY_7", cursor[6]);
	initialize_scene("assets/maps/CITY_8", cursor[7]);
	return (0);
}

int initialize_roads(game_t *game)
{
	scene_t **cursor = game->scenes->roads;

	for (int i = 0; i < 9; ++i)
		cursor[i] = malloc(sizeof(scene_t));
	initialize_scene("assets/maps/ROAD_1", cursor[0]);
	initialize_scene("assets/maps/ROAD_2", cursor[1]);
	initialize_scene("assets/maps/ROAD_3", cursor[2]);
	initialize_scene("assets/maps/ROAD_4", cursor[3]);
	initialize_scene("assets/maps/ROAD_5", cursor[4]);
	initialize_scene("assets/maps/ROAD_6", cursor[5]);
	initialize_scene("assets/maps/ROAD_7", cursor[6]);
	initialize_scene("assets/maps/ROAD_8", cursor[7]);
	initialize_scene("assets/maps/ROAD_9", cursor[8]);
	return (0);
}

int initialize_scenes(game_t *game)
{
	game->scenes = malloc(sizeof(scenes_t));
	if (!game->scenes)
		return (84);
	game->scenes->zones = malloc(sizeof(scene_t *) * 4);
	if (!game->scenes->zones)
		return (84);
	game->scenes->roads = malloc(sizeof(scene_t *) * 9);
	if (!game->scenes->roads)
		return (84);
	game->scenes->cities = malloc(sizeof(scene_t *) * 8);
	if (!game->scenes->cities)
		return (84);
	initialize_zones(game);
	initialize_roads(game);
	initialize_cities(game);
	return (0);
}
