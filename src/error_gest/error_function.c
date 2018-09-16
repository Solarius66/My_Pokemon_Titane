/*
** EPITECH PROJECT, 2018
** epi_overcooked
** File description:
** does the func exist?
*/

#include "declaration.h"

int sfml_check_err(void)
{
	sfTexture *test = sfTexture_createFromFile(PLAYER, NULL);
	sfSprite *test2 = sfSprite_create();
	int error_count = 0;

	if (test == NULL) {
		epi_puterr("CSMFL error: missing functions\n");
		++error_count;
	} else
		sfTexture_destroy(test);
	if (test2 == NULL) {
		epi_puterr("CSFML error: mission functions\n");
		++error_count;
	} else
		sfSprite_destroy(test2);
	return (error_count);
}

int error_func(void)
{
	char *str = malloc(sizeof(char));
	int error_count = 0;

	if (str == NULL) {
		epi_puterr("allocation error:\n");
		epi_puterr("stdlib problem: malloc function");
		++error_count;
	} else
		free(str);
	if (open("./Makefile", O_RDONLY) < 3) {
		epi_puterr("opening file error:\n");
		epi_puterr("problem in one of the following lib:\n");
		epi_puterr("types\nstat\nfcntl\n");
		++error_count;
	}
	return (sfml_check_err() + error_count);
}
