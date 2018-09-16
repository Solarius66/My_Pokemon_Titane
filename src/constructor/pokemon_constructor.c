/*
** EPITECH PROJECT, 2018
** my_rPokemong
** File description:
** creating pokemons from file
*/

#include "declaration.h"

int fill_pokemon(pokemon_t *new, char **str, attack_t *attack)
{
	new->type2 = epi_atoi(str[2]);
	new->max_health = epi_atoi(str[3]);
	new->damage = epi_atoi(str[4]);
	new->defense = epi_atoi(str[5]);
	new->special_damage = epi_atoi(str[6]);
	new->special_defense = epi_atoi(str[7]);
	new->attack_speed = epi_atoi(str[8]);
	new->name = epi_remalloc(str[9], -1);
	new->id_evolve = epi_atoi(str[10]);
	new->lvl_evolve = epi_atoi(str[11]);
	new->attack[0] = find_attack_by_id(attack, epi_atoi(str[12]));
	new->attack[1] = find_attack_by_id(attack, epi_atoi(str[13]));
	new->attack[2] = find_attack_by_id(attack, epi_atoi(str[14]));
	new->attack[3] = find_attack_by_id(attack, epi_atoi(str[15]));
	new->is_discovered = false;
	return (0);
}

int parse_pokemon_conf(FILE *stream, pokemon_t *new, attack_t *attack)
{
	char **sol = NULL;
	char *str = NULL;
	size_t len = 0;

	if (getline(&str, &len, stream) <= 1) {
		epi_free(str);
		return (1);
	}
	sol = epi_split(str, ',');
	new->id = epi_atoi(sol[0]);
	new->type1 = epi_atoi(sol[1]);
	fill_pokemon(new, sol, attack);
	epi_ddestroy(sol);
	free(str);
	return (0);
}

pokemon_t *create_all_pokemon(attack_t *attack)
{
	FILE *stream = fopen("./config/pokemon.conf", "r");
	pokemon_t *new = malloc(sizeof(pokemon_t));
	pokemon_t *next = new;
	int error_gest = 0;

	error_gest = parse_pokemon_conf(stream, next, attack);
	while (error_gest == 0) {
		if (error_gest == 0) {
			next->next = malloc(sizeof(pokemon_t));
			next = next->next;
			next->name = NULL;
			next->next = NULL;
		}
		error_gest = parse_pokemon_conf(stream, next, attack);
		if (error_gest == -1)
			return (NULL);
	}
	fclose(stream);
	return (new);
}
