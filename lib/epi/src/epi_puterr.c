/*
** EPITECH PROJECT, 2018
** lib 2.0
** File description:
** epi_puterr
*/

#include "../internal.h"

int epi_puterr(char *str)
{
	write(2, str, epi_strlen(str));
	return (0);
}
