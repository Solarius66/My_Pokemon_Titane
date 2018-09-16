/*
** EPITECH PROJECT, 2018
** lib 2.0
** File description:
** replace all charac c in str
*/

#include "../internal.h"

int epi_reverse_str(char *str)
{
	int nb = epi_strlen(str) - 1;
	char c = 0;

	for (int i = 0; i < nb; ++i, --nb) {
		c = str[i];
		str[i] = str[nb];
		str[nb] = c;
	}
	return (0);
}

char *epi_remove_charac(char **str, char char_to_remove)
{
	int new_length = 0;
	char *temp = *str;

	if (char_to_remove == 0) {
		epi_printf("error, \0 cannot be remove\n");
		return (NULL);
	}
	for (int i = 0; temp[i]; ++i)
		if (temp[i] != char_to_remove)
			++new_length;
	*str = epi_malloc_spe(new_length, 127);
	new_length = 0;
	for (int i = 0; temp[i]; ++i)
		if (temp[i] != char_to_remove) {
			str[0][new_length] = temp[i];
			++new_length;
		}
	return (temp);
}

int epi_replace_charac(char *str, char charac_to_replace, char charac_replaced)
{
	if (charac_to_replace == 0) {
		epi_printf("error, \0 cannot be replaced\n");
		return (-1);
	}
	for (int i = 0; str[i]; ++i) {
		if (str[i] == charac_to_replace)
			str[i] = charac_replaced;
	}
	return (0);
}
