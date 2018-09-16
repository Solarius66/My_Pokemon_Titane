/*
** EPITECH PROJECT, 2018
** mysh
** File description:
** compare str
*/

#include "../internal.h"

int epi_compare_str(char *str, char *str2)
{
	int i = 0;

	while (1) {
		if (str[i] != str2[i])
			return (___false___);
		if (str2[i] == 0 && str[i] == 0)
			return (___true___);
		if (str2[i] == 0 || str[i] == 0)
			return (___false___);
		++i;
	}
	return (___true___);
}
