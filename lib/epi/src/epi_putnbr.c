/*
** EPITECH PROJECT, 2018
** lib 2.0
** File description:
** putnbr et putnbr_err
*/

#include "../internal.h"

int length_nb3(int nb)
{
	if (nb > -1000000000)
		return (10);
	return (11);
}

int length_nb2(int nb)
{
	if (nb > -1)
		return (1);
	if (nb > -10)
		return (2);
	if (nb > -100)
		return (3);
	if (nb > -1000)
		return (4);
	if (nb > -10000)
		return (5);
	if (nb > -100000)
		return (6);
	if (nb > -1000000)
		return (7);
	if (nb > -10000000)
		return (8);
	if (nb > -100000000)
		return (9);
	return (length_nb3(nb));
}

int length_nb(int nb)
{
	if (nb >= 1000000000)
		return (10);
	if (nb >= 100000000)
		return (9);
	if (nb >= 10000000)
		return (8);
	if (nb >= 1000000)
		return (7);
	if (nb >= 100000)
		return (6);
	if (nb >= 10000)
		return (5);
	if (nb >= 1000)
		return (4);
	if (nb >= 100)
		return (3);
	if (nb >= 10)
		return (2);
	return (length_nb2(nb));
}

int epi_putnbr_err(int nb)
{
	char *str = epi_itoa(nb);

	epi_puterr(str);
	if (str != NULL && nb != 0)
		free(str);
	return (0);

}

int epi_putnbr(int nb)
{
	char *str = epi_itoa(nb);

	epi_putstr(str);
	if (str != NULL && nb != 0)
		free(str);
	return (0);
}
