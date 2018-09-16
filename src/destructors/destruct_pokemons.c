/*
** EPITECH PROJECT, 2018
** DESTRUCT_POKEMONS.C
** File description:
** Destructs pokemons of RPokémonG
*/

#include "declaration.h"

void destruct_pokemon(pokemon_t *pkm)
{
	epi_free(pkm->name);
	epi_free(pkm);
}

int destruct_pokemons(game_t *game)
{
	pokemon_t *tmp = game->pokemons;

	if (tmp == NULL)
		return (0);
	if (tmp->next == NULL) {
		free(tmp->name);
		free(game->pokemons);
		game->pokemons = NULL;
		return (0);
	}
	for (; tmp->next->next != NULL; tmp = tmp->next);
	if (tmp->next->name != NULL)
		free(tmp->next->name);
	free(tmp->next);
	tmp->next = NULL;
	destruct_pokemons(game);
	return (0);
}
