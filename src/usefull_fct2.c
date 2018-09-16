/*
** EPITECH PROJECT, 2018
** 2
** File description:
** 2
*/

#include "declaration.h"

sfIntRect *create_int_rect_star(int top, int left, int width, int height)
{
	sfIntRect *rect = malloc(sizeof(sfIntRect));

	rect->top = top;
	rect->left = left;
	rect->width = width;
	rect->height = height;
	return (rect);
}

sfIntRect create_int_rect(int top, int left, int width, int height)
{
	sfIntRect rect;

	rect.top = top;
	rect.left = left;
	rect.width = width;
	rect.height = height;
	return (rect);
}

sfSprite *create_sprite(sfTexture *texture, sfVector2f pos, sfIntRect rect)
{
	sfSprite *sprite = sfSprite_create();

	sfSprite_setTexture(sprite, texture, sfTrue);
	sfSprite_setTextureRect(sprite, rect);
	sfSprite_setPosition(sprite, pos);
	return (sprite);
}

void create_color_rect(sfColor color, sfVector2f size, sfVector2f pos,
sfRenderWindow *window)
{
	sfRectangleShape *rect = sfRectangleShape_create();

	sfRectangleShape_setPosition(rect, pos);
	sfRectangleShape_setSize(rect, size);
	sfRectangleShape_setOutlineColor(rect, color);
	sfRectangleShape_setOutlineThickness(rect, 5);
	sfRectangleShape_setFillColor(rect, sfTransparent);
	sfRenderWindow_drawRectangleShape(window, rect, NULL);
	sfRectangleShape_destroy(rect);
}

void create_color_rect_in(sfColor color, sfVector2f size, sfVector2f pos,
sfRenderWindow *window)
{
	sfRectangleShape *rect = sfRectangleShape_create();

	sfRectangleShape_setPosition(rect, pos);
	sfRectangleShape_setSize(rect, size);
	sfRectangleShape_setFillColor(rect, color);
	sfRenderWindow_drawRectangleShape(window, rect, NULL);
	sfRectangleShape_destroy(rect);
}
