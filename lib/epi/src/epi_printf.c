/*
** EPITECH PROJECT, 2018
** lib 2.0
** File description:
** 2 month later :D
*/

#include "../internal.h"

void switch_manage4(va_list list, char *str, int *i)
{
	switch (str[*i]) {
	case '#':
		*i += 1;
		hash_gest(list, str, i);
		break;
	case 'S':
		epi_putstr_o(va_arg(list, char *));
		break;
	default:
		switch_manage(list, str[*i]);
	}
}

void switch_manage3(va_list list, char c)
{
	switch (c) {
	case 'c':
		epi_putchar((unsigned char)va_arg(list, int));
		break;
	case 'b':
		epi_printnbr_base(va_arg(list, unsigned int), 2);
		break;
	case 'p':
		epi_putstr("0x");
		epi_printnbr_base(va_arg(list, long long), 16);
		break;
	default:
		epi_printf("error: flag '%%%c' not found.\n", c);
	}
}

void switch_manage2(va_list list, char c, unsigned int i)
{
	switch (c) {
	case 'o':
		epi_printnbr_base(va_arg(list, long long), 8);
		break;
	case 'u':
		i = va_arg(list, unsigned int);
		epi_printnbr_base(i, 10);
		break;
	case 'x':
		epi_printnbr_base((long long)va_arg(list, int), 16);
		break;
	case 'X':
		epi_printnbr_base_maj((long long)va_arg(list, int), 16);
		break;
	default:
		switch_manage3(list, c);
	}
}

void switch_manage(va_list list, char c)
{
	switch (c) {
	case 's':
		epi_putstr(va_arg(list, char *));
		break;
	case 'i':
	case 'd':
		epi_printnbr_base(va_arg(list, int), 10);
		break;
	case 'F':
	case 'f':
		epi_putfloat(va_arg(list, double));
		break;
	case '%':
		epi_putstr("%");
		break;
	default:
		switch_manage2(list, c, 0);
	}
}

int epi_printf(char *str, ...)
{
	va_list list;

	va_start(list, str);
	if (str == NULL) {
		epi_putstr(NULL);
		return (0);
	}
	for (int i = 0; str[i]; ++i) {
		if (str[i] == '%') {
			++i;
			switch_manage4(list, str, &i);
		} else
			write(1, &str[i], 1);
	}
	va_end(list);
	return (0);
}
