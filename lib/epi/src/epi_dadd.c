/*
** EPITECH PROJECT, 2018
** lib 2.0
** File description:
** adding some case to a double array
*/

#include "../internal.h"

char **epi_remove_line_nb(char **tab[], int line_nb)
{
	int total = epi_dstrlen(tab[0]);
	char **new = NULL;
	char **old = tab[0];

	if (line_nb > total - 1 || line_nb < 0)
		return (epi_dre_malloc(old));
	new = malloc(sizeof(char *) * (total + 1));
	for (int i = 0; i <= total; ++i)
		new[i] = NULL;
	total = 0;
	for (int i = 0; old[i]; ++i) {
		if (i == line_nb)
			continue;
		new[total] = epi_remalloc(tab[0][i], -1);
		++total;
	}
	new[total] = NULL;
	tab[0] = new;
	return (old);
}

char **epi_remove_line(char **tab[], char *str)
{
	int total = epi_dstrlen(tab[0]);
	char **new = NULL;
	char **old = tab[0];

	if (str == NULL)
		return (NULL);
	for (int i = 0; tab[0][i]; ++i)
		if (epi_start_with(tab[0][i], str) != -1)
			--total;
	new = malloc(sizeof(char *) * (total + 1));
	new[total] = NULL;
	total = 0;
	for (int i = 0; tab[0][i]; ++i) {
		if (epi_start_with(tab[0][i], str) == -1) {
			new[total] = epi_remalloc(tab[0][i], -1);
			++total;
		}
	}
	tab[0] = new;
	return (old);
}

char **epi_dadd_start(char *tab[], char *str)
{
	int len = epi_dstrlen(tab) + 1;
	char **sol = malloc(sizeof(char *) * (len + 1));
	int j = 0;

	sol[len] = NULL;
	for (int i = 1; tab && tab[j]; ++i, ++j)
		sol[i] = epi_remalloc(tab[j], -1);
	sol[0] = epi_remalloc(str, -1);
	if (tab)
		epi_ddestroy(tab);
	return (sol);
}

char **epi_dadd(char *tab[], char *str)
{
	int len = epi_dstrlen(tab) + 1;
	char **sol = malloc(sizeof(char *) * (len + 1));

	sol[len] = NULL;
	for (int i = 0; tab && tab[i]; ++i)
		sol[i] = epi_remalloc(tab[i], -1);
	if (len == 0)
		len = 1;
	sol[len - 1] = epi_remalloc(str, -1);
	if (tab)
		epi_ddestroy(tab);
	return (sol);
}
