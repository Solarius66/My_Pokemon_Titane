/*
** EPITECH PROJECT, 2018
** my graphical lib
** File description:
** creating texture
*/

#include "declaration.h"

void destruct_npc(player_t *npc)
{
	player_t *tempo = npc->next;

	for (; npc != NULL; tempo = tempo->next) {
		epi_free(npc->name);
		epi_free(npc->catchphrase);
		epi_free(npc->map_name);
		destruct_pokemon(npc->pokemons[0]);
		epi_free(npc->pokemons);
		npc->next = NULL;
		epi_free(npc);
		npc = NULL;
		npc = tempo;
		if (npc == NULL)
			return;
	}
}
