/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Rpg based on Pokemon
*/

#include "declaration.h"

void save_pokedex(int fd, pokemon_t *pokemons)
{
	do {
		if (pokemons->is_discovered) {
			write(fd, "1", 1);
		} else {
			write(fd, "0", 1);
		}
	} while ((pokemons = pokemons->next));
	write(fd, "\n", 1);
}
