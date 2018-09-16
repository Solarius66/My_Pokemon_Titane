/*
** EPITECH PROJECT, 2018
** POKEDEX_EXTENDED.C
** File description:
** Extension file for pokedex
*/

#include "declaration.h"

int pokedex_move(int x, sfClock *clock)
{
	if (sfClock_getElapsedTime(clock).microseconds <= 150000)
		return (x);
	if (move_bot() == sfTrue)
		x++;
	if (move_top() == sfTrue)
		x--;
	if (x == 0)
		x = 151;
	if (x == 152)
		x = 1;
	sfClock_restart(clock);
	return (x);
}
