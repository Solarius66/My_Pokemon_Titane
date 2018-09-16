/*
** EPITECH PROJECT, 2018
** STR_LEN.C
** File description:
** Returns lenght of given string
*/

#include "gumiho_lib.h"

int str_len(char *str)
{
	int len = 0;

	if (!str)
		return (-1);
	for (len = 0; str[len] != '\0'; len++);
	return (len);
}
