/*
** EPITECH PROJECT, 2018
** lib 2.0
** File description:
** putf and not printf!!!!
*/

#include "../internal.h"

char *epi_switch4(va_list list, char c)
{
	char *sol = epi_malloc(1);

	switch (c) {
	case 'c':
		free(epi_stradd(&sol, (char)va_arg(list, int)));
		return (sol);
	default:
		return (NULL);
	}
	return (NULL);
}

char *epi_switch3(va_list list, char c, unsigned int i)
{
	switch (c) {
	case 'o':
		return (epi_putnbr_base(va_arg(list, long long), 8));
	case 'u':
		i = va_arg(list, unsigned int);
		return (epi_putnbr_base(i, 10));
	case 'x':
		return (epi_putnbr_base((long long)va_arg(list, int), 16));
	case 'X':
		return (epi_putnbr_base_maj((long long)va_arg(list, int), 16));
	case 'b':
		return (epi_putnbr_base(va_arg(list, unsigned int), 2));
	case 'p':
		return (fusion_str_many("0x", epi_putnbr_base(va_arg(list,
		long long), 16), NULL));
	default:
		return (epi_switch4(list, c));
	}
	return (NULL);
}

char *epi_switch2(va_list list, char c)
{
	switch (c) {
	case 's':
		return (epi_remalloc(va_arg(list, char *), -1));
	case 'i':
	case 'd':
		return (epi_itoa(va_arg(list, int)));
	case 'F':
	case 'f':
		return (epi_dtoa(va_arg(list, double)));
	case '%':
		return (epi_remalloc("%", -1));
	default:
		return (epi_switch3(list, c, 0));
	}
	return (NULL);
}

char *epi_switch1(va_list list, char *str, int *i)
{
	switch (str[*i]) {
	case '#':
		*i += 1;
		return (epi_hash_gest(list, str, i));
		break;
	case 'S':
		return (epi_getstr_o(va_arg(list, char *)));
		break;
	default:
		return (epi_switch2(list, str[*i]));
	}
	return (NULL);
}

char *epi_vprintf(char *str, va_list list)
{
	char *sol = NULL;
	char *tmp = NULL;
	char *temp = NULL;

	if (str == NULL)
		return (NULL);
	for (int i = 0; str[i]; ++i) {
		if (str[i] == '%') {
			++i;
			tmp = epi_switch1(list, str, &i);
			temp = sol;
			sol = fusion_str_many(sol, tmp, NULL);
			epi_free(temp);
			epi_free(tmp);
			temp = NULL;
			tmp = NULL;
		} else
			epi_free(epi_stradd(&sol, str[i]));
	}
	return (sol);
}
