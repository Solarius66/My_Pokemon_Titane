/*
** EPITECH PROJECT, 2018
** epi_overcooked
** File description:
** error
*/

#include "declaration.h"

int error_main(void)
{
	int error_nb = 0;

	error_nb += error_func();
	if (error_nb < 0)
		return (84);
	error_nb += error_music();
	error_nb += error_graph();
	if (error_nb > 0) {
		epi_puterr("Error: \n");
		epi_puterr("please check if some files or lib are missing.\n");
		return (84);
	}
	return (0);
}
