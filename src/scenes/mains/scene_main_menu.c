/*
** EPITECH PROJECT, 2018
** SCENE_MAIN_MENU.C
** File description:
** Manages menu scene from main scope
*/

#include "declaration.h"

void create_text_start(sfFont *font, sfVector2f pos, char *sentence,
sfRenderWindow *window)
{
	int size = 30;
	sfText *text = sfText_create();

	sfText_setString(text, sentence);
	sfText_setPosition(text, pos);
	sfText_setCharacterSize(text, size);
	sfText_setFont(text, font);
	sfText_setColor(text, sfBlue);
	sfText_setStyle(text, sfTextBold);
	sfRenderWindow_drawText(window, text, NULL);
	sfText_destroy(text);
}

void main_menu_display(game_t *game, int x)
{
	create_rect(game->texture->start_back, create_vector2f(0, 0),
	create_vector2f(960, 640), game->win);
	create_rect(game->texture->start_move2,
	create_vector2f(0, 640 - 4 * x),
	create_vector2f(960, 450), game->win);
	create_rect(game->texture->start_move1,
	create_vector2f(0, 240 - 3 * x),
	create_vector2f(960, 1050), game->win);
	create_rect(game->texture->start_top, create_vector2f(0, 0),
	create_vector2f(960, 640), game->win);
	if (x / 55 % 2 == 1) {
		create_text_start(game->texture->font,
		create_vector2f(50, 450),
		" APPUYEZ SUR\n\nFLECHE DROITE", game->win);
		create_text_inv(game->texture->font, create_vector2f(400, 620),
		"COMMANDES : APPUYEZ SUR FLECHE GAUCHE", game->win);
	}
	if (press_x())
		create_rect(game->texture->controls, create_vector2f(0, 0),
		create_vector2f(960, 640), game->win);
}

int x_management_main_menu(int x, sfClock *clock, sfClock *intro_c,
game_t *game)
{
	if (sfClock_getElapsedTime(clock).microseconds >= 10000) {
		x++;
		sfClock_restart(clock);
	}
	if (x >= 273)
		x = 0;
	if (sfClock_getElapsedTime(intro_c).microseconds >= 10000000) {
		sfMusic_stop(game->musics->intro);
		display_intro(game);
		sfClock_restart(intro_c);
		sfMusic_play(game->musics->intro);
		while (press_b(game));
	}
	return (x);
}

void load_scene_main_menu(game_t *game)
{
	sfClock *clock = sfClock_create();
	sfClock *intro_c = sfClock_create();
	int x = 0;

	sfMusic_play(game->musics->intro);
	while (sfRenderWindow_isOpen(game->win)) {
		sfRenderWindow_clear(game->win, sfWhite);
		main_menu_display(game, x);
		sfRenderWindow_display(game->win);
		x = x_management_main_menu(x, clock, intro_c, game);
		event_close(game->win);
		if (press_b(game) == sfTrue)
			break;
	}
	sfClock_destroy(clock);
	sfClock_destroy(intro_c);
	sfMusic_stop(game->musics->intro);
	save_menu(game);
}
