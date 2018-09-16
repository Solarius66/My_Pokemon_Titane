/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Manages player position on maps
*/

#include "declaration.h"

sfVector2f *get_entrances(scene_t *cur_scene)
{
	sfVector2f *entrances = NULL;

	if (!cur_scene)
		return (NULL);
	entrances = malloc(sizeof(sfVector2f) * 4);
	entrances[0].x = cur_scene->north.x;
	entrances[0].y = cur_scene->north.y;
	entrances[1].x = cur_scene->east.x;
	entrances[1].y = cur_scene->east.y;
	entrances[2].x = cur_scene->south.x;
	entrances[2].y = cur_scene->south.y;
	entrances[3].x = cur_scene->west.x;
	entrances[3].y = cur_scene->west.y;
	return (entrances);
}

void check_player_pos(game_t *game, sfVector2f *cur_pos)
{
	sfVector2f *entrances = NULL;
	int cpx = 0;
	int cpy = 0;

	if (!game || !cur_pos)
		return;
	cpx = cur_pos->x + 15;
	cpy = cur_pos->y + 10;
	entrances = get_entrances(game->cur_scene);
	if (cpx == entrances[0].x && cpy == entrances[0].y)
		to_north_scene(game, cur_pos);
	if (cpx == entrances[1].x && cpy == entrances[1].y)
		to_east_scene(game, cur_pos);
	if (cpx == entrances[2].x && cpy == entrances[2].y)
		to_south_scene(game, cur_pos);
	if (cpx == entrances[3].x && cpy == entrances[3].y)
		to_west_scene(game, cur_pos);
	free(entrances);
	check_buildings(game);
}
