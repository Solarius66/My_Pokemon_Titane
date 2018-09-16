/*
** EPITECH PROJECT, 2018
** DESTRUCT_ATTACKS.C
** File description:
** Destrucs attacks of RPokémonG
*/

#include "declaration.h"

void destruct_attacks(game_t *game)
{
	destroy_all_attack(game->attacks);
	game->attacks = NULL;
}

int destroy_all_attack(attack_t *att)
{
	attack_t *tmp = att;

	if (att == NULL)
		return (0);
	if (att->next == NULL) {
		free(att->name);
		free(att);
		att = NULL;
		return (0);
	}
	for (; tmp->next->next != NULL; tmp = tmp->next);
	if (tmp->next->name != NULL)
		free(tmp->next->name);
	free(tmp->next);
	tmp->next = NULL;
	destroy_all_attack(att);
	return (0);
}
