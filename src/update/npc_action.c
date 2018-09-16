/*
** EPITECH PROJECT, 2018
** my_rPOKEMONg
** File description:
** npc actions
*/

#include "declaration.h"

int npc_interaction(game_t *game)
{
	sfVector2f pos = game->player->position;
	int look = game->player->look_tile;
	sfClock *clock = sfClock_create();

	pos.x += 15;
	pos.y += 10;
	if (!press_b(game))
		return (0);
	for (player_t *npc = game->npc; npc; npc = npc->next) {
		if (!epi_compare_str(npc->map_name, game->cur_scene->map_file))
			continue;
		if ((look == 0 && pos.x == npc->position.x && pos.y + 1 == npc->position.y) ||
		    (look == 1 && pos.x == npc->position.x && pos.y - 1 == npc->position.y) ||
		    (look == 2 && pos.x - 1 == npc->position.x && pos.y == npc->position.y) ||
		    (look == 3 && pos.x + 1 == npc->position.x && pos.y == npc->position.y)) {
			sfClock_restart(clock);
			text_displayer(game, npc->catchphrase, false);
			sfRenderWindow_display(game->win);
			while (sfClock_getElapsedTime(clock).microseconds <= 500000 ||
			       !press_b(game));
			break;
		}
	}
	while (sfClock_getElapsedTime(clock).microseconds <= 1000000);
	sfClock_destroy(clock);
	return (0);
}
