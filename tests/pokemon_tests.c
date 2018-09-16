/*
** EPITECH PROJECT, 2018
** a test file
** File description:
** creating pokemon tests
*/

#include "declaration.h"
#include "criterion/criterion.h"

Test(pokemon_creator_from_file, all_tests)
{
	pokemon_t *pokemon = create_all_pokemon(NULL);
	for (int i = 1; pokemon->next; pokemon = pokemon->next, ++i)
		cr_expect(pokemon->id == i);
}
