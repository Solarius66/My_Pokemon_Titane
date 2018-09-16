/*
** EPITECH PROJECT, 2018
** SCENE_CITIES_CITY_5
** File description:
** Manages city_5 scene from cities scope
*/

#include "declaration.h"

void load_scene_cities_city_5(game_t *game)
{
	game->cities[4].type = CITY_5;
	game->cities[4].name = "City 5";
	game->cities[4].map_file = "maps/cities/city_5.map";
}
