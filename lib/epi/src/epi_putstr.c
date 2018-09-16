/*
** EPITECH PROJECT, 2018
** lib 2.0
** File description:
** epi_putstr
*/

#include "../internal.h"

int epi_putchar(unsigned char c)
{
	write(1, &c, 1);
	return (0);
}

int epi_putstr(char *str)
{
	if (str == NULL) {
		write(1, "(NULL)\n", 7);
		return (84);
	}
	write(1, str, epi_strlen(str));
	return (0);
}
