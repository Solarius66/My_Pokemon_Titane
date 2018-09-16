/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Get proper scene and position to switch
*/

#include "declaration.h"

void switch_to_correct_scene(game_t *game, char **data, sfVector2f *cur_pos)
{
	int i = epi_atoi(data[1]);

	if (!cur_pos)
		return;
	if (epi_compare_str(data[0], "ROAD"))
		switch_scene(game, game->scenes->roads[i]);
	if (epi_compare_str(data[0], "CITY"))
		switch_scene(game, game->scenes->cities[i]);
	if (epi_compare_str(data[0], "ZONE"))
		switch_scene(game, game->scenes->zones[i]);
}

void to_north_scene(game_t *game, sfVector2f *cur_pos)
{
	char **data = NULL;
	scene_t *scene = game->cur_scene;

	if (!game || !cur_pos)
		return;
	data = str_parse(scene->north_dest, ';');
	switch_to_correct_scene(game, data, cur_pos);
	stra_free(data);
	cur_pos->x = game->cur_scene->south.x - 15;
	cur_pos->y = game->cur_scene->south.y - 11;
}

void to_south_scene(game_t *game, sfVector2f *cur_pos)
{
	char **data = NULL;
	scene_t *scene = game->cur_scene;

	if (!game || !cur_pos)
		return;
	data = str_parse(scene->south_dest, ';');
	switch_to_correct_scene(game, data, cur_pos);
	stra_free(data);
	cur_pos->x = game->cur_scene->north.x - 15;
	cur_pos->y = game->cur_scene->north.y - 9;
}

void to_west_scene(game_t *game, sfVector2f *cur_pos)
{
	char **data = NULL;
	scene_t *scene = game->cur_scene;

	if (!game || !cur_pos)
		return;
	data = str_parse(scene->west_dest, ';');
	switch_to_correct_scene(game, data, cur_pos);
	stra_free(data);
	cur_pos->x = game->cur_scene->east.x - 16;
	cur_pos->y = game->cur_scene->east.y - 10;
}

void to_east_scene(game_t *game, sfVector2f *cur_pos)
{
	char **data = NULL;
	scene_t *scene = game->cur_scene;

	if (!game || !cur_pos)
		return;
	data = str_parse(scene->east_dest, ';');
	switch_to_correct_scene(game, data, cur_pos);
	stra_free(data);
	cur_pos->x = game->cur_scene->west.x - 14;
	cur_pos->y = game->cur_scene->west.y - 10;
}
