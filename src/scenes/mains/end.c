/*
** EPITECH PROJECT, 2018
** end
** File description:
** end
*/

#include "declaration.h"

void display_end(game_t *game, intro_t *intro, sfTexture *credit,
sfClock *clock)
{
	static int x = 0;

	if (sfClock_getElapsedTime(clock).microseconds < 50000 && x > -4480) {
		x--;
		sfClock_restart(clock);
	}
	create_rect(intro->para4, create_vector2f(0, 0),
	create_vector2f(960, 640), game->win);
	intro_display(intro, -x / 5, game);
	create_rect(credit, create_vector2f(0, x), create_vector2f(960, 5120),
	game->win);
}

void end_main(game_t *game)
{
	intro_t *intro = create_intro_str();
	sfTexture *credit = sfTexture_createFromFile(CREDITS, NULL);
	sfClock *clock = sfClock_create();

	sfMusic_stop(game->musics->current);
	sfMusic_play(game->musics->end);
	while (sfRenderWindow_isOpen(game->win)) {
		sfRenderWindow_clear(game->win, sfBlack);
		display_end(game, intro, credit, clock);
		sfRenderWindow_display(game->win);
		event_close(game->win);
		if (press_b(game))
			break;
	}
	sfMusic_stop(game->musics->end);
	sfTexture_destroy(credit);
	sfClock_destroy(clock);
	destroy_intro(intro);
}
