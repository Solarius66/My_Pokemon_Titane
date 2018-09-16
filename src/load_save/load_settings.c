/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Rpg based on Pokemon
*/

#include "declaration.h"

void load_color(int fd, game_t *game)
{
	char *line;

	game->outline.r = epi_atoi(line = get_next_line(fd));
	free(line);
	game->outline.g = epi_atoi(line = get_next_line(fd));
	free(line);
	game->outline.b = epi_atoi(line = get_next_line(fd));
	free(line);
	game->outline.a = epi_atoi(line = get_next_line(fd));
	free(line);
}

void load_settings(int fd, settings_t *settings)
{
	char *line;

	settings->current_volume = epi_atoi(line = get_next_line(fd));
	free(line);
}
