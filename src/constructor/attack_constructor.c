/*
** EPITECH PROJECT, 2018
** my_rPOKEMONg
** File description:
** creating all attacks
*/

#include "declaration.h"

int fill_attack(attack_t *new, int i, char *str)
{
	new->status = (status)epi_atoi(&str[i]);
	++i;
	for (; str[i - 1] != ','; ++i);
	new->power = epi_atoi(&str[i]);
	++i;
	for (; str[i - 1] != ','; ++i);
	new->precision = epi_atoi(&str[i]);
	++i;
	for (; str[i - 1] != ','; ++i);
	new->priority = (short)epi_atoi(&str[i]);
	++i;
	for (; str[i - 1] != ','; ++i);
	new->name = epi_malloc(epi_strlen(str) - i - 1);
	for (int j = 0; str[i] != '\n'; ++j, ++i)
		new->name[j] = str[i];
	return (0);
}

int parse_attack_conf(FILE *stream, attack_t *new)
{
	char *str = NULL;
	size_t len = 0;
	int i = 1;

	if (getline(&str, &len, stream) <= 0) {
		free(str);
		return (1);
	}
	if (nmatch(str, "*,*") != 6)
		return (-1);
	new->id = epi_atoi(str);
	for (; str[i - 1] != ','; ++i);
	new->type = (pokemon_type)epi_atoi(&str[i]);
	++i;
	for (; str[i - 1] != ','; ++i);
	fill_attack(new, i, str);
	free(str);
	return (0);
}

attack_t *create_all_attack(void)
{
	FILE *stream = fopen("./config/attack.conf", "r");
	attack_t *new = malloc(sizeof(attack_t));
	attack_t *next = new;
	int error_gest = 0;

	error_gest = parse_attack_conf(stream, next);
	while (error_gest == 0) {
		if (error_gest == 0) {
			next->next = malloc(sizeof(attack_t));
			next = next->next;
			next->name = NULL;
			next->next = NULL;
		}
		error_gest = parse_attack_conf(stream, next);
		if (error_gest == -1)
			return (NULL);
	}
	fclose(stream);
	return (new);
}

void dup_attack(attack_t *new, attack_t *attack)
{
	new->name = attack->name;
	new->id = attack->id;
	new->type = attack->type;
	new->power = attack->power;
	new->precision = attack->precision;
	new->priority = attack->priority;
	new->next = NULL;
}

attack_t find_attack_by_id(attack_t *attack, int id)
{
	attack_t new;

	for (; attack && attack->next; attack = attack->next)
		if (attack && attack->id == id)
			dup_attack(&new, attack);
	return (new);
}
