/*
** EPITECH PROJECT, 2018
** options.h
** File description:
** options
*/

#include "declaration.h"

void display_option_text(game_t *game)
{
	create_text_dex(game->texture->font, create_vector2f(220, 110),
	"CONTROLES", game->win);
	create_text_dex(game->texture->font, create_vector2f(220, 235),
	"MUSIQUE", game->win);
	create_text_dex(game->texture->font, create_vector2f(220, 360),
	"COULEUR DU CONTOUR", game->win);
	create_text_inv(game->texture->font, create_vector2f(860, 600),
	"QUIT", game->win);
}

void display_option_rect(game_t *game, int x)
{
	int i = 0;

	if (x == 3)
		i = 1;
	create_rect(game->texture->font_inv, create_vector2f(0, 0),
	create_vector2f(960, 640), game->win);
	create_rect(game->texture->exit[i], create_vector2f(820, 590),
	create_vector2f(125, 38), game->win);
	create_color_rect_in(sfWhite, create_vector2f(560, 100),
	create_vector2f(200, 75), game->win);
	create_color_rect_in(sfWhite, create_vector2f(560, 100),
	create_vector2f(200, 200), game->win);
	create_color_rect_in(sfWhite, create_vector2f(560, 100),
	create_vector2f(200, 325), game->win);
	if (x != 3)
		create_color_rect(game->outline, create_vector2f(560, 100),
		create_vector2f(200, 75 + 125 * x), game->win);
	if (x == 2)
		text_displayer(game,
		"Gauche / Droite Couleur du contour", true);
}

int manage_cursor_option(int x, sfClock *clock)
{
	if (sfClock_getElapsedTime(clock).microseconds < 150000)
		return (x);
	if (move_bot())
		x++;
	if (move_top())
		x--;
	if (x == 4)
		x = 0;
	if (x == -1)
		x = 3;
	sfClock_restart(clock);
	return (x);
}

void define_option_button(game_t *game, int x, sfClock *clock)
{
	if (x == 0 && press_b(game))
		create_rect(game->texture->controls, create_vector2f(0, 0),
		create_vector2f(960, 640), game->win);
	if (x == 1 && press_b(game))
		play_pause(game);
	if (x == 2)
		define_outline_color(game, clock);
}

void option_main(game_t *game)
{
	int x = 0;
	sfClock *clock = sfClock_create();
	sfClock *color_clock = sfClock_create();

	while (sfClock_getElapsedTime(clock).microseconds <= 150000);
	sfClock_restart(clock);
	while (sfRenderWindow_isOpen(game->win)) {
		sfRenderWindow_clear(game->win, sfBlack);
		display_option_rect(game, x);
		display_option_text(game);
		define_option_button(game, x, clock);
		sfRenderWindow_display(game->win);
		event_close(game->win);
		x = manage_cursor_option(x, color_clock);
		if (press_a() || (x == 3 && press_b(game)))
			break;
	}
	sfClock_restart(clock);
	while (sfClock_getElapsedTime(clock).microseconds <= 150000);
	sfClock_destroy(clock);
	sfClock_destroy(color_clock);
}
