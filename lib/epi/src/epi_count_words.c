/*
** EPITECH PROJECT, 2018
** lib 2.0
** File description:
** my count words
*/

#include "../internal.h"

void epi_skip_word(int *i, char *str, char quote)
{
	*i += 1;
	for (; str[*i] != quote; *i += 1)
		if (str[*i] == 0)
			break;
}

int epi_count_words_arg(char *str, char space)
{
	int word_nb = 0;

	if (str[0] != space && str[0] != 0)
		++word_nb;
	for (int i = 0; str[i]; ++i) {
		if (str[i] == 34)
			epi_skip_word(&i, str, 34);
		if (str[i] == 39)
			epi_skip_word(&i, str, 39);
		if (str[i] == space && str[i + 1] &&
			str[i + 1] != space)
			++word_nb;
	}
	return (word_nb);
}

int epi_count_words(char *str, char space)
{
	int word_nb = 0;

	if (str[0] != space && str[0] != 0)
		++word_nb;
	for (int i = 0; str[i]; ++i) {
		if (str[i] == space && str[i + 1] != space &&
			str[i + 1])
			++word_nb;
	}
	return (word_nb);
}
