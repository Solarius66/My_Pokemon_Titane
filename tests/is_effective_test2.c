/*
** EPITECH PROJECT, 2018
** my RPokemonG
** File description:
** du de les tests unit'ères
*/

#include "declaration.h"
#include "criterion/criterion.h"
#define TEST_WITNESS "this test was supposed to fail and it failed, \
what a wonderful world."

Test(is_effective, another_test)
{
	attack_t a;

	a.type = ICE;
	cr_expect(is_effective(&a, WATER) == 0.5);
	cr_expect(is_effective(&a, ICE) == 0.5);
	a.type = INSECT;
	cr_expect(is_effective(&a, FIGHT) == 0.5);
	cr_expect(is_effective(&a, FIRE) == 0.5);
	cr_expect(is_effective(&a, PHANTOM) == 0.5);
	cr_expect(is_effective(&a, FLY) == 0.5);
	a.type = NORMAL;
	cr_expect(is_effective(&a, ROCK) == 0.5);
	a.type = PLANT;
	cr_expect(is_effective(&a, DRAGON) == 0.5);
	cr_expect(is_effective(&a, FIRE) == 0.5);
	cr_expect(is_effective(&a, INSECT) == 0.5);
	cr_expect(is_effective(&a, PLANT) == 0.5);
	cr_expect(is_effective(&a, POISON) == 0.5);
	cr_expect(is_effective(&a, FLY) == 0.5);
}

Test(is_effective, im_a_potato)
{
	attack_t a;

	a.type = POISON;
	cr_expect(is_effective(&a, POISON) == 0.5);
	cr_expect(is_effective(&a, ROCK) == 0.5);
	cr_expect(is_effective(&a, GROUND) == 0.5);
	cr_expect(is_effective(&a, PHANTOM) == 0.5);
	a.type = PSY;
	cr_expect(is_effective(&a, PSY) == 0.5);
	a.type = ROCK;
	cr_expect(is_effective(&a, PLANT) == 0.5);
	a.type = FLY;
	cr_expect(is_effective(&a, ELEC) == 0.5);
	cr_expect(is_effective(&a, ROCK) == 0.5);
}

Test(is_effective, crash_test)
{
	attack_t a;
	pokemon_t p;

	p.type1 = FIRE;
	p.type2 = NO_TYPE;
	p.attack_chosen.type = FIRE;
	a.type = WATER;
	cr_expect(is_effective(&a, FIRE) == 0.5, TEST_WITNESS);
	cr_expect(get_stab(&p) == 1, "that one too, unbelivable...");
}

Test(STAB, is_stab_good)
{
	pokemon_t p;

	p.type1 = NORMAL;
	p.type2 = NO_TYPE;
	p.attack_chosen.type = NORMAL;
	cr_expect(get_stab(&p) == 1.5);
	p.type1 = NORMAL;
	p.type2 = FIRE;
	p.attack_chosen.type = FIRE;
	cr_expect(get_stab(&p) == 1.5);
}
