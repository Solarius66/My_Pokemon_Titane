/*
** EPITECH PROJECT, 2018
** lib 2.0
** File description:
** multiple split
*/

#include "../internal.h"

char **epi_split_many_arg(char *str, char *splitters)
{
	char **sol = NULL;
	char *temp = epi_remalloc(str, -1);

	if (str == NULL || splitters == NULL || temp == NULL)
		return (NULL);
	for (int i = 1; splitters[i] != 0; ++i) {
		sol = epi_split_arg(temp, splitters[i]);
		free(temp);
		temp = epi_join(sol, splitters[0]);
		if (temp == NULL || sol == NULL)
			return (NULL);
		epi_ddestroy(sol);
	}
	sol = epi_split_arg(temp, splitters[0]);
	free(temp);
	return (sol);
}

char **epi_split_many(char *str, char *splitters)
{
	char **sol = NULL;
	char *hey = epi_remalloc(str, -1);

	if (hey == NULL || splitters == NULL || str == NULL)
		return (NULL);
	for (int i = 1; splitters[i] != 0; ++i) {
		epi_replace_charac(hey, splitters[i], splitters[0]);
	}
	sol = epi_split(hey, splitters[0]);
	epi_free(hey);
	return (sol);
}
