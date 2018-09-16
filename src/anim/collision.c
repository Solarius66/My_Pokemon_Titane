/*
** EPITECH PROJECT, 2018
** my_RPokemonG
** File description:
** collision
*/

#include "declaration.h"

int collision_npc(game_t *game)
{
	player_t *npc = game->npc;
	sfVector2f pos = game->player->position;
	char *map_name = game->cur_scene->map_file;
	int look = game->player->look_tile;

	pos.x += 15;
	pos.y += 10;
	for (; npc; npc = npc->next) {
		if (!epi_compare_str(npc->map_name, map_name))
			continue;
		if (look == 0 && pos.x == npc->position.x && pos.y + 1 == npc->position.y)
			return (0);
		if (look == 1 && pos.x == npc->position.x && pos.y - 1 == npc->position.y)
			return (0);
		if (look == 2 && pos.x - 1 == npc->position.x && pos.y == npc->position.y)
			return (0);
		if (look == 3 && pos.x + 1 == npc->position.x && pos.y == npc->position.y)
			return (0);
	}
	return (1);
}

int collision2(char **str, int look_tile, int x, int y)
{
	int i = 0;

	if (look_tile == 0 && str[y + 1][x] == ' ')
		i = 1;
	if (look_tile == 1 && str[y - 1][x] == ' ')
		i = 1;
	if (look_tile == 2 && str[y][x - 1] == ' ')
		i = 1;
	if (look_tile == 3 && str[y][x + 1] == ' ')
		i = 1;
	if (look_tile == 0 && str[y + 1][x] == '|')
		i = 2;
	if (look_tile == 1 && str[y - 1][x] == '|')
		i = 2;
	if ((look_tile == 2 && str[y][x - 1] == '|') ||
		(look_tile == 3 && str[y][x + 1] == '|'))
		i = 2;
	return (i);
}

int collision(char *map, int look_tile, int x, int y)
{
	char **str = epi_split(map, '\n');
	int i = 0;

	if (look_tile == 1 && y == 0)
		return (0);
	if (look_tile == 2 && x == 0)
		return (0);
	if (look_tile == 0 && y >= epi_dstrlen(str))
		return (0);
	if (look_tile == 3 && x >= epi_strlen(str[0]))
		return (0);
	i = collision2(str, look_tile, x, y);
	epi_ddestroy(str);
	return (i);
}
