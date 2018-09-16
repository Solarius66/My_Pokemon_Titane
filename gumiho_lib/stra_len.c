/*
** EPITECH PROJECT, 2018
** STRA_LEN.C
** File description:
** Returns lenght of given str array
*/

#include "gumiho_lib.h"

int stra_len(char **stra)
{
	int len = 0;

	if (!stra)
		return (0);
	for (len = 0; stra[len] != NULL; len++);
	return (len);
}
