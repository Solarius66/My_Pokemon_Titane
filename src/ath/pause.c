/*
** EPITECH PROJECT, 2018
** pause
** File description:
** pause dislayer
*/

#include "declaration.h"

void create_text_pause(sfFont *font, sfVector2f pos, char *sentence,
sfRenderWindow *window)
{
	int size = 20;
	sfText *text = sfText_create();

	sfText_setString(text, sentence);
	sfText_setPosition(text, pos);
	sfText_setCharacterSize(text, size);
	sfText_setFont(text, font);
	sfText_setColor(text, sfBlack);
	sfRenderWindow_drawText(window, text, NULL);
	sfText_destroy(text);
}

void display_icons(game_t *game, int cursor)
{
	sfVector2f pos[7] = {{650, 40}, {650, 120}, {650, 200},
		{650, 280}, {650, 360}, {650, 440}, {650, 520}};
	int x;

	create_rect(game->texture->pause_inv, create_vector2f(0, 0),
	create_vector2f(960, 640), game->win);
	create_text_pause(game->texture->font, create_vector2f(760, 310),
	game->player->name, game->win);
	create_color_rect(game->outline, create_vector2f(260, 80),
	create_vector2f(660, cursor * 80 + 40), game->win);
	for (int i = 0; i < 7; i++) {
		if (cursor != i)
			x = 0;
		else
			x = 1;
		create_rect(game->texture->icons_inv[i][x],
		pos[i], create_vector2f(90, 70), game->win);
	}
}

void define_window_inv(int cursor, game_t *game)
{
	if (cursor == 0 && press_b(game))
		pokedex_main(game);
	if (cursor == 1 && press_b(game))
		poke_inventory(game);
	if (cursor == 2 && press_b(game))
		bag_main(game);
	if (cursor == 3 && press_b(game))
		player_card(game);
	if (cursor == 4 && press_b(game))
		save(game);
	if (cursor == 5 && press_b(game))
		option_main(game);
}

int define_cursor(int cursor, sfClock *clock)
{
	sfInt64 time = sfClock_getElapsedTime(clock).microseconds;

	if (time <= 100000)
		return (cursor);
	if (move_top() == sfTrue) {
		if (cursor == 0)
			cursor = 6;
		else
			cursor--;
	}
	if (move_bot() == sfTrue) {
		if (cursor == 6)
			cursor = 0;
		else
			cursor++;
	}
	sfClock_restart(clock);
	return (cursor);
}

void pause_menu(game_t *game)
{
	int cursor = 0;
	sfClock *clock = sfClock_create();
	sfTexture *map = sfTexture_create(960, 640);

	sfTexture_updateFromRenderWindow(map, game->win, 0, 0);
	while (sfRenderWindow_isOpen(game->win)) {
		sfRenderWindow_clear(game->win, sfBlack);
		create_rect(map, create_vector2f(0, 0),
		create_vector2f(960, 640), game->win);
		cursor = define_cursor(cursor, clock);
		display_icons(game, cursor);
		define_window_inv(cursor, game);
		if (press_a() == sfTrue ||
			(cursor == 6 && press_b(game) == sfTrue))
			break;
		sfRenderWindow_display(game->win);
		event_close(game->win);
	}
	sfClock_destroy(clock);
	sfTexture_destroy(map);
}
