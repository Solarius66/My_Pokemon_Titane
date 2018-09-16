/*
** EPITECH PROJECT, 2018
** CHECK_BUILDINGS.C
** File description:
** Checks if player can interact with building
*/

#include "declaration.h"

int check_shop(game_t *game, sfVector2f pp)
{
	sfVector2f sp = game->cur_scene->shop_pos;

	if (sp.x != pp.x || sp.y != pp.y)
		return (0);
	if (game->player->look_tile != 1)
		return (0);
	if (press_b(game)) {
		shop_management(game);
	}
	return (0);
}

int check_center(game_t *game, sfVector2f pp)
{
	sfVector2f cp = game->cur_scene->center_pos;

	if (cp.x != pp.x || cp.y != pp.y)
		return (0);
	if (game->player->look_tile != 1)
		return (0);
	if (press_b(game)) {
		poke_center_management(game);
	}
	return (0);
}

int check_arena(game_t *game, sfVector2f pp)
{
	sfVector2f ap = game->cur_scene->arena_pos;

	if (ap.x != pp.x || ap.y != pp.y)
		return (0);
	if (game->player->look_tile != 1)
		return (0);
	if (press_b(game)) {
		return (0);
	}
	return (0);
}

int check_buildings(game_t *game)
{
	scene_t *cs = game->cur_scene;
	sfVector2f pp = game->player->position;

	if (!game)
		return (84);
	if (cs->arena_pos.x != -1 && cs->arena_pos.y != -1)
		check_arena(game, pp);
	if (cs->center_pos.x != -1 && cs->center_pos.y != -1)
		check_center(game, pp);
	if (cs->shop_pos.x != -1 && cs->shop_pos.y != -1)
		check_shop(game, pp);
	return (0);
}
