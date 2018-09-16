/*
** EPITECH PROJECT, 2018
** lib 2.0
** File description:
** nbr to decimal
*/

#include "../internal.h"

long long epi_pow(int nb, int power)
{
	long long tempo = (long long)nb;

	if (power == 0)
		return (1);
	for (int i = 0; i < power; ++i)
		tempo = tempo * nb;
	return (tempo);
}

int epi_find_in_array(char *str, char c)
{
	for (int i = 0; str[i]; ++i)
		if (str[i] == c)
			return (i);
	epi_printf("%s, %s<", str, &c);
	return (-1);
}

long long epi_putnbr_dec(char *nbr, int base_nb)
{
	char *base = "0123456789abcdefghijklmnopqrstuvwxyz";
	int len = epi_strlen(nbr) - 1;
	long long sol = 0;

	if (base_nb > 36)
		base_nb = 36;
	if (base_nb < 2)
		base_nb = 2;
	if (len > 128)
		return (0);
	for (int i = len; i >= 0; --i) {
		sol = sol + epi_find_in_array(base, nbr[i]) *
		epi_pow(base_nb, i);
	}
	return (sol);
}
