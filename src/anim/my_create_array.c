/*
** EPITECH PROJECT, 2018
** lib 2.0
** File description:
** creating arrow
*/

#include "declaration.h"

sfTexture **my_create_array(int length)
{
	sfTexture **tab = malloc(sizeof(sfTexture *) * (length + 1));

	if (tab == NULL)
		return (NULL);
	tab[length] = NULL;
	return (tab);
}
