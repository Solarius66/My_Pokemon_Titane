/*
** EPITECH PROJECT, 2018
** bag
** File description:
** bag
*/

#include "declaration.h"

void display_heal_bag(game_t *game, sfVector2i cursor)
{
	char *items[6] = {"POTION", "SUPER POTION", "HYPER POTION",
		"POTION MAX", "TOTAL SOIN", "QUITTER"};
	char *desc[6] = {"Un spray qui rend 20 PV a un pokemon.",
		"Un spray qui rend 50 PV a un pokemon.",
		"Un spray qui rend 200 PV a un pokemon.",
		"Un spray qui rend tout ses PV a un pokemon.",
		"Un spray qui enleve tout les etats d'un pokemon.",
		"RETOUR"};

	for (int x = 0; x < 6; x++)
		create_text_bag(game->texture->font,
		create_vector2f(420, 80 + 50 * x), items[x], game->win);
	text_displayer(game, desc[cursor.y], true);
	display_heal_nb(game);
	display_item_heal(game->texture->items, game->win, cursor);
	create_color_rect(game->outline, create_vector2f(530, 40),
	create_vector2f(410, 70 + 50 * cursor.y), game->win);
}

void display_balls_bag(game_t *game, sfVector2i cursor)
{
	char *items[6] = {"POKE BALL", "SUPER BALL", "HYPER BALL",
		"MASTER BALL", "HONOR BALL", "QUITTER"};
	char *desc[6] = {"Un objet qui capture les pokemons sauvages.",
		"Une Ball plus performante que la pokeball.",
		"Une Ball bien plus performante que la super ball.",
		"La Ball la plus performante. Ne rate jamais.",
		"Une Ball rare, creee pour un evenement special.",
		"RETOUR"};

	for (int x = 0; x < 6; x++)
		create_text_bag(game->texture->font,
		create_vector2f(420, 80 + 50 * x), items[x], game->win);
	display_item_ball(game->texture->items, game->win, cursor);
	display_balls_nb(game);
	text_displayer(game, desc[cursor.y], true);
	create_color_rect(game->outline, create_vector2f(530, 40),
	create_vector2f(410, 70 + 50 * cursor.y), game->win);
}

void display_bag_font(game_t *game, sfRenderWindow *window, sfVector2i cursor)
{
	create_rect(game->texture->bag, create_vector2f(0, 0),
	create_vector2f(960, 640), window);
	create_color_rect(game->outline, create_vector2f(150, 50),
	create_vector2f(40 + 150 * cursor.x, 206), window);
	if (cursor.x == 0)
		display_balls_bag(game, cursor);
	else
		display_heal_bag(game, cursor);
}

sfVector2i cursor_management_bag(sfVector2i cursor, sfClock *clock)
{
	if (sfClock_getElapsedTime(clock).microseconds <= 150000)
		return (cursor);
	if (move_left())
		cursor.x--;
	if (move_right())
		cursor.x++;
	if (cursor.x < 0)
		cursor.x = 1;
	if (cursor.x > 1)
		cursor.x = 0;
	if (move_top())
		cursor.y--;
	if (move_bot())
		cursor.y++;
	if (cursor.y < 0)
		cursor.y = 5;
	if (cursor.y > 5)
		cursor.y = 0;
	sfClock_restart(clock);
	return (cursor);
}

void bag_main(game_t *game)
{
	sfVector2i cursor = {0, 0};
	sfClock *clock = sfClock_create();

	while (sfRenderWindow_isOpen(game->win)) {
		sfRenderWindow_clear(game->win, sfBlack);
		display_bag_font(game, game->win, cursor);
		sfRenderWindow_display(game->win);
		cursor = cursor_management_bag(cursor, clock);
		event_close(game->win);
		if (press_a() || (press_b(game) && cursor.y == 5))
			break;
	}
	sfClock_restart(clock);
	while (sfClock_getElapsedTime(clock).microseconds <= 150000);
	sfClock_destroy(clock);
}
