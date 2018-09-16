/*
** EPITECH PROJECT, 2018
** lib 2.O
** File description:
** sort double array
*/

#include "../internal.h"

/*
**takes a string and returns a version with only non capital letters
**(replace the capital ones by the same non capital ones)
*/
char *epi_lower_str(char *str)
{
	char *sol = epi_remalloc(str, -1);

	if (!sol)
		return (NULL);
	for (int i = 0; str[i]; ++i) {
		if (str[i] >= 'A' && str[i] <= 'Z')
			sol[i] = str[i] + 32;
		else
			sol[i] = str[i];
	}
	return (sol);
}

/*
**INTERNAL LIB FUNCTION DO NOT USE /!\
*/
static int internal_is_first2(char *str1, char *str2, int i)
{
	if (str1[i] < str2[i])
		return (1);
	if (str2[i] < str1[i])
		return (2);
	return (0);
}

/*
**INTERNAL LIB FUNCTION DO NOT USE /!\
*/
static int internal_is_first(char *str1, char *str2)
{
	char *sol1 = epi_lower_str(str1);
	char *sol2 = epi_lower_str(str2);
	int i = 0;

	if (!str1 || !str2)
		return (-1);
	for (i = 0; sol1[i] && sol2[i]; ++i)
		if (internal_is_first2(sol1, sol2, i))
			return (internal_is_first2(sol1, sol2, i) +
			epi_free_many(sol1, sol2, 1));
	if (sol1[i] < sol2[i]) {
		epi_free_many(sol1, sol2, 1);
		return (1);
	}
	if (sol1[i] > sol2[i]) {
		epi_free_many(sol1, sol2, 1);
		return (2);
	}
	return (epi_free_many(sol1, sol2, 1));
}

/*
**takes a double array as argument and sort it by alphabetical order
**use bubble sort algorithme
**DO NOT SEND A DOUBLE ARRAY CREATED BY EPI_SPLIT_LIGHT OR IT WILL CAUSE A
**SEGMENTATION FAULT
*/
void epi_sort(char **tab)
{
	int bigger = 0;
	char *temp = NULL;

	if (!tab)
		return;
	for (int i = 0; tab[i] && tab[i + 1]; ++i) {
		bigger = internal_is_first(tab[i], tab[i + 1]);
		if (bigger == 2) {
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = -1;
		}
	}
}
