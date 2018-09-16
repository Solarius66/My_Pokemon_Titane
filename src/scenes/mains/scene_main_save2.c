/*
** EPITECH PROJECT, 2018
** save2
** File description:
** save2
*/

#include "declaration.h"

void text_manager_save(game_t *game, int x)
{
	char *str[8] = {"Bien le bonjour!",
		"Bienvenue dans le monde magique des POKEMONS!",
		"Mon nom est HARRAULT, mais les gens m'appellent",
		"PROF JEREM!",
		"Parlons de toi, es-tu un garcon? ou une fille?",
		"Et quel est ton nom?",
		"Maintenant, choisis ton pokemon",
		"Fais deja atteindre le niveau 20 a ton pokemon"};

	text_displayer(game, str[x], false);
	if (x < 4 || x == 7)
		create_rect(game->texture->jerem, create_vector2f(305, 50),
		create_vector2f(400, 400), game->win);
	if (x == 4)
		define_gender_player(game);
	if (x == 5)
		define_name(game);
	if (x == 6)
		choose_starter(game);
}

void start_new_game(game_t *game)
{
	int x = 0;
	sfClock *clock = sfClock_create();

	sfMusic_play(game->musics->start);
	while (sfRenderWindow_isOpen(game->win) && x < 8) {
		sfRenderWindow_clear(game->win, sfBlack);
		create_rect(game->texture->start_b, create_vector2f(0, 0),
		create_vector2f(960, 440), game->win);
		text_manager_save(game, x);
		sfRenderWindow_display(game->win);
		if (press_b(game) &&
		sfClock_getElapsedTime(clock).microseconds >= 300000) {
			x++;
			sfClock_restart(clock);
		}
		event_close(game->win);
	}
	sfMusic_stop(game->musics->start);
	sfClock_destroy(clock);
}

void define_save_load(game_t *game, int fd, int x)
{
	if (x == 0)
		load_save(game, fd);
	else {
		start_new_game(game);
		switch_scene(game, game->scenes->cities[0]);
	}
}

void display_save_loop(game_t *game, int x, int fd, sfClock *clock)
{
	while (sfRenderWindow_isOpen(game->win)) {
		sfRenderWindow_clear(game->win, sfBlue);
		display_save(game, fd, x);
		sfRenderWindow_display(game->win);
		event_close(game->win);
		x = manage_event_save(x, clock);
		if (press_b(game)) {
			define_save_load(game, fd, x);
			break;
		}
	}
}
