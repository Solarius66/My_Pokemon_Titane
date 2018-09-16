/*
** EPITECH PROJECT, 2018
** lib 2.0
** File description:
** int to array
*/

#include "../internal.h"

char *epi_itoa(int nb)
{
	int length = (length_nb(nb));
	char *str = epi_malloc((length));
	int save = 0;

	if (str == NULL)
		return (NULL);
	if (nb == 0) {
		str[0] = 48;
		return (str);
	} else if (nb < 0) {
		str[0] = '-';
		nb = nb * -1;
	}
	for (int i = 1; nb >= 1; ++i) {
		save = nb % 10;
		nb = nb / 10;
		str[length - i] = (save + 48);
	}
	return (str);
}
