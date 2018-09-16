/*
** EPITECH PROJECT, 2018
** INITIALIZE_GAME_4.C
** File description:
** Initializes maps of the game
*/

#include "declaration.h"

void fill_layers(int fd, char **layers, int size)
{
	fill_layer_ground(fd, layers, size);
	fill_layer_col(fd, layers, size);
	fill_layer_top(fd, layers, size);
}

int create_textures(int fd, scene_t *scene)
{
	sfTexture *ground = NULL;
	sfTexture *col = NULL;
	sfTexture *top = NULL;
	char *tmp = NULL;

	tmp = get_next_line(fd);
	ground = sfTexture_createFromFile(tmp, NULL);
	epi_free(tmp);
	tmp = get_next_line(fd);
	col = sfTexture_createFromFile(tmp, NULL);
	epi_free(tmp);
	tmp = get_next_line(fd);
	top = sfTexture_createFromFile(tmp, NULL);
	epi_free(tmp);
	scene->layer_ground = ground;
	scene->layer_col = col;
	scene->layer_top = top;
	return (0);
}

int create_entries_extended(int fd, scene_t *scene)
{
	char *west = get_next_line(fd);
	char *east = get_next_line(fd);
	char **west_a = epi_split(west, ';');
	char **east_a = epi_split(east, ';');

	scene->west.x = epi_atoi(west_a[1]);
	scene->west.y = epi_atoi(west_a[2]);
	scene->east.x = epi_atoi(east_a[1]);
	scene->east.y = epi_atoi(east_a[2]);
	stra_free(west_a);
	stra_free(east_a);
	free(west);
	free(east);
	return (0);
}

int create_entries(int fd, scene_t *scene)
{
	char *north = get_next_line(fd);
	char *south = get_next_line(fd);
	char **north_a = str_parse(north, ';');
	char **south_a = str_parse(south, ';');

	scene->north.x = epi_atoi(north_a[1]);
	scene->north.y = epi_atoi(north_a[2]);
	scene->south.x = epi_atoi(south_a[1]);
	scene->south.y = epi_atoi(south_a[2]);
	stra_free(north_a);
	stra_free(south_a);
	free(north);
	free(south);
	create_entries_extended(fd, scene);
	return (0);
}

int initialize_scene(char *path, scene_t *scene)
{
	struct stat map_stat;
	int fd = -1;

	if ((fd = open(path, O_RDONLY)) < 0)
		return (2);
	stat(path, &map_stat);
	create_default_scene(scene);
	scene->name = get_next_line(fd);
	scene->map_file = path;
	scene->map_size = map_stat.st_size;
	if ((scene->layers = malloc(sizeof(char *) * 4)) == NULL)
		return (0);
	scene->layers[3] = NULL;
	fill_layers(fd, scene->layers, scene->map_size);
	create_scene_properties(scene);
	create_textures(fd, scene);
	create_entries(fd, scene);
	create_entrances(fd, scene);
	create_objects(fd, scene);
	close(fd);
	return (1);
}
