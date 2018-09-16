/*
** EPITECH PROJECT, 2018
** INITIALIZE_LAYERS.C
** File description:
** Initializes each layer of given scene
*/

#include "declaration.h"

void fill_layer_ground(int fd, char **layers, int size)
{
	char *line = NULL;

	layers[0] = epi_malloc(size);
	epi_free(get_next_line(fd));
	for (int i = 0;; i++) {
		line = get_next_line(fd);
		if (str_iseq(line, "COL:")) {
			epi_free(line);
			break;
		}
		for (int j = 0; j < str_len(line); i++, j++)
			layers[0][i] = line[j];
		epi_free(line);
		layers[0][i] = '\n';
	}
}

void fill_layer_col(int fd, char **layers, int size)
{
	char *line = NULL;

	layers[1] = epi_malloc(size);
	for (int i = 0;; i++) {
		line = get_next_line(fd);
		if (str_iseq(line, "TOP:")) {
			epi_free(line);
			break;
		}
		for (int j = 0; j < str_len(line); i++, j++)
			layers[1][i] = line[j];
		epi_free(line);
		layers[1][i] = '\n';
	}
}

void fill_layer_top(int fd, char **layers, int size)
{
	char *line = NULL;

	layers[2] = epi_malloc(size);
	for (int i = 0;; i++) {
		line = get_next_line(fd);
		if (str_iseq(line, "END")) {
			epi_free(line);
			break;
		}
		for (int j = 0; j < str_len(line); i++, j++)
			layers[2][i] = line[j];
		epi_free(line);
		layers[2][i] = '\n';
	}
}
