/*
** EPITECH PROJECT, 2018
** lib 2.0
** File description:
** clear malloc
*/

#include "../internal.h"

int clear_malloc(char *str, int size)
{
	for (int i = 0; i < size; ++i)
		str[i] = 0;
	return (0);
}
