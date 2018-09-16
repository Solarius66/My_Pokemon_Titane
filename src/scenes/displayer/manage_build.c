/*
** EPITECH PROJECT, 2018
** manage_build
** File description:
** manage builds
*/

#include "declaration.h"

void heal_pokemons(player_t *p1, game_t *game)
{
	for (int x = 0; x < 6; x++)
		if (p1->pokemons[x] != NULL)
			p1->pokemons[x]->cur_health =
			p1->pokemons[x]->max_health;
	while (press_b(game));
	text_displayer(game, "Vos pokemons ont ete soignes", false);
	sfRenderWindow_display(game->win);
	while (!press_b(game));
}

void display_map_ath(game_t *game)
{
	sfTexture *map = sfTexture_create(960, 640);

	sfTexture_updateFromRenderWindow(map, game->win, 0, 0);
	create_rect(map, create_vector2f(0, 0), create_vector2f(960, 640),
	game->win);
	sfTexture_destroy(map);
}

void poke_center_management(game_t *game)
{
	int x = 0;
	sfClock *clock = sfClock_create();

	while (press_b(game));
	while (sfRenderWindow_isOpen(game->win)) {
		map_displayer_main(game, false);
		text_displayer(game, "Voulez vous soigner vous pokemons?",
		true);
		display_question_save(game, x);
		sfRenderWindow_display(game->win);
		x = define_x_save(x, clock);
		event_close(game->win);
		if (press_b(game))
			break;
	}
	if (x == 1)
		heal_pokemons(game->player, game);
	sfClock_destroy(clock);
	while (press_b(game));
}
