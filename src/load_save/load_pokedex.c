/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Rpg based on Pokemon
*/

#include "declaration.h"

void load_pokedex(int fd, pokemon_t *pokemons)
{
	char *line = get_next_line(fd);
	char *temp = line;

	do {
		if (*temp++ == '1')
			pokemons->is_discovered = 1;
	} while ((pokemons = pokemons->next));
	free(line);
}
