/*
** EPITECH PROJECT, 2018
** text manager
** File description:
** text displayer fight
*/

#include "declaration.h"

void display_escape(game_t *game)
{
	text_displayer(game, "Vous prennez la fuite", false);
	sfRenderWindow_display(game->win);
	while (!press_b(game));
}

void display_attack_name(game_t *game, player_t *p1, player_t *p2)
{
	char *str = epi_putf("%s utilise %s!",
	p1->pokemons[p1->actual]->name,
	p1->pokemons[p1->actual]->attack_chosen.name);

	text_displayer(game, str, false);
	free(str);
	sfRenderWindow_display(game->win);
	while (!press_b(game));
	while (press_b(game));
	str = epi_putf("%s utilise %s!",
	p2->pokemons[p2->actual]->name,
	p2->pokemons[p2->actual]->attack_chosen.name);
	text_displayer(game, str, false);
	free(str);
	sfRenderWindow_display(game->win);
	while (!press_b(game));
}

void text_manager_fight(int x, game_t *game, player_t *p1, player_t *p2)
{
	if (x == 1) {
		if (speed_calculator(p1->pokemons[p1->actual],
			p2->pokemons[p2->actual]) == 2)
			display_attack_name(game, p1, p2);
		else if (speed_calculator(p1->pokemons[p1->actual],
			p2->pokemons[p2->actual]) == 1)
			display_attack_name(game, p2, p1);
	}
	if (x == 2)
		return;
	if (x == 3)
		return;
	if (x == 4)
		display_escape(game);
}
