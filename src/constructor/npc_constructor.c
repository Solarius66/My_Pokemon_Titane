/*
** EPITECH PROJECT, 2018
** my_rPOKEMONg
** File description:
** creating npc
*/

#include "declaration.h"

void init_npc(player_t *npc)
{
	npc->name = NULL;
	npc->actual = 0;
	npc->pokemons = NULL;
	npc->id = 0;
	npc->catchphrase = NULL;
	npc->next = NULL;
	npc->texture = NULL;
}

/*
**0: id 1: skin 2: nom 3 catchphrase 4 zone 5 position (x) 6 position (y)
**7 pokemon ID 8 pokemon lvl
*/
void fill_npc(player_t *npc, char **sol, pokemon_t *pkm)
{
	npc->name = epi_remalloc(sol[2], -1);
	npc->id = epi_atoi(sol[0]);
	npc->skin_id = epi_atoi(sol[1]);
	npc->catchphrase = epi_remalloc(sol[3], -1);
	npc->map_name = epi_remalloc(sol[4], -1);
	npc->position.x = epi_atoi(sol[5]);
	npc->position.y = epi_atoi(sol[6]);
	npc->pokemons = malloc(sizeof(pokemon_t) * 7);
	for (int i = 0; i < 6; ++i)
		npc->pokemons[i] = NULL;
	npc->pokemons[0] = pokemon_dup_by_id(epi_atoi(sol[7]), epi_atoi(sol[8]), pkm);
}

int parse_npc_conf(FILE *stream, player_t *actual, pokemon_t *pkm)
{
	char **sol = NULL;
	char *str = NULL;
	size_t len = 0;

	if (getline(&str, &len, stream) <= 1) {
		epi_free(str);
		return (1);
	}
	sol = epi_split(str, ',');
	fill_npc(actual, sol, pkm);
	epi_ddestroy(sol);
	free(str);
	return (0);
}

player_t *create_npc(pokemon_t *pkm)
{
	player_t *npc = malloc(sizeof(player_t));
	player_t *actual = npc;
	FILE *stream = fopen("./config/npc.conf", "r");
	int error_gest = 0;

	init_npc(npc);
	error_gest = parse_npc_conf(stream, actual, pkm);
	while (error_gest == 0) {
		if (error_gest == 0)
			actual->next = malloc(sizeof(player_t));
		init_npc(actual->next);
		error_gest = parse_npc_conf(stream, actual->next, pkm);
		if (error_gest == 0)
			actual = actual->next;
		else {
			epi_free(actual->next);
			actual->next = NULL;
		}
	}
	fclose(stream);
	return (npc);
}
