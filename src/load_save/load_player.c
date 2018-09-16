/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Rpg based on Pokemon
*/

#include "declaration.h"

void load_pokemon(int fd, pokemon_t **pokemon, pokemon_t *all_pokemons)
{
	int id = load_int(fd);
	int level;
	int health;
	int xp;

	level = load_int(fd);
	health = load_int(fd);
	xp = load_int(fd);
	*pokemon = pokemon_dup_by_id(id, level, all_pokemons);
	(*pokemon)->cur_health = health;
	(*pokemon)->xp = xp;
}

void load_pokemons(int fd, pokemon_t **pokemons, pokemon_t *all_pokemons)
{
	int pokemons_nb = load_int(fd);
	int i = 0;

	while (i != pokemons_nb) {
		load_pokemon(fd, pokemons + i, all_pokemons);
		++i;
	}
}

void clean_get_next_line(int fd)
{
	char *temp = NULL;

	while ((temp = get_next_line(fd)))
		epi_free(temp);
}

void load_position(int fd, player_t *player)
{
	int temp1 = load_int(fd);
	int temp2 = load_int(fd);

	player->position = create_vector2f(temp1, temp2);
}

void load_player(int fd, game_t *game)
{
	game->player->name = get_next_line(fd);
	game->player->gender = load_int(fd);
	game->player->money = load_int(fd);
	game->player->playtime_hours = load_int(fd);
	game->player->playtime_minutes = load_int(fd);
	game->player->look_tile = load_int(fd);
	game->player->badges = load_int(fd);
	game->player->texture =
	game->player->gender ? game->texture->woman : game->texture->man;
	load_position(fd, game->player);
	change_scene(game, fd);
	load_pokemons(fd, game->player->pokemons, game->pokemons);
}
