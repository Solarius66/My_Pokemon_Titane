/*
** EPITECH PROJECT, 2018
** display npc
** File description:
** display npc
*/

#include "declaration.h"

void display_one_npc(game_t *game, player_t *npc)
{
	create_rect(game->texture->npc[npc->skin_id][1],
		create_vector2f((npc->position.x - game->player->position.x) * 32,
				(npc->position.y - game->player->position.y) * 32 - 10),
		create_vector2f(32, 42), game->win);
}

void display_npcs(game_t *game, player_t *npc)
{
	while (npc != NULL) {
		if (nmatch(game->cur_scene->map_file, npc->map_name) == 1)
			display_one_npc(game, npc);
		npc = npc->next;
	}
}
