/*
** EPITECH PROJECT, 2018
** INITIALIZE_GAME_6.C
** File description:
** Create base scenes
*/

#include "declaration.h"

int create_default_scene_extended(scene_t *scene)
{
	scene->scene_type = NULL;
	scene->scene_index = 0;
	scene->arena_pos.x = -1.0;
	scene->arena_pos.y = -1.0;
	scene->center_pos.x = -1.0;
	scene->center_pos.y = -1.0;
	scene->shop_pos.x = -1.0;
	scene->shop_pos.y = -1.0;
	return (0);
}

int create_default_scene(scene_t *scene)
{
	if (!scene)
		return (84);
	scene->name = NULL;
	scene->map_file = NULL;
	scene->layers = NULL;
	scene->npcs = NULL;
	scene->interface = NULL;
	scene->layer_ground = NULL;
	scene->layer_col = NULL;
	scene->layer_top = NULL;
	scene->north_dest = NULL;
	scene->south_dest = NULL;
	scene->east_dest = NULL;
	scene->west_dest = NULL;
	scene->trainers = NULL;
	scene->pokemons = NULL;
	scene->signs = NULL;
	scene->homes = NULL;
	create_default_scene_extended(scene);
	return (0);
}

int create_scene_properties(scene_t *scene)
{
	if (!scene)
		return (84);
	return (0);
}

int create_entrances(int fd, scene_t *scene)
{
	scene->north_dest = get_next_line(fd);
	scene->south_dest = get_next_line(fd);
	scene->west_dest = get_next_line(fd);
	scene->east_dest = get_next_line(fd);
	return (0);
}
