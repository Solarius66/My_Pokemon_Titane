/*
** EPITECH PROJECT, 2018
** my_rPOKEMONg
** File description:
** duplicate pokemon by id
*/

#include "declaration.h"

pokemon_t *create_missing_no(void)
{
	pokemon_t *sol = malloc(sizeof(pokemon_t));

	if (!sol)
		return (NULL);
	sol->name = epi_remalloc("Missing n°", -1);
	sol->lvl = -422;
	sol->max_health = 1;
	sol->type1 = NO_TYPE;
	sol->type2 = NO_TYPE;
	sol->cur_health = 1;
	sol->damage = 1;
	sol->defense = 1;
	sol->special_damage = 1;
	sol->special_defense = 1;
	sol->attack_speed = 1;
	sol->status = OKAY;
	sol->xp = -666;
	sol->id = 0;
	sol->is_discovered = false;
	return (sol);
}

void create_stats_from_lvl(pokemon_t *sol, pokemon_t *new, int lvl)
{
	if (lvl <= 0)
		lvl = 1;
	sol->lvl = lvl;
	sol->damage = new->damage + (3 * lvl);
	sol->max_health = new->max_health + (3 * lvl);
	sol->defense = new->defense + (3 * lvl);
	sol->special_damage = new->special_damage + (3 * lvl);
	sol->special_defense = new->special_defense + (3 * lvl);
	sol->attack_speed = new->attack_speed + (3 * lvl);
	sol->xp = lvl * lvl * lvl;
	sol->status = OKAY;
	sol->lvl_evolve = new->lvl_evolve;
	sol->id_evolve = new->id_evolve;
	sol->attack[0] = new->attack[0];
	sol->attack[1] = new->attack[1];
	sol->attack[2] = new->attack[2];
	sol->attack[3] = new->attack[3];
}

pokemon_t *pokemon_dup_by_id(int id, int lvl, pokemon_t *start)
{
	pokemon_t *new = find_pokemon_by_id(start, id);
	pokemon_t *sol = NULL;

	if (new == NULL)
		return (create_missing_no());
	sol = malloc(sizeof(pokemon_t));
	if (sol == NULL)
		return (create_missing_no());
	sol->id = id;
	sol->name = epi_remalloc(new->name, -1);
	sol->texture = new->texture;
	sol->is_discovered = new->is_discovered;
	sol->lvl = lvl;
	sol->type1 = new->type1;
	sol->type2 = new->type2;
	sol->next = NULL;
	create_stats_from_lvl(sol, new, lvl);
	sol->cur_health = sol->max_health;
	new->is_discovered = true;
	return (sol);
}
