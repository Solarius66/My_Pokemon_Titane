/*
** EPITECH PROJECT, 2018
** my_rPOKEMONg
** File description:
** testing attack creation
*/

#include "declaration.h"
#include "criterion/criterion.h"

Test(attack_constructor, is_load_good)
{
	attack_t *att = NULL;

	att = create_all_attack();
	cr_expect(att != NULL);
	cr_expect(att->id == 0);
	epi_printf("%d, %s", att, att->name);
	epi_printf("%d", att->next);
}
