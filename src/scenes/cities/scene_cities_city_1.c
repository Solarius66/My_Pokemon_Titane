/*
** EPITECH PROJECT, 2018
** SCENE_CITIES_CITY_1
** File description:
** Manages city_1 scene from cities scope
*/

#include "declaration.h"

void load_scene_cities_city_1(game_t *game)
{
	game->cities[0].type = CITY_1;
	game->cities[0].name = "City 1";
	game->cities[0].map_file = "maps/cities/city_1.map";
}
