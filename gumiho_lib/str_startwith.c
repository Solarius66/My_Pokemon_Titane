/*
** EPITECH PROJECT, 2018
** STR_STARTWITH.C
** File description:
** Checks if given string starts with given expression
*/

#include "gumiho_lib.h"

int str_startwith(char *str, char *expr)
{
	if (!str || !expr)
		return (-1);
	if (str_len(str) < str_len(expr))
		return (0);
	for (int i = 0; i < str_len(expr); i++) {
		if (str[i] != expr[i])
			return (0);
	}
	return (1);
}
