/*
** EPITECH PROJECT, 2018
** CONFIG_STATIC_DATA.C
** File description:
** Configures a scene using config file
*/

#include "declaration.h"

void get_ground_layer(scene_t *scene, FILE *stream)
{
	size_t len = 1;
	ssize_t read = 0;
	char *line = NULL;
	int y = 0;

	do {
		read = getline(&line, &len, stream);
		if (epi_compare_str(line, "COL:\n") == 1)
		break;
		for (int x = 0; x < read; x++, y++)
			scene->layers[0][y] = line[x];
	} while (epi_compare_str(line, "COL:\n") == 0);
	free(line);
}

void get_col_layer(scene_t *scene, FILE *stream)
{
	size_t len = 1;
	ssize_t read = 0;
	char *line = NULL;
	int y = 0;

	do {
		read = getline(&line, &len, stream);
		if (epi_compare_str(line, "TOP:\n") == 1)
		break;
		for (int x = 0; x < read; x++, y++)
			scene->layers[1][y] = line[x];
	} while (epi_compare_str(line, "TOP:\n") == 0);
	free(line);
}

void get_top_layer(scene_t *scene, FILE *stream)
{
	size_t len = 1;
	ssize_t read = 0;
	char *line = NULL;
	int y = 0;

	do {
		read = getline(&line, &len, stream);
		if (epi_compare_str(line, "END\n") == 1)
		break;
		for (int x = 0; x < read; x++, y++)
			scene->layers[2][y] = line[x];
	} while (epi_compare_str(line, "END\n") == 0);
	free(line);
}

void get_layers(scene_t *scene, int size, FILE *stream)
{
	size_t len = 1;
	char *line = NULL;

	scene->layers = malloc(sizeof(char *) * 3);
	scene->layers[0] = epi_malloc(size);
	scene->layers[1] = epi_malloc(size);
	scene->layers[2] = epi_malloc(size);
	getline(&line, &len, stream);
	get_ground_layer(scene, stream);
	get_col_layer(scene, stream);
	get_top_layer(scene, stream);
	free(line);
}

void config_static_data(scene_t *scene, char *config, game_scenes type)
{
	struct stat map_stat;
	FILE *stream = fopen(config, "r");
	size_t len = 1;
	ssize_t read = 0;
	int size = 0;
	char *line = NULL;

	stat(config, &map_stat);
	size = map_stat.st_size;
	read = getline(&line, &len, stream);
	line[read - 1] = '\0';
	scene->type = type;
	scene->map_file = config;
	scene->name = epi_remalloc(line, -1);
	scene->map_size = size;
	get_layers(scene, size, stream);
	free(line);
	fclose(stream);
}
