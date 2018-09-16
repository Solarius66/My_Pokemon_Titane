/*
** EPITECH PROJECT, 2018
** lib 2.0
** File description:
** putf flags
*/

#include "../internal.h"

char *epi_getstr_o(char *str)
{
	char *sol = epi_malloc(1);
	char *tmp;
	char *temp;

	for (int i = 0; str[i]; ++i) {
		if (str[i] >= 32 && str[i] != 127)
			free(epi_stradd(&sol, str[i]));
		else {
			tmp = sol;
			temp = epi_getchar_o(str[i]);
			sol = fusion_str_many(sol, temp, NULL);
			free(tmp);
			free(temp);
		}
	}
	return (sol);
}

char *epi_getchar_o(char c)
{
	char *sol = epi_putnbr_base((long long)c, 8);
	int len = epi_strlen(sol);
	char *str;

	if (!sol)
		return (NULL);
	if (len != 1 && len != 2)
		str = fusion_str_many("\\", sol, NULL);
	if (len == 1)
		str = fusion_str_many("\\", "00", sol, NULL);
	if (len == 2)
		str = fusion_str_many("\\", "0", sol, NULL);
	return (str);
}

char *epi_hash_gest2(va_list list, char *str, int *i)
{
	char *sol;
	char *tmp;

	switch (str[*i]) {
	case 'X':
		sol = epi_putnbr_base_maj(va_arg(list, int), 16);
		if (sol[0] != '0') {
			tmp = sol;
			sol = fusion_str_many("0X", sol, NULL);
			free(tmp);
		}
		return (sol);
	}
	return (NULL);
}

char *epi_hash_gest(va_list list, char *str, int *i)
{
	char *sol;
	char *tmp;

	if (str[*i] == 'o' && (sol = epi_putnbr_base(va_arg(list, int), 8))) {
		if (sol[0] != '0') {
			tmp = sol;
			sol = fusion_str_many("0", sol, NULL);
			free(tmp);
		}
		return (sol);
	} else if (str[*i] == 'x') {
		sol = epi_putnbr_base(va_arg(list, int), 16);
		if (sol[0] != '0') {
			tmp = sol;
			sol = fusion_str_many("0x", sol, NULL);
			free(tmp);
		}
		return (sol);
	} else
		return (epi_hash_gest2(list, str, i));
}
