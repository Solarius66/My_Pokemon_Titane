/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Rpg based on Pokemon
*/

#include "declaration.h"

void display_question_save(game_t *game, int x)
{
	create_color_rect(game->outline, create_vector2f(140, 185),
	create_vector2f(815, 450), game->win);
	create_color_rect_in(sfWhite, create_vector2f(140, 185),
	create_vector2f(815, 450), game->win);
	create_text_save(game->texture->font, create_vector2f(860, 500),
	"NON", game->win);
	create_text_save(game->texture->font, create_vector2f(860, 575),
	"OUI", game->win);
	create_color_rect(game->outline, create_vector2f(140, 60),
	create_vector2f(815, 475 + x * 75), game->win);
}

int define_x_save(int x, sfClock *clock)
{
	if (sfClock_getElapsedTime(clock).microseconds <= 100000)
		return (x);
	if (move_bot() == sfTrue || move_top() == sfTrue) {
		if (x == 0)
			x = 1;
		else if (x == 1)
			x = 0;
		sfClock_restart(clock);
	}
	return (x);
}

int really_save(game_t *game)
{
	int x = 0;
	sfClock *clock = sfClock_create();

	while (sfClock_getElapsedTime(clock).microseconds <= 100000);
	sfClock_restart(clock);
	while (sfRenderWindow_isOpen(game->win)) {
		text_displayer(game, "Voulez vous sauvegarder?", true);
		display_question_save(game, x);
		x = define_x_save(x, clock);
		sfRenderWindow_display(game->win);
		event_close(game->win);
		if (press_b(game))
			break;
	}
	sfClock_restart(clock);
	while (sfClock_getElapsedTime(clock).microseconds <= 100000);
	sfClock_destroy(clock);
	return (x);
}

void save(game_t *game)
{
	int fd;

	if (really_save(game) == 0)
		return;
	fd = open(".save", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	save_player(fd, game->player, game);
	save_color(fd, game->outline);
	save_settings(fd, game->settings);
	save_bag(fd, game->bag);
	save_pokedex(fd, game->pokemons);
	close(fd);
}
