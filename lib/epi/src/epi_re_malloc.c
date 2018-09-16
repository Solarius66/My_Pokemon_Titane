/*
** EPITECH PROJECT, 2018
** lib 2.0
** File description:
** re_malloc
*/

#include "../internal.h"

char *epi_remalloc(char *str, int nb)
{
	char *sol;
	int nbis = epi_strlen(str);

	if (nb < 0)
		nb = nbis;
	sol = epi_malloc(nb);
	for (int i = 0; i < nb; ++i)
		sol[i] = str[i];
	return (sol);
}
