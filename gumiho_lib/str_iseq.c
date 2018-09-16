/*
** EPITECH PROJECT, 2018
** STR_ISEQ.C
** File description:
** Checks if given string is equals to given expression
*/

#include "gumiho_lib.h"

int str_iseq(char *str, char *expr)
{
	if (!str || !expr)
		return (0);
	if (str_len(str) != str_len(expr))
		return (0);
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] != expr[i])
			return (0);
	}
	return (1);
}
