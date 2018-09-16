/*
** EPITECH PROJECT, 2018
** my RPokemonG
** File description:
** load scene
*/

#include "declaration.h"

int change_scene(game_t *game, int fd)
{
	char *str = get_next_line(fd);

	for (int i = 0; i < 4; ++i)
		if (epi_compare_str(game->scenes->zones[i]->name, str)) {
			switch_scene(game, game->scenes->zones[i]);
			return (epi_free(str));
		}
	for (int i = 0; i < 9; ++i)
		if (epi_compare_str(game->scenes->roads[i]->name, str)) {
			switch_scene(game, game->scenes->roads[i]);
			return (epi_free(str));
		}
	for (int i = 0; i < 8; ++i)
		if (epi_compare_str(game->scenes->cities[i]->name, str)) {
			switch_scene(game, game->scenes->cities[i]);
			return (epi_free(str));
		}
	switch_scene(game, game->scenes->cities[0]);
	return (epi_free(str));
}
