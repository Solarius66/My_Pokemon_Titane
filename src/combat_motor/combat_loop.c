/*
** EPITECH PROJECT, 2018
** my_rPOKEMONg
** File description:
** combat_loop
*/

#include "declaration.h"

void display_death(game_t *game, player_t *p1)
{
	char *str;
	sfClock *clock = sfClock_create();

	str = epi_putf("%s est KO!", p1->pokemons[p1->actual]->name);
	text_displayer(game, str, false);
	free(str);
	sfRenderWindow_display(game->win);
	while (sfClock_getElapsedTime(clock).microseconds < 150000);
	while (!press_b(game));
	sfClock_destroy(clock);
}

int attack_main(player_t *P1, player_t *P2, game_t *game)
{
	if (speed_calculator(P1->pokemons[P1->actual],
	P2->pokemons[P2->actual]) == 2) {
		return (attack_main(P2, P1, game));
	} else {
		P2->pokemons[P2->actual]->cur_health -=
		attack_dps(P1->pokemons[P1->actual], P2->pokemons[P2->actual]);
		if (P2->pokemons[P2->actual]->cur_health < 0)
			P2->pokemons[P2->actual]->cur_health = 0;
		if (P2->pokemons[P2->actual]->cur_health <= 0) {
			display_death(game, P2);
			return (0);
		}
		P1->pokemons[P1->actual]->cur_health -=
		attack_dps(P2->pokemons[P2->actual], P1->pokemons[P1->actual]);
		if (P1->pokemons[P1->actual]->cur_health < 0)
			P1->pokemons[P1->actual]->cur_health = 0;
		if (P1->pokemons[P2->actual]->cur_health <= 0)
			display_death(game, P1);
	}
	return (0);
}

int hp_check(player_t *p1, player_t *p2)
{
	int x = 0;

	while (x < 6) {
		if (p1->pokemons[x] && p1->pokemons[x]->cur_health > 0)
			break;
		x++;
	}
	if (p1->pokemons[x] == NULL || p1->pokemons[x]->cur_health <= 0)
		return (2);
	x = 0;
	while (x < 6) {
		if (p2->pokemons[x] == NULL)
			x++;
		else if (p2->pokemons[x]->cur_health > 0)
			return (0);
		else
			x++;
	}
	return (1);
}

void combat_loop(game_t *game, player_t *player, player_t *npc)
{
	int win = 0;

	music_management_fight(game, npc, false);
	while (sfRenderWindow_isOpen(game->win)) {
		sfRenderWindow_clear(game->win, sfBlack);
		combat_displayer(game, player, npc);
		sfRenderWindow_display(game->win);
		attack_ai(npc->pokemons[npc->actual]);
		if (display_ath_fight(game, player, npc) == 1)
			break;
		attack_main(player, npc, game);
		sfRenderWindow_clear(game->win, sfBlack);
		combat_displayer(game, player, npc);
		sfRenderWindow_display(game->win);
		event_close(game->win);
		if ((win = hp_check(player, npc)) != 0)
			break;
	}
	win_management(win, game, player, npc);
	music_management_fight(game, npc, true);
}
