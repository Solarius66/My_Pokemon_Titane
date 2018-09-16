/*
** EPITECH PROJECT, 2018
** my graphical lib
** File description:
** destroying texture
*/

#include "declaration.h"

int destroy_textures(sfTexture **tab)
{
	for (int i = 0; tab[i] != NULL; ++i)
		sfTexture_destroy(tab[i]);
	free(tab);
	return (0);
}
