/*
** EPITECH PROJECT, 2017
** match!
** File description:
** hello <3
*/

#include "../internal.h"

int nmatch(char const *s1, char const *s2)
{
	if (*s1 == 0 && *s2 == 0)
		return (1);
	if (*s2 == '*' && *s1 != 0)
		return (nmatch((s1 + 1), s2) + nmatch(s1, (s2 + 1)));
	if (*s2 == '*' && *s1 == 0)
		return (nmatch(s1, (s2 + 1)));
	if (*s1 == *s2)
		return (nmatch((s1 + 1), (s2 + 1)));
	return (0);
}
