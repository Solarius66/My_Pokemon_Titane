/*
** EPITECH PROJECT, 2018
** controllerinterract.c
** File description:
** controller buttons & interactions
*/

#include "declaration.h"

sfBool press_start(void)
{
	if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue)
		return (sfTrue);
	if (sfJoystick_isConnected(0) == sfTrue &&
		sfJoystick_isButtonPressed(0, 7) == sfTrue)
		return (sfTrue);
	return (sfFalse);
}

sfBool press_a(void)
{
	if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue)
		return (sfTrue);
	if (sfJoystick_isConnected(0) == sfTrue &&
		sfJoystick_isButtonPressed(0, 0) == sfTrue)
		return (sfTrue);
	return (sfFalse);
}

sfBool press_y(void)
{
	if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue)
		return (sfTrue);
	if (sfJoystick_isConnected(0) == sfTrue &&
		sfJoystick_isButtonPressed(0, 3) == sfTrue)
		return (sfTrue);
	return (sfFalse);
}

sfBool press_b(game_t *game)
{
	static bool poney = true;

	if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue)
		return (sfTrue);
	if (sfJoystick_isConnected(0) == sfTrue &&
		sfJoystick_isButtonPressed(0, 1) == sfTrue)
		return (sfTrue);
	event_close(game->win);
	if (!sfRenderWindow_isOpen(game->win) && poney == true) {
		poney = false;
		return (sfTrue);
	} else
		poney = true;
	return (sfFalse);
}

sfBool press_x(void)
{
	if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue)
		return (sfTrue);
	if (sfJoystick_isConnected(0) == sfTrue &&
		sfJoystick_isButtonPressed(0, 2) == sfTrue)
		return (sfTrue);
	return (sfFalse);
}
