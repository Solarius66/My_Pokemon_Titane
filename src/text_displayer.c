/*
** EPITECH PROJECT, 2018
** text_displayer
** File description:
** text display, with scrolling and fading
*/

#include "declaration.h"

void display_rect_text(game_t *game, bool bool)
{
	sfRectangleShape *rect = sfRectangleShape_create();

	if (bool == false) {
		sfRectangleShape_setPosition(rect, create_vector2f(10, 450));
		sfRectangleShape_setSize(rect, create_vector2f(940, 180));
	} else {
		sfRectangleShape_setPosition(rect, create_vector2f(10, 450));
		sfRectangleShape_setSize(rect, create_vector2f(790, 180));
	}
	sfRectangleShape_setFillColor(rect, sfWhite);
	sfRectangleShape_setOutlineColor(rect, game->outline);
	sfRectangleShape_setOutlineThickness(rect, 10);
	sfRenderWindow_drawRectangleShape(game->win, rect, NULL);
	sfRectangleShape_destroy(rect);
}

void display_text_tchat(game_t *game, char *str, int x)
{
	sfText *text = sfText_create();

	sfText_setString(text, str);
	sfText_setPosition(text, create_vector2f(30, 470 + x * 50));
	sfText_setCharacterSize(text, 40);
	sfText_setFont(text, game->texture->font);
	sfText_setColor(text, sfBlack);
	sfRenderWindow_drawText(game->win, text, NULL);
	sfText_destroy(text);
}

void text_displayer(game_t *game, char *str, bool bool)
{
	char **tab;

	if (bool == false)
		tab = epi_split_nb(str, 22, " ");
	else
		tab = epi_split_nb(str, 19, " ");
	display_rect_text(game, bool);
	for (int x = 0; tab[x] != NULL; x++)
		display_text_tchat(game, tab[x], x);
	epi_ddestroy(tab);
}
