/*
** EPITECH PROJECT, 2018
** SCENE_CITIES_CITY_8
** File description:
** Manages city_8 scene from cities scope
*/

#include "declaration.h"

void load_scene_cities_city_8(game_t *game)
{
	game->cities[7].type = CITY_8;
	game->cities[7].name = "City 8";
	game->cities[7].map_file = "maps/cities/city_8.map";
}
