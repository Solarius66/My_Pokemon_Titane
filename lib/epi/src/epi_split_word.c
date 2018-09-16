/*
** EPITECH PROJECT, 2018
** lib 2.0
** File description:
** epi_split but with words as splitters
*/

#include "../internal.h"

/*
**works like epi_split_words but put the integer *is_good at -1 if two
**separators are attached
*/
char **epi_split_facade(char *str, char *splitters, int *is_good)
{
	char **sol = epi_split_words(str, splitters);

	for (int i = 0; str[i]; ++i) {
		if (epi_start_with(&str[i], splitters) == -1)
			continue;
		i += epi_start_with(&str[i], splitters);
		if (epi_start_with(&str[i], splitters) == -1)
			continue;
		*is_good = -1;
		break;
	}
	return (sol);
}

/*
**takes a string and split it using the word given as argument
**if the word does not exist, returns NULL
*/
char **epi_split_words(char *str, char *splitters)
{
	int words = epi_count_words_words(str, splitters);
	char **sol = malloc(sizeof(char *) * (words + 1));
	int len = epi_strlen(str);
	int i = 0;

	if (sol == NULL || str == NULL || splitters == NULL)
		return (NULL);
	sol[words] = NULL;
	for (int j = 0; j < words; ++j)
		sol[j] = epi_malloc_spe(len, 127);
	for (int j = 0; sol[j]; ++j) {
		for (; epi_start_with(&str[i], splitters) != -1 && str[i];)
			i += epi_start_with(&str[i], splitters);
		for (int k = 0; str[i] &&
			epi_start_with(&str[i], splitters) == -1; ++k, ++i)
			sol[j][k] = str[i];
		epi_free(epi_remove_charac(&sol[j], 127));
	}
	return (sol);
}
