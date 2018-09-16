/*
** EPITECH PROJECT, 2018
** INTA_MALLOC.C
** File description:
** Mallocs int array with given size
*/

#include "gumiho_lib.h"

int *inta_malloc(int size)
{
	int *inta = NULL;

	inta = malloc(sizeof(int) * (size + 1));
	for (int i = 0; i < size; i++)
		inta[i] = 0;
	inta[size] = -1;
	return (inta);
}
