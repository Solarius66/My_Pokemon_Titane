/*
** EPITECH PROJECT, 2018
** DESTRUCT_GAME.C
** File description:
** Destruct game structure
*/

#include "declaration.h"

int destroy_settings(game_t *game)
{
	if (!game->settings)
		return (0);
	game->settings->current_volume = 0;
	free(game->settings);
	return (0);
}

int destroy_progress(game_t *game)
{
	sfVector2f end_pos = { .x = 0, .y = 0 };

	if (!game->progress)
		return (0);
	game->progress->current_progress = 0;
	game->progress->current_map = NULL;
	game->progress->current_pos = end_pos;
	game->progress->discovered_pokemons_count = 0;
	if (game->progress->discovered_pokemons)
		free(game->progress->discovered_pokemons);
	free(game->progress);
	return (0);
}

int destroy_bag(game_t *game)
{
	if (!game->bag)
		return (0);
	game->bag->default_potions = 0;
	game->bag->super_potions = 0;
	game->bag->hyper_potions = 0;
	game->bag->total_heal_potions = 0;
	game->bag->pokeballs = 0;
	game->bag->superballs = 0;
	game->bag->hyperballs = 0;
	game->bag->masterballs = 0;
	free(game->bag);
	return (0);
}

int destroy_pc(game_t *game)
{
	if (!game->pc)
		return (0);
	if (game->pc->storage)
		free(game->pc->storage);
	free(game->pc);
	return (0);
}

int destroy_game(game_t *game)
{
	destroy_settings(game);
	destroy_progress(game);
	destroy_bag(game);
	destroy_pc(game);
	destroy_player(game);
	destroy_scenes(game);
	destroy_window(game);
	destroy_musics(game);
	free(game);
	return (0);
}
