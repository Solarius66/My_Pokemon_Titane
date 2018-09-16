/*
** EPITECH PROJECT, 2018
** lib 2.0
** File description:
** epi_free
*/

#include "../internal.h"

int epi_free(void *ptr)
{
	if (!ptr)
		return (1);
	free(ptr);
	return (0);
}
