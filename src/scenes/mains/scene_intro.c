/*
** EPITECH PROJECT, 2018
** scene intro
** File description:
** scene intro
*/

#include "declaration.h"

void display_mew_intro(sfTexture *texture, int x, sfRenderWindow *win)
{
	sfSprite *sprite = create_sprite(texture,
	create_vector2f((1500 - (x % 200 * 10)), 100),
	create_int_rect(0, 70 * ((x % 50) % 3), 70, 38));

	sfSprite_setScale(sprite, create_vector2f(2, 2));
	sfRenderWindow_drawSprite(win, sprite, NULL);
	sfSprite_destroy(sprite);
}

intro_t *create_intro_str(void)
{
	intro_t *intro = malloc(sizeof(intro_t));

	if (intro == NULL)
		return (NULL);
	intro->bike = sfTexture_createFromFile(BIKE, NULL);
	intro->para1 = sfTexture_createFromFile(PARA_1, NULL);
	intro->para2 = sfTexture_createFromFile(PARA_2, NULL);
	intro->para3 = sfTexture_createFromFile(PARA_3, NULL);
	intro->para4 = sfTexture_createFromFile(PARA_4, NULL);
	intro->mew = sfTexture_createFromFile(MEW, NULL);
	intro->clock = sfClock_create();
	return (intro);
}

void destroy_intro(intro_t *intro)
{
	sfTexture_destroy(intro->bike);
	sfTexture_destroy(intro->para1);
	sfTexture_destroy(intro->para2);
	sfTexture_destroy(intro->para3);
	sfTexture_destroy(intro->para4);
	sfTexture_destroy(intro->mew);
	sfClock_destroy(intro->clock);
	free(intro);
}

int define_x_intro(intro_t *intro, int x)
{
	if (sfClock_getElapsedTime(intro->clock).microseconds >= 100000) {
		x++;
		sfClock_restart(intro->clock);
	}
	return (x);
}

void display_intro(game_t *game)
{
	intro_t *intro = create_intro_str();
	int x = 0;

	sfMusic_play(game->musics->cinematic);
	while (sfRenderWindow_isOpen(game->win)) {
		sfRenderWindow_clear(game->win, sfBlack);
		create_rect(intro->para4, create_vector2f(0, 0),
		create_vector2f(960, 640), game->win);
		x = define_x_intro(intro, x);
		intro_display(intro, x, game);
		sfRenderWindow_display(game->win);
		event_close(game->win);
		if (press_b(game))
			break;
	}
	sfMusic_stop(game->musics->cinematic);
	destroy_intro(intro);
}
