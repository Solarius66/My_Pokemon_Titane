/*
** EPITECH PROJECT, 2018
** controllermove.c
** File description:
** controller for joystick management
*/

#include "declaration.h"

sfBool move_top(void)
{
	if (sfKeyboard_isKeyPressed(sfKeyZ))
		return (sfTrue);
	if (sfJoystick_isConnected(0) && sfJoystick_getAxisPosition(0,
		sfJoystickY) <= -50)
		return (sfTrue);
	return (sfFalse);
}

sfBool move_bot(void)
{
	if (sfKeyboard_isKeyPressed(sfKeyS))
		return (sfTrue);
	if (sfJoystick_isConnected(0) && sfJoystick_getAxisPosition(0,
		sfJoystickY) >= 50)
		return (sfTrue);
	return (sfFalse);
}

sfBool move_right(void)
{
	if (sfKeyboard_isKeyPressed(sfKeyD))
		return (sfTrue);
	if (sfJoystick_isConnected(0) && sfJoystick_getAxisPosition(0,
		sfJoystickX) >= 50)
		return (sfTrue);
	return (sfFalse);
}

sfBool move_left(void)
{
	if (sfKeyboard_isKeyPressed(sfKeyQ))
		return (sfTrue);
	if (sfJoystick_isConnected(0) && sfJoystick_getAxisPosition(0,
		sfJoystickX) <= -50)
		return (sfTrue);
	return (sfFalse);
}

sfBool move_select(void)
{
	if (sfKeyboard_isKeyPressed(sfKeyTab))
		return (sfTrue);
	if (sfJoystick_isConnected(0) && sfJoystick_isButtonPressed(0, 6))
		return (sfTrue);
	return (sfFalse);
}
