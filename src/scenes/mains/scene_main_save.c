/*
** EPITECH PROJECT, 2018
** main_save_menu
** File description:
** main_save_menu
*/

#include "declaration.h"

void create_text_save(sfFont *font, sfVector2f pos, char *sentence,
sfRenderWindow *window)
{
	int size = 15;
	sfText *text = sfText_create();

	sfText_setString(text, sentence);
	sfText_setPosition(text, pos);
	sfText_setCharacterSize(text, size);
	sfText_setFont(text, font);
	sfText_setColor(text, sfBlack);
	sfRenderWindow_drawText(window, text, NULL);
	sfText_destroy(text);
}

void display_new(game_t *game, int x)
{
	create_color_rect_in(sfWhite, create_vector2f(760, 100),
	create_vector2f(100, 400), game->win);
	if (x == 1)
		create_color_rect(sfCyan, create_vector2f(760, 100),
		create_vector2f(100, 400), game->win);
	create_text_start(game->texture->font, create_vector2f(130, 410),
	"NOUVELLE PARTIE", game->win);
}

void display_save(game_t *game, int save, int x)
{
	epi_free(get_next_line(save));
	create_color_rect_in(sfWhite, create_vector2f(760, 250),
	create_vector2f(100, 100), game->win);
	if (x == 0)
		create_color_rect(sfCyan, create_vector2f(760, 250),
		create_vector2f(100, 100), game->win);
	create_text_start(game->texture->font, create_vector2f(110, 110),
	"CONTINUER", game->win);
	create_text_save(game->texture->font, create_vector2f(150, 160),
	"JOUEUR", game->win);
	create_text_save(game->texture->font, create_vector2f(150, 210),
	"DUREE DE JEU", game->win);
	create_text_save(game->texture->font, create_vector2f(150, 260),
	"BADGES", game->win);
	create_text_save(game->texture->font, create_vector2f(150, 310),
	"POKEDEX", game->win);
	display_new(game, x);
}

int manage_event_save(int x, sfClock *clock)
{
	if (sfClock_getElapsedTime(clock).microseconds <= 100000)
		return (x);
	if (move_top() == sfTrue || move_bot() == sfTrue) {
		if (x == 1)
			x = 0;
		else if (x == 0)
			x = 1;
	}
	sfClock_restart(clock);
	return (x);
}

void save_menu(game_t *game)
{
	int save = open(".save", O_RDONLY);
	int x = 0;
	sfClock *clock = sfClock_create();

	if (save == -1) {
		start_new_game(game);
		switch_scene(game, game->scenes->cities[0]);
		sfClock_destroy(clock);
		return;
	}
	while (sfClock_getElapsedTime(clock).microseconds <= 500000);
	sfClock_restart(clock);
	display_save_loop(game, x, save, clock);
	sfClock_destroy(clock);
	close(save);
}
