/*
** EPITECH PROJECT, 2018
** new2
** File description:
** new2
*/

#include "declaration.h"

int manage_tilt_new(int z, sfClock *clock, int max)
{
	if (sfClock_getElapsedTime(clock).microseconds > 100000) {
		z++;
		sfClock_restart(clock);
	}
	if (z > max)
		z = 0;
	return (z);
}

void define_starter2(game_t *game, sfClock *clock, int x)
{
	while (sfClock_getElapsedTime(clock).microseconds < 100000);
	sfClock_restart(clock);
	if (press_b(game))
		game->player->pokemons[0] = pokemon_dup_by_id(1 + 3 * x, 5,
		game->pokemons);
}

void define_starter(game_t *game, int x, sfClock *clock)
{
	sfSprite *sprite = create_sprite(game->texture->pokemons[1 + 3 * x],
	create_vector2f(288, 100), create_int_rect(0, 128, 64, 64));
	char *name = epi_putf("%s, valider?",
	find_pokemon_by_id(game->pokemons, 1 + 3 * x)->name);

	sfSprite_setScale(sprite, create_vector2f(5, 5));
	while (sfClock_getElapsedTime(clock).microseconds < 100000);
	while (press_b(game) == sfFalse && press_a() == sfFalse &&
	sfRenderWindow_isOpen(game->win)) {
		text_displayer(game, name, false);
		create_color_rect(game->outline, create_vector2f(0, 0),
		create_vector2f(200, 200), game->win);
		sfRenderWindow_drawSprite(game->win, sprite, NULL);
		sfRenderWindow_display(game->win);
		event_close(game->win);
		define_starter2(game, clock, x);
	}
	free(name);
	sfSprite_destroy(sprite);
}

void define_name2(game_t *game, int x, char **str)
{
	create_rect(game->texture->start_b, create_vector2f(0, 0),
	create_vector2f(960, 440), game->win);
	create_rect(game->texture->jerem, create_vector2f(305, 10),
	create_vector2f(400, 400), game->win);
	for (int y = 0; y < 4; y++) {
		create_text_pause(game->texture->font,
		create_vector2f(100 + 200 * y, 400), str[y], game->win);
	}
	create_color_rect(game->outline, create_vector2f(190, 30),
	create_vector2f(95 + 200 * x, 400), game->win);
}

void define_name(game_t *game)
{
	char *name[4] = {"ALEX\0", "MATT\0", "MICHAEL\0", "YANNICK\0"};
	int x = 0;
	sfClock *clock = sfClock_create();

	while (sfRenderWindow_isOpen(game->win)) {
		define_name2(game, x, name);
		sfRenderWindow_display(game->win);
		x = manage_x_new(x, clock, 3);
		event_close(game->win);
		if (press_b(game))
			break;
	}
	sfClock_destroy(clock);
	epi_free(game->player->name);
	game->player->name = NULL;
	game->player->name = epi_remalloc(name[x], -1);
}
