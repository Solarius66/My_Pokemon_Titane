/*
** EPITECH PROJECT, 2018
** my_rPokemong
** File description:
** pkm find by id & name
*/

#include "declaration.h"

pokemon_t *find_pokemon_by_name(pokemon_t *pkm, char *name)
{
	if (pkm == NULL || name == NULL)
		return (NULL);
	for (; pkm != NULL; pkm = pkm->next)
		if (epi_compare_str(pkm->name, name))
			break;
	return (pkm);
}

pokemon_t *find_pokemon_by_id(pokemon_t *pkm, int id)
{
	if (pkm == NULL)
		return (NULL);
	for (; pkm != NULL; pkm = pkm->next)
		if (pkm->id == id)
			break;
	return (pkm);
}
