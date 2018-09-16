/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Rpg based on Pokemon
*/

#include "declaration.h"

void save_bag(int fd, bag_t *bag)
{
	epi_dprintf(fd, "%d\n", bag->default_potions);
	epi_dprintf(fd, "%d\n", bag->super_potions);
	epi_dprintf(fd, "%d\n", bag->hyper_potions);
	epi_dprintf(fd, "%d\n", bag->total_heal_potions);
	epi_dprintf(fd, "%d\n", bag->pokeballs);
	epi_dprintf(fd, "%d\n", bag->superballs);
	epi_dprintf(fd, "%d\n", bag->hyperballs);
	epi_dprintf(fd, "%d\n", bag->masterballs);
}
