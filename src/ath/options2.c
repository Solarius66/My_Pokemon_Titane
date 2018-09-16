/*
** EPITECH PROJECT, 2018
** options2
** File description:
** options2
*/

#include "declaration.h"

void define_outline_color(game_t *game, sfClock *clock)
{
	sfColor color[7] = {sfRed, sfGreen, sfBlue,
		sfYellow, sfMagenta, sfCyan, sfBlack};
	static int x = 0;

	if (sfClock_getElapsedTime(clock).microseconds < 150000)
		return;
	if (x == 7)
		x = 0;
	if (x == -1)
		x = 6;
	if (move_right())
		x++;
	if (move_left())
		x--;
	game->outline = color[x];
	sfClock_restart(clock);
}
