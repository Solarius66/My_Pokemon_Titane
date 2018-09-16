/*
** EPITECH PROJECT, 2018
** my_RPokemonG
** File description:
** the bush file
*/

#include "declaration.h"

void launch_savage_combat(game_t *game)
{
	int poney;
	int i;
	player_t *pkm = malloc(sizeof(player_t));

	pkm->pokemons = malloc(sizeof(pokemon_t *) * 6);
	for (int j = 0; j < 6; ++j)
		pkm->pokemons[j] = NULL;
	for (i = 0; game->cur_scene->pokemons[i] != -1; ++i);
	poney = rand() % i;
	pkm->pokemons[0] = pokemon_dup_by_id(game->cur_scene->pokemons[poney],
	game->cur_scene->median_level + (rand() % 6 - 5),
	game->pokemons);
	pkm->actual = 0;
	pkm->name = epi_putf("Wild");
	combat_loop(game, game->player, pkm);
	epi_free(pkm->name);
	destruct_pokemon(pkm->pokemons[0]);
	epi_free(pkm->pokemons);
	epi_free(pkm);
}

void bushes_gest(game_t *game)
{
	char **map = epi_split(game->cur_scene->layers[1], '\n');
	sfVector2i pos = {game->player->position.x, game->player->position.y};
	char actual_tile = map[pos.y + 10][pos.x + 15];
	int poney = rand() % 25;

	epi_ddestroy(map);
	if ((epi_compare_str(game->cur_scene->name, "ROUTE 6") ||
	epi_compare_str(game->cur_scene->name, "ROUTE VICTOIRE") ||
	actual_tile == '|') && poney == 1) {
		launch_savage_combat(game);
	}
}
