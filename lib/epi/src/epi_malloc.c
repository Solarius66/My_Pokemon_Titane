/*
** EPITECH PROJECT, 2018
** lib 2.0
** File description:
** malloc into clean into cool.
*/

#include "../internal.h"

char *epi_malloc_spe(int size, char c)
{
	char *str = malloc(sizeof(char) * (size + 1));

	if (size <= 0 || !str)
		return (NULL);
	for (int i = 0; i < size; ++i)
		str[i] = c;
	str[size] = 0;
	return (str);
}

char *epi_malloc(int size)
{
	char *str = malloc(sizeof(char) * (size + 1));

	if (size <= 0 || !str)
		return (NULL);
	clear_malloc(str, size);
	str[size] = 0;
	return (str);
}
