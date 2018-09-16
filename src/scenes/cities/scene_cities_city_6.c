/*
** EPITECH PROJECT, 2018
** SCENE_CITIES_CITY_6
** File description:
** Manages city_6 scene from cities scope
*/

#include "declaration.h"

void load_scene_cities_city_6(game_t *game)
{
	game->cities[5].type = CITY_6;
	game->cities[5].name = "City 6";
	game->cities[5].map_file = "maps/cities/city_6.map";
}
