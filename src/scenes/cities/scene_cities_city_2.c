/*
** EPITECH PROJECT, 2018
** SCENE_CITIES_CITY_2
** File description:
** Manages city_2 scene from cities scope
*/

#include "declaration.h"

void load_scene_cities_city_2(game_t *game)
{
	game->cities[1].type = CITY_2;
	game->cities[1].name = "City 2";
	game->cities[1].map_file = "maps/cities/city_2.map";
}
