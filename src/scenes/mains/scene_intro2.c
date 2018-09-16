/*
** EPITECH PROJECT, 2018
** intro_displayer.c
** File description:
** display intro scene
*/

#include "declaration.h"

void display_parallax_hill(sfTexture *texture, int x, sfRenderWindow *win)
{
	create_rect(texture, create_vector2f(x % 960, 0),
	create_vector2f(960, 640), win);
	create_rect(texture, create_vector2f(-960 + x % 960, 0),
	create_vector2f(960, 640), win);
}

void display_parallax_tree(sfTexture *texture, int x, sfRenderWindow *win)
{
	create_rect(texture, create_vector2f(x % 480 * 2, 0),
	create_vector2f(960, 640), win);
	create_rect(texture, create_vector2f(-960 + (x % 480 * 2), 0),
	create_vector2f(960, 640), win);
}

void display_parallax_bush(sfTexture *texture, int x, sfRenderWindow *win)
{
	create_rect(texture, create_vector2f(x % 240 * 4, 0),
	create_vector2f(960, 640), win);
	create_rect(texture, create_vector2f(-960 + (x % 240 * 4), 0),
	create_vector2f(960, 640), win);
}

void display_bike_intro(sfTexture *texture, int x, sfRenderWindow *win)
{
	sfSprite *sprite = create_sprite(texture,
	create_vector2f((960 - x % 960), 400),
	create_int_rect(0, 92 * ((x % 50) % 3), 92, 92));

	sfSprite_setScale(sprite, create_vector2f(2, 2));
	sfRenderWindow_drawSprite(win, sprite, NULL);
	sfSprite_destroy(sprite);
}

void intro_display(intro_t *intro, int x, game_t *game)
{
	display_parallax_hill(intro->para3, x, game->win);
	display_parallax_tree(intro->para2, x, game->win);
	display_parallax_bush(intro->para1, x, game->win);
	display_bike_intro(intro->bike, x, game->win);
	display_mew_intro(intro->mew, x, game->win);
}
