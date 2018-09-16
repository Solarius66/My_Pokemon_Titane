/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Rpg based on Pokemon
*/

#include "declaration.h"

void save_pokemon(int fd, pokemon_t *pokemon)
{
	epi_dprintf(fd, "%d\n", pokemon->id);
	epi_dprintf(fd, "%d\n", pokemon->lvl);
	epi_dprintf(fd, "%d\n", pokemon->cur_health);
	epi_dprintf(fd, "%d\n", pokemon->xp);
}

void save_pokemons(int fd, pokemon_t **pokemons)
{
	int pokemon_nb = 0;

	while (pokemons[pokemon_nb])
		++pokemon_nb;
	epi_dprintf(fd, "%d\n", pokemon_nb);
	for (int i = 0; pokemons[i]; ++i)
		save_pokemon(fd, pokemons[i]);
}

void save_player(int fd, player_t *player, game_t *game)
{
	epi_dprintf(fd, "%s\n", player->name);
	epi_dprintf(fd, "%d\n", (int) player->gender);
	epi_dprintf(fd, "%d\n", player->money);
	epi_dprintf(fd, "%d\n", player->playtime_hours);
	epi_dprintf(fd, "%d\n", player->playtime_minutes);
	epi_dprintf(fd, "%d\n", player->look_tile);
	epi_dprintf(fd, "%d\n", player->badges);
	epi_dprintf(fd, "%d\n", (int) player->position.x);
	epi_dprintf(fd, "%d\n", (int) player->position.y);
	epi_dprintf(fd, "%s\n", game->cur_scene->name);
	save_pokemons(fd, player->pokemons);
}
