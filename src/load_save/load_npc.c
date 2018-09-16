/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Rpg based on Pokemon
*/

#include "declaration.h"

void load_npc(int fd, npc_t *npcs)
{
	char *line = get_next_line(fd);
	char *temp = line;

	do {
		if (*temp++ == '1')
			npcs->has_been_defeated = 1;
	} while ((npcs = npcs->next));
	free(line);
}
