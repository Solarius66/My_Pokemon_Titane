/*
** EPITECH PROJECT, 2018
** lib2.0
** File description:
** get string between next separators
*/

#include "../internal.h"

/*
**gets the string that is contain between sep1 et sep2
**if sep1 or sep2 or str is null, returns NULL
**if the string ends before sep2 is found, '\0' is considered as sep2
**if the string does not find sep1, returns NULL
**if there is an allocation error, returns NULL
*/
char *epi_get_word(char *str, char *sep1, char *sep2)
{
	int i = 0;
	int len = 0;
	char *sol = NULL;

	if (!str || !sep1 || !sep2)
		return (NULL);
	for (; str[i] && epi_start_with(str, sep1) == -1; ++i);
	if (!str[i])
		return (NULL);
	i += epi_start_with(str, sep1);
	for (; str[i + len] && epi_start_with(str, sep2) == -1; ++len);
	sol = epi_malloc(len);
	if (!sol)
		return (NULL);
	for (int j = 0; str[i] &&
		epi_start_with(&str[i], sep2) == -1; ++i, ++j)
		sol[j] = str[i];
	return (sol);
}
