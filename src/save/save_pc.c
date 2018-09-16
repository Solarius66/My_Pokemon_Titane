/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Rpg based on Pokemon
*/

#include "declaration.h"

void save_pc(int fd, pc_t *pc)
{
	save_pokemons(fd, pc->storage);
}
