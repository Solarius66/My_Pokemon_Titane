/*
** EPITECH PROJECT, 2018
** shop management
** File description:
** shop management
*/

#include "declaration.h"

int define_x_shop(int x, sfClock *clock)
{
	if (sfClock_getElapsedTime(clock).microseconds <= 100000)
		return (x);
	sfClock_restart(clock);
	if (move_top())
		x--;
	if (move_bot())
		x++;
	if (x < 0)
		x = 9;
	if (x > 9)
		x = 0;
	return (x);
}

int display_article_shop(game_t *game, sfClock *clock, int x)
{
	char *items[11]= {"POTION", "SUPER POTION", "HYPER POTION",
			  "POTION MAX", "TOTAL_SOIN", "POKEBALL",
			  "SUPER BALL", "HYPER BALL", "MASTER BALL",
			  "QUITTER"};

	x = define_x_shop(x, clock);
	create_color_rect_in(sfWhite, create_vector2f(500, 430),
	create_vector2f(5, 5), game->win);
	create_color_rect(game->outline, create_vector2f(500, 430),
	create_vector2f(5, 5), game->win);
	create_color_rect(game->outline, create_vector2f(490, 40),
	create_vector2f(10, 40 * x + 10), game->win);
	for (int y = 0; y < 11; y++) {
		if (y >= 0 && y <= 11 && 40 * y + 20 < 430)
			create_text_pause(game->texture->font,
					  create_vector2f(20, 40 * y + 20),
					  items[y], game->win);
	}
	return (x);
}

void display_stats_shop(game_t *game)
{
	char *money = epi_itoa(game->player->money);

	create_color_rect_in(sfWhite, create_vector2f(200, 250),
	create_vector2f(700, 50), game->win);
	create_color_rect(game->outline, create_vector2f(200, 250),
	create_vector2f(700, 50), game->win);
	create_text_pause(game->texture->font, create_vector2f(710, 65),
	"BOUTIQUE", game->win);
	create_text_pause(game->texture->font, create_vector2f(710, 125),
	"$ :", game->win);
	create_text_pause(game->texture->font, create_vector2f(770, 125),
	money, game->win);
}

void shop_management(game_t *game)
{
	sfClock *clock = sfClock_create();
	int x = 0;

	while (press_b(game));
	while (sfRenderWindow_isOpen(game->win)) {
		map_displayer_main(game, false);
		text_displayer(game, "Bonjour, que voulez-vous acheter?",
		false);
		x = display_article_shop(game, clock, x);
		display_stats_shop(game);
		sfRenderWindow_display(game->win);
		if (press_a() || (press_b(game) && x == 9))
			break;
		event_close(game->win);
	}
	while (press_b(game));
}
