/*
** EPITECH PROJECT, 2018
** lib2.0
** File description:
** creating chained struct
*/

#include "../internal.h"

static void internal_init_chained(chained_t *actual, int id)
{
	actual->id = id;
	actual->next = NULL;
	actual->prev = NULL;
	actual->in = NULL;
}

chained_t *epi_create_chained(int alloc_number)
{
	chained_t *start = malloc(sizeof(chained_t));
	chained_t *actual = start;

	internal_init_chained(start, 0);
	if (alloc_number <= 0) {
		epi_free(start);
		return (NULL);
	}
	for (int i = 1; i < alloc_number; ++i) {
		actual->next = malloc(sizeof(chained_t));
		internal_init_chained(actual->next, i);
		actual = actual->next;
	}
	return (start);
}

chained_t *epi_create_dchained(int alloc_number)
{
	chained_t *start = malloc(sizeof(chained_t));
	chained_t *actual = start;

	internal_init_chained(start, 0);
	if (alloc_number <= 0) {
		epi_free(start);
		return (NULL);
	}
	for (int i = 1; i < alloc_number; ++i) {
		actual->next = malloc(sizeof(chained_t));
		internal_init_chained(actual->next, i);
		actual->next->prev = actual;
		actual = actual->next;
	}
	return (start);
}

void epi_add_chained(chained_t *start, int nb)
{
	chained_t *actual = start;
	chained_t *backup = NULL;
	int i = 0;

	for (; actual->next && actual->id != nb; ++i, actual = actual->next);
	backup = actual->next;
	actual->next = malloc(sizeof(chained_t));
	internal_init_chained(actual->next, i);
	actual = actual->next;
	actual->next = backup;
	for (; actual && actual->next; ++i, actual = actual->next) {
		epi_printf("%d\n", actual->id);
		actual->id = i;
	}
}

void epi_add_dchained(chained_t *start, int nb)
{
	chained_t *actual = start;
	chained_t *backup = NULL;
	int i = 0;

	for (; actual->next && actual->id != nb; ++i, actual = actual->next);
	backup = actual->next;
	actual->next = malloc(sizeof(chained_t));
	internal_init_chained(actual->next, i);
	actual->next->prev = actual;
	actual = actual->next;
	actual->next = backup;
	for (; actual && actual->next; ++i, actual = actual->next) {
		actual->id = i;
		actual->next->prev = actual;
	}
}
