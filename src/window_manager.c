/*
** EPITECH PROJECT, 2018
** WINDOW_MANAGER.C
** File description:
** Manages SFML windows
*/

#include "declaration.h"

sfRenderWindow *win_create(sfVideoMode mode, char *name)
{
	sfRenderWindow *win = NULL;

	if (name == NULL)
		return (NULL);
	win = sfRenderWindow_create(mode, name, sfClose | sfResize, NULL);
	if (win == NULL)
		return (NULL);
	sfRenderWindow_setFramerateLimit(win, 60);
	return (win);
}

int win_close(sfRenderWindow *win)
{
	if (win == NULL)
		return (84);
	sfRenderWindow_close(win);
	return (0);
}

int win_destroy(sfRenderWindow *win)
{
	if (win == NULL)
		return (84);
	sfRenderWindow_destroy(win);
	return (0);
}
