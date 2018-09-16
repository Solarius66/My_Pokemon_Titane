/*
** EPITECH PROJECT, 2018
** lib 2.0
** File description:
** all printf mains
*/

#include "../internal.h"

char *epi_putf(char *str, ...)
{
	va_list list;
	char *sol = NULL;

	if (str == NULL)
		return (NULL);
	va_start(list, str);
	sol = epi_vprintf(str, list);
	va_end(list);
	return (sol);
}

int epi_dprintf(int fd, char *str, ...)
{
	va_list list;
	char *sol = NULL;

	va_start(list, str);
	if (fd < 0 || str == NULL)
		return (84);
	sol = epi_vprintf(str, list);
	write(fd, sol, epi_strlen(sol));
	free(sol);
	va_end(list);
	return (0);
}
