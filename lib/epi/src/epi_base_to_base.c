/*
** EPITECH PROJECT, 2018
** lib2.0
** File description:
** converting a number in base a to a number in base b
*/

#include "../internal.h"

/*
**takes a number (char *) in a number base1 and returns it in base base2
**base are between base 2 and base 32
**if the base are under or over the limits, it will be casted
*/
char *epi_base_to_base(char *str, int base1, int base2, int is_maj)
{
	long long number = epi_putnbr_dec(str, base1);
	char *sol = NULL;

	if (is_maj == 1) {
		sol = epi_putnbr_base_maj(number, base2);
	} else {
		sol = epi_putnbr_base(number, base2);
	}
	return (sol);
}
