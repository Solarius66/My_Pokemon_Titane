/*
** EPITECH PROJECT, 2018
** lib 2.0
** File description:
** epi_getnbr
*/

#include "../internal.h"

int epi_atoi(char *str)
{
	int soluce = 0;
	int is_neg = 1;
	int i;

	if (!str)
		return (0);
	for (i = 0; str[i] == '+' || str[i] == '-'; ++i)
		if (str[i] == '-')
			is_neg = is_neg * -1;
	for (; str[i] <= 57 && str[i] >= 48; ++i)
		soluce = (soluce * 10) + (str[i] - 48);
	soluce = soluce * is_neg;
	return (soluce);
}
