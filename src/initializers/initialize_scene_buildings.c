/*
** EPITECH PROJECT, 2018
** INITIALIZE_SCENE_BUILDINGS.C
** File description:
** Manages buildings in scenes
*/

#include "declaration.h"

int create_arena(int fd, scene_t *scene)
{
	char *line = NULL;
	char **pos = NULL;
	int x = 0;
	int y = 0;

	free(get_next_line(fd));
	if (str_iseq(line = get_next_line(fd), "NULL")) {
		epi_free(line);
		return (0);
	}
	pos = str_parse(line, ';');
	x = epi_atoi(pos[0]);
	y = epi_atoi(pos[1]);
	scene->arena_pos = create_vector2f(x, y);
	stra_free(pos);
	free(line);
	return (0);
}

int create_center(int fd, scene_t *scene)
{
	char *line = NULL;
	char **pos = NULL;
	int x = 0;
	int y = 0;

	free(get_next_line(fd));
	if (str_iseq(line = get_next_line(fd), "NULL")) {
		epi_free(line);
		return (0);
	}
	pos = str_parse(line, ';');
	x = epi_atoi(pos[0]);
	y = epi_atoi(pos[1]);
	scene->center_pos = create_vector2f(x, y);
	stra_free(pos);
	free(line);
	return (0);
}

int create_shop(int fd, scene_t *scene)
{
	char *line = NULL;
	char **pos = NULL;
	int x = 0;
	int y = 0;

	free(get_next_line(fd));
	if (str_iseq(line = get_next_line(fd), "NULL")) {
		epi_free(line);
		return (0);
	}
	pos = str_parse(line, ';');
	x = epi_atoi(pos[0]);
	y = epi_atoi(pos[1]);
	scene->shop_pos = create_vector2f(x, y);
	stra_free(pos);
	free(line);
	return (0);
}
