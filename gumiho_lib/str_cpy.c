/*
** EPITECH PROJECT, 2018
** STR_CPY.C
** File description:
** Copies a string into another.
*/

#include "gumiho_lib.h"

char *str_cpy(char const *str)
{
	int len = 0;
	char *copy = NULL;

	if (!str)
		return (NULL);
	for (len = 0; str[len] != '\0'; len++);
	if (len == 0)
		return (NULL);
	copy = malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	for (int i = 0; i < len; i++)
		copy[i] = str[i];
	copy[len] = '\0';
	return (copy);
}
