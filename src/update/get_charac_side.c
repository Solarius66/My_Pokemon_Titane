/*
** EPITECH PROJECT, 2018
** my_rPokemong
** File description:
** getting the character side things
*/

#include "declaration.h"

side_t *get_tiles_around(char *map, sfVector2f *pos, int map_size)
{
	int pos_x = pos.x / 32;
	int pos_y = pos.y / 32;
	side_t *s_char = malloc(sizeof(struct side_t));
	int pos_char = pos_y * map_size + pos_x;

	s_char->top = map_string[pos_char - map_size] - 48;
	if (s_char->top < 0 || s_char->top > 14)
		s_char->top = 1;
	s_char->bot = map_string[pos_char + map_size] - 48;
	if (s_char->bot < 0 || s_char->bot > 14)
		s_char->bot = 1;
	s_char->right = map_string[pos_char + 1] - 48;
	if (s_char->right < 0 || s_char->right > 14)
		s_char->right = 1;
	s_char->left = map_string[pos_char - 1] - 48;
	if (s_char->left < 0 || s_char->left > 14)
		s_char->left = 1;
	return (s_char);
}
