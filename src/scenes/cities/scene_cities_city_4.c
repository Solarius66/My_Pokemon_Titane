/*
** EPITECH PROJECT, 2018
** SCENE_CITIES_CITY_4
** File description:
** Manages city_4 scene from cities scope
*/

#include "declaration.h"

void load_scene_cities_city_4(game_t *game)
{
	game->cities[3].type = CITY_4;
	game->cities[3].name = "City 4";
	game->cities[3].map_file = "maps/cities/city_4.map";
}
