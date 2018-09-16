/*
** EPITECH PROJECT, 2018
** lib 2.0
** File description:
** putfloat
*/

#include "../internal.h"

int epi_sec_pow(int nb, int pw)
{
	int save = nb;

	if (nb < 0)
		nb = 0;
	for (int i = 0; i < pw; ++i)
		nb = nb * save;
	return (nb);
}

char *epi_dtoa2(char *str, double i, int length)
{
	int save = 0;

	for (int j = 1; i >= 1; ++j) {
		save = (int)i % 10;
		i = i / 10.0;
		str[length - j] = (save + 48);
	}
	return (str);
}

char *epi_dtoa(double i)
{
	int length = length_nb(i);
	char *str = NULL;

	if (i == 0)
		return ("0.0");
	str = epi_malloc((length + 7));
	if (str == NULL)
		return (NULL);
	if (i < 0)
		str[0] = '-';
	for (int j = 6; j >= 0; --j) {
		str[length + j] = ((int)(i * epi_sec_pow(10, j - 1)) % 10) + 48;
	}
	str[length] = '.';
	str = epi_dtoa2(str, i, length);
	return (str);
}

int epi_putfloat_err(double i)
{
	char *str = epi_dtoa(i);

	epi_puterr(str);
	if (str != NULL && i != 0.0)
		free(str);
	return (0);
}

int epi_putfloat(double i)
{
	char *str = epi_dtoa(i);

	epi_putstr(str);
	if (str != NULL && i != 0.0)
		free(str);
	return (0);
}
