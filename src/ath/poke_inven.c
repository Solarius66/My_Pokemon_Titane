/*
** EPITECH PROJECT, 2018
** maiun
** File description:
** main
*/

#include "declaration.h"

void display_line_pokemon(sfVector2i cursor, sfTexture **texture,
sfRenderWindow *window, int x)
{
	for (int y = 0; y <= 2; y++) {
		if (cursor.x == x && cursor.y == y)
			create_rect(texture[1], create_vector2f(200 + 450 * x,
			100 + 150 * y), create_vector2f(256, 128), window);
		else
			create_rect(texture[0], create_vector2f(200 + 450 * x,
			100 + 150 * y), create_vector2f(256, 128), window);
	}
}

void display_pokemon_ath(sfTexture **texture, sfRenderWindow *window,
sfVector2i cursor)
{
	for (int x = 0; x <= 1; x++) {
		display_line_pokemon(cursor, texture, window, x);
	}
}

void display_ath(texture_t *textures, sfRenderWindow *window, sfVector2i cur)
{

	int x = 0;

	if (cur.x == 2 || cur.y == 3)
		x = 1;
	create_rect(textures->font_inv, create_vector2f(0, 0),
	create_vector2f(960, 640), window);
	create_rect(textures->exit[x], create_vector2f(820, 590),
	create_vector2f(125, 38), window);
	display_pokemon_ath(textures->poke_inv, window, cur);
}

sfVector2i input_management(sfVector2i cursor, sfClock *clock)
{
	if (sfClock_getElapsedTime(clock).microseconds <= 150000)
		return (cursor);
	if (move_top() == sfTrue)
		cursor.y--;
	if (move_bot() == sfTrue)
		cursor.y++;
	if (move_right() == sfTrue)
		cursor.x++;
	if (move_left() == sfTrue)
		cursor.x--;
	if (cursor.x > 1)
		cursor.x = 0;
	if (cursor.x < 0)
		cursor.x = 1;
	if (cursor.y > 3)
		cursor.y = 0;
	if (cursor.y < 0)
		cursor.y = 3;
	sfClock_restart(clock);
	return (cursor);
}

void poke_inventory(game_t *game)
{
	sfClock *clock = sfClock_create();
	sfClock *anim = sfClock_create();
	sfVector2i cursor = {0, 0};

	while (sfRenderWindow_isOpen(game->win)) {
		sfRenderWindow_clear(game->win, sfBlack);
		display_ath(game->texture, game->win, cursor);
		display_pokemon(game, game->win, anim);
		create_text_inv(game->texture->font,
		create_vector2f(860, 600), "QUIT", game->win);
		sfRenderWindow_display(game->win);
		cursor = input_management(cursor, clock);
		event_close(game->win);
		if (press_a() || (cursor.y == 3 && press_b(game)))
			break;
	}
	sfClock_restart(clock);
	while (sfClock_getElapsedTime(clock).microseconds <= 500000);
	sfClock_destroy(clock);
	sfClock_destroy(anim);
}
