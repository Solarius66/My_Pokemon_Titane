/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Rpg based on Pokemon
*/

#include "declaration.h"

void save_color(int fd, sfColor c)
{
	epi_dprintf(fd, "%d\n%d\n%d\n%d\n", c.r, c.g, c.b, c.a);
}

void save_settings(int fd, settings_t *settings)
{
	epi_dprintf(fd, "%d\n", settings->current_volume);
}
