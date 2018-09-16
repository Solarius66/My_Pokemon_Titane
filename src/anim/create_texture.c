/*
** EPITECH PROJECT, 2018
** my graphical lib
** File description:
** creating texture
*/

#include "declaration.h"

sfTexture **create_texture(char *path, int text_nb, sfIntRect *area)
{
	sfTexture **tab = my_create_array(text_nb);

	if (tab == NULL)
		return (NULL);
	for (int i = 0; i < text_nb; ++i) {
		tab[i] = sfTexture_createFromFile(path, area);
		if (area != NULL)
			area->left = area->width + area->left;
	}
	if (area != NULL)
		area->left = 0;
	return (tab);
}
