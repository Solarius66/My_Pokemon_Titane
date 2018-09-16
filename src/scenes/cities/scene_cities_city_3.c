/*
** EPITECH PROJECT, 2018
** SCENE_CITIES_CITY_3
** File description:
** Manages city_3 scene from cities scope
*/

#include "declaration.h"

void load_scene_cities_city_3(game_t *game)
{
	game->cities[2].type = CITY_3;
	game->cities[2].name = "City 3";
	game->cities[2].map_file = "maps/cities/city_3.map";
}
