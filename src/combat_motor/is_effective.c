/*
** EPITECH PROJECT, 2018
** my_rPOKEMONg
** File description:
** is effective, super effective / don't affect
*/

#include "declaration.h"

float is_effective5(attack_t *a, pokemon_type P)
{
	float effectiveness = 1;

	if (a->type == PSY && P == PSY)
		effectiveness *= 0.5;
	if (a->type == ROCK && P == PLANT)
		effectiveness *= 0.5;
	if (a->type == FLY && (P == ELEC || P == ROCK))
		effectiveness *= 0.5;
	return (effectiveness);
}

float is_effective4(attack_t *a, pokemon_type P)
{
	float effectiveness = 1;

	if (a->type == FIRE && (P == DRAGON || P == WATER || P == FIRE ||
		P == ROCK))
		effectiveness *= 0.5;
	if (a->type == ICE && (P == WATER || P == ICE))
		effectiveness *= 0.5;
	if (a->type == INSECT && (P == FIGHT || P == FIRE || P == PHANTOM ||
		P == FLY))
		effectiveness *= 0.5;
	if (a->type == NORMAL && (P == ROCK))
		effectiveness *= 0.5;
	if (a->type == PLANT && (P == DRAGON || P == FIRE || P == INSECT ||
		P == PLANT || P == POISON || P == FLY))
		effectiveness *= 0.5;
	if (a->type == POISON && (P == POISON || P == ROCK || P == GROUND ||
		P == PHANTOM))
		effectiveness *= 0.5;
	return (effectiveness * is_effective5(a, P));
}

float is_effective3(attack_t *a, pokemon_type P)
{
	float effectiveness = 1;

	if (a->type == GROUND && P == FLY)
		effectiveness *= 0;
	if (a->type == NORMAL && P == PHANTOM)
		effectiveness *= 0;
	if (a->type == ELEC && P == GROUND)
		effectiveness *= 0;
	if (a->type == FIGHT && P == PHANTOM)
		effectiveness *= 0;
	if (a->type == FIGHT && (P == INSECT || P == POISON || P == PSY ||
		P == FLY))
		effectiveness *= 0.5;
	if (a->type == WATER && (P == DRAGON || P == WATER || P == PLANT))
		effectiveness *= 0.5;
	if (a->type == ELEC && (P == DRAGON || P == ELEC || P == PLANT))
		effectiveness *= 0.5;
	return (effectiveness * is_effective4(a, P));
}

float is_effective2(attack_t *a, pokemon_type P)
{
	float effectiveness = 1;

	if (a->type == POISON && (P == INSECT || P == PLANT))
		effectiveness *= 2;
	if (a->type == PSY && (P == FIGHT || P == POISON))
		effectiveness *= 2;
	if (a->type == ROCK && (P == FIRE || P == ICE || P == INSECT ||
		P == FLY))
		effectiveness *= 2;
	if (a->type == GROUND && (P == ELEC || P == FIRE || P == POISON ||
		P == ROCK))
		effectiveness *= 2;
	if (a->type == PHANTOM && P == PHANTOM)
		effectiveness *= 2;
	if (a->type == FLY && (P == FIGHT || P == INSECT || P == PLANT))
		effectiveness *= 2;
	if (a->type == PHANTOM && (P == NORMAL || P == PSY))
		effectiveness *= 0;
	return (effectiveness * is_effective3(a, P));
}

float is_effective(attack_t *a, pokemon_type P)
{
	float effectiveness = 1;

	if (a->type == FIGHT && (P == ICE || P == NORMAL || P == ROCK))
		effectiveness *= 2;
	if (a->type == DRAGON && P == DRAGON)
		effectiveness *= 2;
	if (a->type == WATER && (P == FIRE || P == ROCK || P == GROUND))
		effectiveness *= 2;
	if (a->type == ELEC && (P == WATER || P == FLY))
		effectiveness *= 2;
	if (a->type == FIRE && (P == ICE || P == INSECT || P == PLANT))
		effectiveness *= 2;
	if (a->type == ICE && (P == DRAGON || P == PLANT || P == ROCK ||
		P == FLY))
		effectiveness *= 2;
	if (a->type == INSECT && (P == PLANT || P == POISON || P == PSY))
		effectiveness *= 2;
	if (a->type == PLANT && (P == WATER || P == ROCK || P == GROUND))
		effectiveness *= 2;
	return (effectiveness * is_effective2(a, P));
}
