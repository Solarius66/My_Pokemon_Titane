/*
** EPITECH PROJECT, 2018
** lib 2.0
** File description:
** does the string start withe the other one
*/

#include "../internal.h"

int epi_end_with(char *str, char *end, int i)
{
	int j = 0;

	if (str == NULL || end == NULL)
		return (0);
	if (epi_strlen(end) > epi_strlen(str))
		return (0);
	for (; str[i] != end[0]; ++i)
		if (str[i] == 0)
			return (0);
	if (epi_strlen(end) > epi_strlen(end))
		return (-1);
	++i;
	for (int k = i; str[k]; ++k, ++j)
		if (str[k] != end[k])
			return (epi_end_with(str, end, i));
	return (1);
}

int epi_start_with(char *str, char *start)
{
	int i = 0;

	if (str == NULL || start == NULL)
		return (-1);
	if (epi_strlen(start) > epi_strlen(str))
		return (-1);
	for (; start[i]; ++i)
		if (start[i] != str[i])
			return (-1);
	return (i);
}
