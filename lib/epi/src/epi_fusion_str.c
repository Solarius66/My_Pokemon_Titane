/*
** EPITECH PROJECT, 2018
** okay
** File description:
** RAAAAAAH
*/

#include "../internal.h"

char *fusion_str_many2(char *str, char *sol)
{
	if (str == NULL)
		str = epi_remalloc(sol, -1);
	else
		str = fusion_str(str, sol);
	return (str);
}

char *fusion_str_many(char *str, ...)
{
	char *tempo = NULL;
	char *sol = NULL;
	int boolean = 0;
	va_list list;

	va_start(list, str);
	for (; 1;) {
		sol = va_arg(list, char *);
		if (sol == NULL && boolean == 0) {
			str = epi_remalloc(str, -1);
			break;
		} else if (sol == NULL)
			break;
		boolean = 1;
		str = fusion_str_many2(str, sol);
		epi_free(tempo);
		tempo = str;
	}
	va_end(list);
	return (str);
}

char *fusion_str(char *str, char *str2)
{
	int j = 0;
	int size1 = epi_strlen(str);
	int size2 = epi_strlen(str2);
	int size = size1 + size2;
	char *sol = malloc(sizeof(char) * (size + 1));

	clear_malloc(sol, size);
	if (sol == NULL)
		return (NULL);
	for (int i = 0; str[i]; ++i, ++j)
		sol[j] = str[i];
	for (int i = 0; str2[i]; ++i, ++j)
		sol[j] = str2[i];
	sol[size] = 0;
	return (sol);
}
