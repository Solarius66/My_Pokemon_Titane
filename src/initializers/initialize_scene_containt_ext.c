/*
** EPITECH PROJECT, 2018
** INITIALIZE_GAME_5.C
** File description:
** Initialies items in scene (trainers and so on)
*/

#include "declaration.h"

int create_trainers(int fd, scene_t *scene)
{
	char *line = NULL;
	char **trainers = NULL;

	free(get_next_line(fd));
	if (str_iseq(line = get_next_line(fd), "NULL")) {
		epi_free(line);
		return (0);
	}
	trainers = str_parse(line, ';');
	scene->trainers = inta_malloc(stra_len(trainers));
	for (int i = 0; trainers[i] != NULL; i++)
		scene->trainers[i] = epi_atoi(trainers[i]);
	stra_free(trainers);
	free(line);
	return (0);
}

int create_bushes(int fd, scene_t *scene)
{
	char *line = NULL;
	char **parsed = NULL;
	char **pokemons = NULL;

	free(get_next_line(fd));
	if (str_iseq(line = get_next_line(fd), "NULL")) {
		epi_free(line);
		return (0);
	}
	parsed = str_parse(line, ':');
	scene->median_level = epi_atoi(parsed[0]);
	pokemons = str_parse(parsed[1], ';');
	scene->pokemons = inta_malloc(stra_len(pokemons));
	for (int i = 0; pokemons[i] != NULL; i++)
		scene->pokemons[i] = epi_atoi(pokemons[i]);
	stra_free(parsed);
	stra_free(pokemons);
	free(line);
	return (0);
}

int create_signs(int fd, scene_t *scene)
{
	char *line = NULL;
	char **signs = NULL;

	free(get_next_line(fd));
	if (str_iseq(line = get_next_line(fd), "NULL")) {
		epi_free(line);
		return (0);
	}
	signs = str_parse(line, ':');
	scene->signs = inta_malloc(stra_len(signs));
	for (int i = 0; signs[i] != NULL; i++)
		scene->signs[i] = epi_atoi(signs[i]);
	stra_free(signs);
	free(line);
	return (0);
}

int create_objects(int fd, scene_t *scene)
{
	char *line = NULL;

	create_trainers(fd, scene);
	create_bushes(fd, scene);
	create_signs(fd, scene);
	create_arena(fd, scene);
	create_center(fd, scene);
	create_shop(fd, scene);
	scene->interface = NULL;
	while ((line = get_next_line(fd)) != NULL)
		epi_free(line);
	return (0);
}
