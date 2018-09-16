/*
** EPITECH PROJECT, 2018
** lib 2.0
** File description:
** split but with 2 mallocs
*/

#include "../internal.h"

/*
**takes a string as argument and split it in a light way,
**if '1' is given as argument, do not even remalloc the string
**WARNING, TO FREE THE DOUBLE ARRAY GIVEN, USE THE FOLLOWING COMMAND:
**epi_free_many(tab[0], tab, 1)
**DO NOT SORT THE ARRAY GIVEN
*/
char **epi_split_light(char *hey, char splitter, int is_malloc)
{
	char *str = hey;
	int word_nb = epi_count_words(str, splitter);
	char **sol = malloc(sizeof(char *) *(word_nb + 1));
	int j = 0;

	if (!is_malloc)
		str = epi_remalloc(str, -1);
	if (!sol || !str)
		return (NULL);
	sol[word_nb] = NULL;
	for (int i = 0; i < word_nb; ++i) {
		for (; str[j] == splitter && str[j]; ++j)
			str[j] = 0;
		sol[i] = &str[j];
		for (; str[j] && str[j] != splitter; ++j);
		for (; str[j] == splitter && str[j]; ++j)
			str[j] = 0;
	}
	epi_replace_charac(str, splitter, 0);
	return (sol);
}
