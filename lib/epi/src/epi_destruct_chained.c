/*
** EPITECH PROJECT, 2018
** lib2.0
** File description:
** destroying chained list
*/

#include "../internal.h"

void epi_destruct_chained(chained_t *start)
{
	chained_t *actual = start;
	chained_t *backup = actual->next;

	for (; actual;) {
		if (actual)
			backup = actual->next;
		epi_free(actual);
		actual = NULL;
		actual = backup;
	}
}

void epi_remove_chained(chained_t *start, int nb)
{
	chained_t *actual = start;

	for (; actual && actual->next && actual->next->id != nb;)
		actual = actual->next;
	if (!actual && !actual->next)
		return;
	epi_free(actual->next);
	actual->next = NULL;
}
