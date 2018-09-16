/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Rpg based on Pokemon
*/

#include "declaration.h"

void load_bag(int fd, bag_t *bag)
{
	char *line;

	bag->default_potions = epi_atoi(line = get_next_line(fd));
	free(line);
	bag->super_potions = epi_atoi(line = get_next_line(fd));
	free(line);
	bag->hyper_potions = epi_atoi(line = get_next_line(fd));
	free(line);
	bag->total_heal_potions = epi_atoi(line = get_next_line(fd));
	free(line);
	bag->pokeballs = epi_atoi(line = get_next_line(fd));
	free(line);
	bag->superballs = epi_atoi(line = get_next_line(fd));
	free(line);
	bag->hyperballs = epi_atoi(line = get_next_line(fd));
	free(line);
	bag->masterballs = epi_atoi(line = get_next_line(fd));
	free(line);
}
