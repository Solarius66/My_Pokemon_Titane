/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Rpg based on Pokemon
*/

#include "declaration.h"

void load_pc(int fd, pc_t *pc, pokemon_t *all_pokemons)
{
	load_pokemons(fd, pc->storage, all_pokemons);
}
