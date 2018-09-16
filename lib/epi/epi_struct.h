/*
** EPITECH PROJECT, 2018
**
** File description:
** creating texture
*/

#pragma once

typedef struct chained_s chained_t;
typedef struct object_s *object_t;

struct object_s {
	void *inside;
	char *type;
	char *original_type;
	void *(*get_value)(object_t);
	int (*len)(object_t);
	void (*print)(object_t);
	void (*to_string)(object_t);
	void (*to_int)(object_t);
	void (*to_origin)(object_t);
	void (*supported_types)(void);
	void (*credit)(void);
	void (*destroy)(object_t);
	char *(*get_type)(object_t);
};

struct chained_s {
	void *in;
	int id;
	chained_t *next;
	chained_t *prev;
};
