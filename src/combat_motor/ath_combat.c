/*
** EPITECH PROJECT, 2018
** ath displayer
** File description:
** ath displayer
*/

#include "declaration.h"

void display_ath_main(game_t *game, player_t *player, int x)
{
	char *str = epi_putf("Que doit faire %s",
	player->pokemons[player->actual]->name);

	text_displayer(game, str, false);
	free(str);
	create_text_pause(game->texture->font,
	create_vector2f(30, 585), "ATTAQUE", game->win);
	create_text_pause(game->texture->font,
	create_vector2f(280, 585), "POKEMON", game->win);
	create_text_pause(game->texture->font,
	create_vector2f(530, 585), "  SAC", game->win);
	create_text_pause(game->texture->font,
	create_vector2f(780, 585), " FUITE", game->win);
	create_color_rect(game->outline, create_vector2f(180, 50),
	create_vector2f(15 + 250 * x, 570), game->win);
}

void display_attack_pick(game_t *game, player_t *player, int x)
{
	display_rect_text(game, false);
	for (int y = 0; y < 4; y++)
		create_text_pause(game->texture->font,
		create_vector2f(150 + 450 * (y % 2), 470 + 100 * (y / 2)),
		player->pokemons[player->actual]->attack[y].name, game->win);
	create_color_rect(game->outline, create_vector2f(300, 50),
	create_vector2f(140 + 450 * (x % 2), 460 + 100 * (x / 2)), game->win);
}

int attack_pick(game_t *game, player_t *player)
{
	int x = 0;
	sfClock *clock = sfClock_create();

	while (sfClock_getElapsedTime(clock).microseconds < 100000);
	while (sfRenderWindow_isOpen(game->win)) {
		display_attack_pick(game, player, x);
		x = manage_x_new(x, clock, 3);
		sfRenderWindow_display(game->win);
		if (press_a())
			return (0);
		if (press_b(game))
			break;
		event_close(game->win);
	}
	sfClock_destroy(clock);
	player->pokemons[player->actual]->attack_chosen =
	player->pokemons[player->actual]->attack[x];
	return (1);
}

int define_menu_fight_main(game_t *game, player_t *p1, int x)
{
	if (x == 0)
		if (attack_pick(game, p1) != 0)
			return (1);
	if (x == 1)
		epi_printf("POKEMON\n");
	if (x == 2)
		epi_printf("POTIONS %d\n", game->bag->default_potions);
	if (x == 3)
		return (4);
	return (0);
}

int display_ath_fight(game_t *game, player_t *player, player_t *npc)
{
	int x = 0;
	int y = 0;
	sfClock *clock = sfClock_create();

	while (press_b(game));
	while (sfRenderWindow_isOpen(game->win)) {
		x = manage_x_new(x, clock, 3);
		if (press_b(game))
			y = define_menu_fight_main(game, player, x);
		if (y != 0)
			break;
		display_ath_main(game, player, x);
		sfRenderWindow_display(game->win);
		event_close(game->win);
	}
	while (press_b(game));
	text_manager_fight(y, game, player, npc);
	sfClock_destroy(clock);
	return ((y == 4) ? 1 : 0);
}
