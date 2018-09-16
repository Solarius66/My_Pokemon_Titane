/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Rpg based on Pokemon
*/

#include "declaration.h"

void save_npc(int fd, npc_t *npcs)
{
	do {
		if (npcs->has_been_defeated) {
			write(fd, "1", 1);
		} else {
			write(fd, "0", 1);
		}
		write(fd, "\n", 1);
	} while ((npcs = npcs->next));
}
