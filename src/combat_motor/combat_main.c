/*
** EPITECH PROJECT, 2018
** my_rPOKEMONg
** File description:
** combat_main
*/

#include "declaration.h"

void attack_ai(pokemon_t *ai)
{
	int poney = rand() % 4;

	ai->attack_chosen = ai->attack[poney];
}

float get_stab(pokemon_t *P1)
{
	float STAB = 1;

	if (P1->type1 == P1->attack_chosen.type ||
		P1->type2 == P1->attack_chosen.type)
		STAB = 1.5;
	return (STAB);
}

int get_critical_hit(pokemon_t *P1)
{
	int augmentation = (2 * P1->lvl + 5) / (P1->lvl + 5);
	int speed = P1->attack_speed;
	int random = rand() % 256;

	if (speed % 2 != 0)
		--speed;
	if (speed / 2 > random && augmentation >= 1)
		return ((int)augmentation);
	return (1);
}

int attack_dps(pokemon_t *P1, pokemon_t *P2)
{
	float STAB = get_stab(P1);
	float effectiveness = is_effective(&P1->attack_chosen, P2->type1) *
	is_effective(&P1->attack_chosen, P2->type2);
	float pv_loose = (P1->lvl * 0.4 + 2) * P1->damage;
	float the_random_part = 1;
	int critical_hit = 1;
	int lvl_diff = P1->lvl - P2->lvl;

	pv_loose = pv_loose / (P2->defense * 50);
	pv_loose += 2;
	pv_loose = pv_loose * (float)STAB * (float)effectiveness *
	(float)critical_hit * (float)the_random_part;
	lvl_diff *= rand() % 7 + 1;
	if ((int)pv_loose + lvl_diff < 10)
		return (10);
	return ((int)pv_loose + lvl_diff);
}

int speed_calculator(pokemon_t *P1, pokemon_t *P2)
{
	if (P1->attack_chosen.priority > P2->attack_chosen.priority)
		return (2);
	if (P1->attack_chosen.priority < P2->attack_chosen.priority)
		return (1);
	if (P1->status == PARALYSED && P2->status != PARALYSED)
		return (2);
	if (P1->attack_speed < P2->attack_speed && P2->status != PARALYSED)
		return (2);
	return (1);
}
