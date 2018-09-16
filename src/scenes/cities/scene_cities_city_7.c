/*
** EPITECH PROJECT, 2018
** SCENE_CITIES_CITY_7
** File description:
** Manages city_7 scene from cities scope
*/

#include "declaration.h"

void load_scene_cities_city_7(game_t *game)
{
	game->cities[6].type = CITY_7;
	game->cities[6].name = "City 7";
	game->cities[6].map_file = "maps/cities/city_7.map";
}
