/*
** EPITECH PROJECT, 2018
** lib 2.0
** File description:
** putnbr_base
*/

#include "../internal.h"

int epi_printnbr_base_maj(long long nb, int base_nb)
{
	char *str = epi_putnbr_base_maj(nb, base_nb);

	epi_putstr(str);
	free(str);
	return (0);
}

int epi_printnbr_base(long long nb, int base_nb)
{
	char *str = epi_putnbr_base(nb, base_nb);

	epi_putstr(str);
	free(str);
	return (0);
}

char *epi_putnbr_base_maj(long long nb, int base_nb)
{
	char *base = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *str = epi_malloc_spe(128, 127);

	if (base_nb > epi_strlen(base))
		base_nb = epi_strlen(base);
	if (base_nb < 2)
		base_nb = 2;
	if (nb == 0)
		str[0] = '0';
	for (int i = 0; nb >= 1; ++i) {
		str[i] = base[nb % base_nb];
		nb = nb / base_nb;
	}
	epi_replace_charac(str, 127, '\0');
	epi_reverse_str(str);
	return (str);
}

char *epi_putnbr_base(long long nb, int base_nb)
{
	char *base = "0123456789abcdefghijklmnopqrstuvwxyz";
	char *str = epi_malloc_spe(128, 127);

	if (base_nb > epi_strlen(base))
		base_nb = epi_strlen(base);
	if (base_nb < 2)
		base_nb = 2;
	if (nb == 0)
		str[0] = '0';
	for (int i = 0; nb >= 1; ++i) {
		str[i] = base[nb % base_nb];
		nb = nb / base_nb;
	}
	epi_replace_charac(str, 127, '\0');
	epi_reverse_str(str);
	return (str);
}
