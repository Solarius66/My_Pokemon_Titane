/*
** EPITECH PROJECT, 2018
** DESTROY_GAME_2.C
** File description:
** Extension of destroy_game.c file
*/

#include "declaration.h"

int destroy_player(game_t *game)
{
	if (!game->player)
		return (0);
	epi_free(game->player->name);
	for (int i = 0; i < 7; i++) {
		if (game->player->pokemons[i])
			destruct_pokemon(game->player->pokemons[i]);
	}
	if (game->player->pokemons)
		free(game->player->pokemons);
	sfClock_destroy(game->player->move_c);
	sfClock_destroy(game->player->walk_c);
	free(game->player);
	return (0);
}

int destroy_musics(game_t *game)
{
	if (!game->musics)
		return (0);
	sfMusic_destroy(game->musics->intro);
	sfMusic_destroy(game->musics->cinematic);
	sfMusic_destroy(game->musics->start);
	sfMusic_destroy(game->musics->city);
	sfMusic_destroy(game->musics->road);
	sfMusic_destroy(game->musics->cave);
	sfMusic_destroy(game->musics->snow);
	sfMusic_destroy(game->musics->ligue);
	sfMusic_destroy(game->musics->victory);
	sfMusic_destroy(game->musics->end);
	sfMusic_destroy(game->musics->volcano);
	sfMusic_destroy(game->musics->fight_salvage);
	sfMusic_destroy(game->musics->fight_trainer);
	free(game->musics);
	return (0);
}

int free_scene(scene_t *scene)
{
	if (!scene)
		return (0);
	if (!scene->name && !epi_free(scene))
		return (0);
	free(scene->name);
	epi_ddestroy(scene->layers);
	epi_free(scene->npcs);
	epi_free(scene->interface);
	sfTexture_destroy(scene->layer_ground);
	sfTexture_destroy(scene->layer_col);
	sfTexture_destroy(scene->layer_top);
	epi_free(scene->north_dest);
	epi_free(scene->south_dest);
	epi_free(scene->west_dest);
	epi_free(scene->east_dest);
	epi_free(scene->pokemons);
	epi_free(scene->scene_type);
	free(scene);
	return (0);
}

int destroy_scenes(game_t *game)
{
	if (!game->scenes)
		return (0);
	for (int i = 0; i < 4; i++)
		free_scene(game->scenes->zones[i]);
	for (int i = 0; i < 8; i++)
		free_scene(game->scenes->cities[i]);
	for (int i = 0; i < 9; i++)
		free_scene(game->scenes->roads[i]);
	free(game->scenes->zones);
	free(game->scenes->roads);
	free(game->scenes->cities);
	free(game->scenes);
	return (0);
}

int destroy_window(game_t *game)
{
	if (!game->win)
		return (0);
	sfRenderWindow_destroy(game->win);
	game->outline = sfWhite;
	return (0);
}
