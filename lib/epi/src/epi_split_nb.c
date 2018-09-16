/*
** EPITECH PROJECT, 2018
** lib 2.0
** File description:
** splitting with number
*/

#include "../internal.h"

void my_free(void *str)
{
	if (str)
		free(str);
}

char *get_first_words(char *str[], int nb, int *len)
{
	char *sol = fusion_str_many(str[0], NULL);
	char *temp = sol;

	*len = *len + 1;
	if (epi_strlen(sol) >= nb)
		return (sol);
	for (int i = 1; str[i]; ++i) {
		sol = fusion_str_many(sol, " ", str[i], NULL);
		if (epi_strlen(sol) > nb) {
			my_free(sol);
			return (temp);
		}
		if (temp) {
			my_free(temp);
			temp = NULL;
		}
		temp = sol;
		*len = *len + 1;
	}
	return (sol);
}

char **epi_split_nb(char *init, int nb, char *word_splitter)
{
	char **sol = NULL;
	char **str = epi_split_many(init, word_splitter);
	char *strbis = NULL;
	int to_remove = 0;

	for (; str[0];) {
		strbis = get_first_words(str, nb, &to_remove);
		sol = epi_dadd(sol, strbis);
		if (strbis) {
			epi_free(strbis);
			strbis = NULL;
		}
		for (; to_remove > 0 && str && str[0]; --to_remove)
			epi_ddestroy(epi_remove_line_nb(&str, 0));
	}
	epi_ddestroy(str);
	return (sol);
}
