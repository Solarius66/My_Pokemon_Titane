/*
** EPITECH PROJECT, 2018
** new game.c
** File description:
** new game
*/

#include "declaration.h"

int manage_x_new(int x, sfClock *clock, int limit)
{
	if (sfClock_getElapsedTime(clock).microseconds <= 120000)
		return (x);
	if (move_left())
		x--;
	if (move_right())
		x++;
	if (x < 0)
		x = limit;
	if (x > limit)
		x = 0;
	sfClock_restart(clock);
	return (x);
}

void display_gender(game_t *game, int x)
{
	sfSprite *man;
	sfSprite *woman;

	create_rect(game->texture->start_b, create_vector2f(0, 0),
	create_vector2f(960, 440), game->win);
	create_color_rect(game->outline, create_vector2f(180, 275),
	create_vector2f(240 + 380 * x, 100), game->win);
	man = create_sprite(game->texture->trainer_big,
	create_vector2f(240, 100), create_int_rect(0, 0, 36, 55));
	woman = create_sprite(game->texture->trainer_big,
	create_vector2f(620, 100), create_int_rect(0, 36, 36, 55));
	sfSprite_setScale(man, create_vector2f(5, 5));
	sfSprite_setScale(woman, create_vector2f(5, 5));
	sfRenderWindow_drawSprite(game->win, man, NULL);
	sfRenderWindow_drawSprite(game->win, woman, NULL);
	sfSprite_destroy(man);
	sfSprite_destroy(woman);
}

void define_gender_player(game_t *game)
{
	int x = 0;
	sfClock *clock = sfClock_create();

	while (sfRenderWindow_isOpen(game->win)) {
		display_gender(game, x);
		sfRenderWindow_display(game->win);
		x = manage_x_new(x, clock, 1);
		if (press_b(game))
			break;
		event_close(game->win);
	}
	sfClock_destroy(clock);
	if (x == 0)
		game->player->texture = game->texture->man;
	else if (x == 1)
		game->player->texture = game->texture->woman;
	game->player->gender = x;
}

void display_starter(game_t *game, int x, int z)
{
	sfSprite *sprite;

	create_rect(game->texture->start_b, create_vector2f(0, 0),
	create_vector2f(960, 440), game->win);
	for (int y = 0; y < 3; y++) {
		if (x == y)
			sprite = create_sprite(game->texture->ball_till,
			create_vector2f(270 + 150 * y, 200),
			create_int_rect(0, 0 + 90 * z, 90, 90));
		else
			sprite = create_sprite(game->texture->ball_till,
			create_vector2f(270 + 150 * y, 200),
			create_int_rect(0, 0, 90, 90));
		sfRenderWindow_drawSprite(game->win, sprite, NULL);
		sfSprite_destroy(sprite);
	}
}

void choose_starter(game_t *game)
{
	int x = 0;
	sfClock *clock = sfClock_create();
	sfClock *tilt = sfClock_create();
	int z = 0;

	while (sfClock_getElapsedTime(clock).microseconds < 100000);
	while (sfRenderWindow_isOpen(game->win)
	&& game->player->pokemons[0] == NULL) {
		display_starter(game, x, z);
		text_displayer(game, "Maintenant, choisis ton pokemon", false);
		sfRenderWindow_display(game->win);
		event_close(game->win);
		x = manage_x_new(x, clock, 2);
		z = manage_tilt_new(z, tilt, 3);
		if (press_b(game))
			define_starter(game, x, tilt);
	}
	sfClock_destroy(tilt);
	sfClock_destroy(clock);
}
