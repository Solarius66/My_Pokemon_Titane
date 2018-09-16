/*
** EPITECH PROJECT, 2018
** usefull_fct.c
** File description:
** open window, set framerate, event close
*/

#include "declaration.h"

sfVector2f create_vector2f(int x, int y)
{
	sfVector2f pos = {x, y};

	return (pos);
}

void create_rect(sfTexture *texture, sfVector2f pos, sfVector2f size,
sfRenderWindow *window)
{
	sfRectangleShape *rect = sfRectangleShape_create();

	sfRectangleShape_setPosition(rect, pos);
	sfRectangleShape_setSize(rect, size);
	sfRectangleShape_setTexture(rect, texture, sfTrue);
	sfRenderWindow_drawRectangleShape(window, rect, NULL);
	sfRectangleShape_destroy(rect);
}

void create_text(sfFont *font, sfVector2f pos, char *sentence,
sfRenderWindow *window)
{
	int size = 30;
	sfText *text = sfText_create();

	sfText_setString(text, sentence);
	sfText_setPosition(text, pos);
	sfText_setCharacterSize(text, size);
	sfText_setFont(text, font);
	sfText_setColor(text, sfWhite);
	sfRenderWindow_drawText(window, text, NULL);
	sfText_destroy(text);
}

void event_close(sfRenderWindow *window)
{
	sfEvent event;

	if (sfJoystick_isConnected(0) && sfJoystick_isButtonPressed(0, 8))
		sfRenderWindow_close(window);
	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(window);
	}
}
