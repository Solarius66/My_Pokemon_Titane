/*
** EPITECH PROJECT, 2018
** my_rPOKEMONg
** File description:
** test attack system
*/

#include "declaration.h"
#include "criterion/criterion.h"
#define TEST_WITNESS "this test was supposed to fail and it failed, \
what a wonderful world."

Test(is_effective, dont_affect)
{
	attack_t a;

	a.type = PHANTOM;
	cr_expect(is_effective(&a, NORMAL) == 0);
	a.type = GROUND;
	cr_expect(is_effective(&a, FLY) == 0);
	a.type = NORMAL;
	cr_expect(is_effective(&a, PHANTOM) == 0);
	a.type = ELEC;
	cr_expect(is_effective(&a, GROUND) == 0);
	a.type = FIGHT;
	cr_expect(is_effective(&a, PHANTOM) == 0);
	cr_expect(is_effective(&a, GROUND) == 1);
}

Test(is_effective, super_effective_1)
{
	attack_t a;

	a.type = FIGHT;
	cr_expect(is_effective(&a, ICE) == 2);
	cr_expect(is_effective(&a, NORMAL) == 2);
	cr_expect(is_effective(&a, ROCK) == 2);
	a.type = DRAGON;
	cr_expect(is_effective(&a, DRAGON) == 2);
	a.type = WATER;
	cr_expect(is_effective(&a, FIRE) == 2);
	cr_expect(is_effective(&a, ROCK) == 2);
	cr_expect(is_effective(&a, GROUND) == 2);
	a.type = ELEC;
	cr_expect(is_effective(&a, WATER) == 2);
	cr_expect(is_effective(&a, FLY) == 2);
	a.type = FIRE;
	cr_expect(is_effective(&a, ICE) == 2);
	cr_expect(is_effective(&a, INSECT) == 2);
	cr_expect(is_effective(&a, PLANT) == 2);
}

Test(is_effective, super_effective_2)
{
	attack_t a;

	a.type = ICE;
	cr_expect(is_effective(&a, DRAGON) == 2);
	cr_expect(is_effective(&a, PLANT) == 2);
	cr_expect(is_effective(&a, ROCK) == 2);
	cr_expect(is_effective(&a, FLY) == 2);
	a.type = INSECT;
	cr_expect(is_effective(&a, PLANT) == 2);
	cr_expect(is_effective(&a, POISON) == 2);
	cr_expect(is_effective(&a, PSY) == 2);
	a.type = PLANT;
	cr_expect(is_effective(&a, WATER) == 2);
	cr_expect(is_effective(&a, ROCK) == 2);
	cr_expect(is_effective(&a, GROUND) == 2);
	a.type = POISON;
	cr_expect(is_effective(&a, INSECT) == 2);
	cr_expect(is_effective(&a, PLANT) == 2);
}

Test(is_effective, super_effective_3)
{
	attack_t a;

	a.type = PSY;
	cr_expect(is_effective(&a, FIGHT) == 2);
	cr_expect(is_effective(&a, POISON) == 2);
	a.type = ROCK;
	cr_expect(is_effective(&a, FIRE) == 2);
	cr_expect(is_effective(&a, ICE) == 2);
	cr_expect(is_effective(&a, INSECT) == 2);
	cr_expect(is_effective(&a, FLY) == 2);
	a.type = GROUND;
	cr_expect(is_effective(&a, ELEC) == 2);
	cr_expect(is_effective(&a, FIRE) == 2);
	cr_expect(is_effective(&a, POISON) == 2);
	cr_expect(is_effective(&a, ROCK) == 2);
	a.type = PHANTOM;
	cr_expect(is_effective(&a, PHANTOM) == 2);
	a.type = FLY;
	cr_expect(is_effective(&a, FIGHT) == 2);
	cr_expect(is_effective(&a, INSECT) == 2);
	cr_expect(is_effective(&a, PLANT) == 2);
}

Test(is_effective, not_effective)
{
	attack_t a;

	a.type = FIGHT;
	cr_expect(is_effective(&a, INSECT) == 0.5);
	cr_expect(is_effective(&a, POISON) == 0.5);
	cr_expect(is_effective(&a, PSY) == 0.5);
	cr_expect(is_effective(&a, FLY) == 0.5);
	a.type = WATER;
	cr_expect(is_effective(&a, DRAGON) == 0.5);
	cr_expect(is_effective(&a, WATER) == 0.5);
	cr_expect(is_effective(&a, PLANT) == 0.5);
	a.type = ELEC;
	cr_expect(is_effective(&a, DRAGON) == 0.5);
	cr_expect(is_effective(&a, ELEC) == 0.5);
	cr_expect(is_effective(&a, PLANT) == 0.5);
	a.type = FIRE;
	cr_expect(is_effective(&a, DRAGON) == 0.5);
	cr_expect(is_effective(&a, WATER) == 0.5);
	cr_expect(is_effective(&a, FIRE) == 0.5);
	cr_expect(is_effective(&a, ROCK) == 0.5);
}
