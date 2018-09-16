/*
** EPITECH PROJECT, 2018
** lib 2.0
** File description:
** the # printf flag
*/

#include "../internal.h"

void epi_putchar_o(char);

void epi_putstr_o(char *str)
{
	for (int i = 0; str[i]; ++i) {
		if (str[i] >= 32 && str[i] != 127)
			epi_putchar(str[i]);
		else
			epi_putchar_o(str[i]);
	}
}

void epi_putchar_o(char c)
{
	char *sol = epi_putnbr_base((long long)c, 8);
	int len = epi_strlen(sol);

	epi_putstr("\\");
	if (len == 1)
		epi_putstr("00");
	if (len == 2)
		epi_putstr("0");
	epi_putstr(sol);
	free(sol);

}

void hash_gest2(va_list list, char *str, int *i)
{
	char *sol;

	switch (str[*i]) {
	case 'X':
		sol = epi_putnbr_base_maj(va_arg(list, int), 16);
		if (sol[0] != '0')
			epi_putstr("0X");
		epi_putstr(sol);
		free(sol);
		break;
	}
}

void hash_gest(va_list list, char *str, int *i)
{
	char *sol;

	switch (str[*i]) {
	case 'o':
		sol = epi_putnbr_base(va_arg(list, int), 8);
		if (sol[0] != '0')
			epi_putstr("0");
		epi_putstr(sol);
		free(sol);
		break;
	case 'x':
		sol = epi_putnbr_base(va_arg(list, int), 16);
		if (sol[0] != '0')
			epi_putstr("0x");
		epi_putstr(sol);
		free(sol);
		break;
	default:
		hash_gest2(list, str, i);
	}
}
