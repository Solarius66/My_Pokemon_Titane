/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Rpg based on Pokemon
*/

#include "declaration.h"

int load_int(int fd)
{
	char *line = get_next_line(fd);
	int nb = epi_atoi(line);

	free(line);
	return nb;
}

void load_save(game_t *game, int fd)
{
	clean_get_next_line(fd);
	fd = open(".save", O_RDONLY);
	load_player(fd, game);
	load_color(fd, game);
	load_settings(fd, game->settings);
	load_bag(fd, game->bag);
	load_pokedex(fd, game->pokemons);
	close(fd);
}
