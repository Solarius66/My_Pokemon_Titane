/*
** EPITECH PROJECT, 2018
** STR_DISP.C
** File description:
** Displays given string into given output
*/

#include "gumiho_lib.h"

int str_disp(char *str, int output)
{
	int out = 0;
	int ret = 0;
	int len = 0;

	if (!str)
		return (84);
	out = (output == 1) ? 1 : 2;
	ret = (output == 1) ? 0 : 84;
	for (len = 0; str[len] != '\0'; len++);
	write(out, str, len);
	return (ret);
}
