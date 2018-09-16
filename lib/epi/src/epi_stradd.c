/*
** EPITECH PROJECT, 2018
** lib 2.0
** File description:
** adding a char to a char *
*/

#include "../internal.h"

char *epi_stradd(char *str[], char c)
{
	int len = 0;
	char *sol = NULL;
	char *temp = str[0];

	len = epi_strlen(temp);
	if (temp == NULL || len == 0) {
		sol = epi_malloc(1);
		sol[0] = c;
		str[0] = sol;
		return (malloc(sizeof(char) * 1));
	}
	if (c < 1)
		return (malloc(sizeof(char) * 1));
	sol = epi_remalloc(temp, len + 1);
	if (!sol)
		return (NULL);
	sol[len] = c;
	str[0] = sol;
	return (temp);
}
