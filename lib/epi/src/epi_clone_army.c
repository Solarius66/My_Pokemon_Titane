/*
** EPITECH PROJECT, 2018
** lib 2.0
** File description:
** copying double array
*/

#include "../internal.h"

int epi_dstrlen(char *str[])
{
	int i = 0;

	if (!str)
		return (0);
	for (i = 0; str[i] != NULL; ++i);
	return (i);
}

int epi_ddestroy(char *str[])
{
	if (str == NULL)
		return (84);
	for (int i = 0; str[i] != NULL; ++i) {
		epi_free(str[i]);
		str[i] = NULL;
	}
	epi_free(str);
	return (0);
}

int epi_printd(char **str)
{
	if (str == NULL)
		return (-1);
	for (int i = 0; str[i] != NULL; ++i) {
		epi_putstr(str[i]);
	}
	return (0);
}

char **epi_dre_malloc(char *str[])
{
	int len = epi_dstrlen(str);
	char **sol = malloc(sizeof(char *) * (len + 1));

	sol[len] = NULL;
	for (int i = 0; str[i]; ++i) {
		sol[i] = epi_remalloc(str[i], -1);
	}
	return (sol);
}
