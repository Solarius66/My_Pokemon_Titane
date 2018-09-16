/*
** EPITECH PROJECT, 2018
** INITIALIZE_GAME.C
** File description:
** Initializes game structure
*/

#include "declaration.h"

int initialize_settings(game_t *game)
{
	sfColor base_color = { .r = 255, .g = 0, .b = 0, .a = 255 };

	game->settings = malloc(sizeof(settings_t));
	if (!game->settings)
		return (84);
	game->settings->current_volume = 50;
	game->outline = base_color;
	return (0);
}

int initialize_progress(game_t *game)
{
	sfVector2f base_pos = { .x = 0, .y = 0 };

	game->progress = malloc(sizeof(progress_t));
	if (!game->progress)
		return (84);
	game->progress->current_progress = 0;
	game->progress->current_map = NULL;
	game->progress->current_pos = base_pos;
	game->progress->discovered_pokemons_count = 0;
	game->progress->discovered_pokemons = NULL;
	return (0);
}

int initialize_bag(game_t *game)
{
	game->bag = malloc(sizeof(bag_t));
	if (!game->bag)
		return (84);
	game->bag->default_potions = 0;
	game->bag->super_potions = 0;
	game->bag->hyper_potions = 0;
	game->bag->total_heal_potions = 0;
	game->bag->total_heal = 0;
	game->bag->pokeballs = 0;
	game->bag->superballs = 0;
	game->bag->hyperballs = 0;
	game->bag->masterballs = 0;
	game->bag->honorballs = 0;
	return (0);
}

int initialize_game_extended(game_t *game)
{
	if (initialize_player(game) == 84)
		return (84);
	if (initialize_scenes(game) == 84)
		return (84);
	if (initialize_window(game) == 84)
		return (84);
	if (initialize_music(game) == 84)
		return (84);
	return (0);
}

game_t *initialize_game(void)
{
	game_t *game = malloc(sizeof(game_t));

	if (!game)
		return (NULL);
	if (initialize_settings(game) == 84)
		return (NULL);
	if (initialize_progress(game) == 84)
		return (NULL);
	if (initialize_bag(game) == 84)
		return (NULL);
	if (initialize_pc(game) == 84)
		return (NULL);
	if (initialize_game_extended(game) == 84)
		return (NULL);
	game->cur_scene = NULL;
	return (game);
}
