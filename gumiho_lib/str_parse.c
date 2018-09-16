/*
** EPITECH PROJECT, 2018
** MY_STR_TO_WORD_ARRAY
** File description:
** Returns parsed version of str using delimiter
*/

#include "gumiho_lib.h"

static int word_len(char *str, char delimiter)
{
	int len = 0;

	while (str[len] != '\0' && str[len] != delimiter)
		++len;
	return (len);
}

static int get_words_nb(char *str, char delimiter)
{
	int nb = 0;
	int i = 0;

	while (str[i] != '\0') {
		while (str[i] == delimiter)
			++i;
		if (str[i] == '\0')
			break;
		++nb;
		while (str[i] != delimiter && str[i] != '\0')
			++i;
	}
	return (nb);
}

char **str_parse(char *str, char d)
{
	int words_nb = get_words_nb(str, d);
	char **array;
	int y = 0;

	if ((array = malloc(sizeof(char *) * (words_nb + 1))) == NULL)
		return NULL;
	array[words_nb] = NULL;
	for (int i = 0; str[i];) {
		while (str[i] == d)
			++i;
		if (str[i] == '\0')
			break;
		array[y] = malloc(sizeof(char) * (word_len(str + i, d) + 1));
		array[y][word_len(str + i, d)] = '\0';
		for (int x = 0; str[i] != d && str[i] != '\0'; ++x) {
			array[y][x] = str[i];
			++i;
		}
		++y;
	}
	return (array);
}
