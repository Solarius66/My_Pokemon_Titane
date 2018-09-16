/*
** EPITECH PROJECT, 2018
** STRA_FREE.C
** File description:
** Free given string array (stra)
*/

#include "gumiho_lib.h"

int stra_free(char **stra)
{
	if (!stra)
		return (84);
	for (int i = 0; stra[i] != NULL; i++) {
		if (stra[i] != NULL)
			free(stra[i]);
	}
	free(stra);
	return (0);
}
