/*
** EPITECH PROJECT, 2018
** lib 2.0
** File description:
** strlen
*/

#include "../internal.h"

int epi_strlen(char *str)
{
	int length = 0;

	if (str == NULL)
		return (0);
	for (length = 0; str[length]; ++length);
	return (length);
}
