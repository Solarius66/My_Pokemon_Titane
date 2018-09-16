/*
** EPITECH PROJECT, 2018
** lib 2.0
** File description:
** epi_wordtoarray
*/

#include "../internal.h"

char *epi_join(char **str, char separator)
{
	int nb = epi_dstrlen(str);
	int length = 0;
	int count = 0;
	char *sol;

	for (int i = 0; nb > i; ++i)
		length += epi_strlen(str[i]);
	length += nb - 1;
	sol = epi_malloc(length);
	for (length = 0; str[length]; ++length) {
		for (int i = 0; str[length][i]; ++i, ++count)
			sol[count] = str[length][i];
		if (str[length + 1] != NULL) {
			sol[count] = separator;
			++count;
		}
	}
	return (sol);
}

int get_argument(char *sol, int *k, int *i, char *str)
{
	char c = str[*i];

	if (c != 34 && c != 39) {
		sol[*k] = str[*i];
		*i += 1;
		*k += 1;
		return (0);
	}
	for (int j = 0; str[*i - 1] != c || j < 2; *k += 1, *i += 1, ++j) {
		if (str[*i] == 0)
			break;
		sol[*k] = str[*i];
	}
	return (0);
}

char **epi_split_arg(char *str, char separator)
{
	int word_nb = epi_count_words_arg(str, separator);
	int len = epi_strlen(str);
	char **sol = malloc(sizeof(char *) * (word_nb + 1));
	int i = 0;

	if (sol == NULL || str == NULL)
		return (NULL);
	sol[word_nb] = NULL;
	for (int i = 0; i < word_nb; ++i)
		sol[i] = epi_malloc_spe(len, 127);
	for (int j = 0; sol[j]; ++j) {
		for (; str[i] == separator && str[i]; ++i);
		for (int k = 0; str[i] != separator && str[i] != 0;)
			get_argument(sol[j], &k, &i, str);
		free(epi_remove_charac(&sol[j], 127));
	}
	return (sol);
}

char **epi_split(char *str, char separator)
{
	int word_nb = epi_count_words(str, separator);
	int len = epi_strlen(str);
	char **sol = malloc(sizeof(char *) * (word_nb + 1));
	int i = 0;

	if (sol == NULL || sol == NULL)
		return (NULL);
	sol[word_nb] = NULL;
	for (int i = 0; i < word_nb; ++i)
		sol[i] = epi_malloc_spe(len, 127);
	for (int j = 0; sol[j]; ++j) {
		for (; str[i] == separator && str[i] != 0; ++i);
		for (int k = 0; str[i] != separator && str[i] != 0; ++i, ++k)
			sol[j][k] = str[i];
		free(epi_remove_charac(&sol[j], 127));
	}
	return (sol);
}
