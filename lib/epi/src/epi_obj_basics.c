/*
** EPITECH PROJECT, 2018
** lib 3.0
** File description:
** some PO in a non PO language :D
*/

#include "../internal.h"

/*
**indicate the supported types
*/
void obj_supported_types(void)
{
	epi_printf("the supported types are the following: %s",
	"string (char *)\n int (integer), array(char *)\n");
	epi_printf("I'm NOT RESPONSIBLE if you use an unknown type %s",
	"that causes the functions to crash.\n");
	epi_printf("Matthieu SAUER, Creator of this library.\n");
}

/*
**returns the length of an object
*/
int obj_len(object_t obj)
{
	long long tmp = (long long)obj->inside;

	if (epi_compare_str("string", obj->type))
		return (epi_strlen((char *)obj->inside));
	if (epi_compare_str("int", obj->type))
		return (internal_length_nb((int)tmp));
	if (epi_compare_str("array", obj->type))
		return (epi_dstrlen((char **)obj->inside));
	epi_printf("\n%s is not an actually supported type\n", obj->type);
	return (0);
}

/*
**print the content of the object
*/
void obj_print(object_t obj)
{
	long long *tmp = obj->inside;
	if (epi_compare_str("string", obj->type))
		epi_putstr((char *)obj->inside);
	if (epi_compare_str("int", obj->type))
		epi_printnbr_base(tmp[0], 10);
	if (epi_compare_str("array", obj->type))
		epi_printd((char **)obj->inside);
}

/*
**returns the value of an object
*/
void *obj_get_value(object_t obj)
{
	return (obj->inside);
}

/*
**instantiate a new object
*/
object_t new_obj(void *inside, char *initial_type)
{
	object_t obj = malloc(sizeof(struct object_s));
	long long *tmp;

	if (epi_compare_str(initial_type, "string"))
		obj->inside = epi_remalloc((char *)inside, -1);
	else if (epi_compare_str(initial_type, "array"))
		obj->inside = epi_dre_malloc((char **)inside);
	else {
		tmp = malloc(sizeof(long long));
		tmp[0] = (long long)inside;
		obj->inside = tmp;
	}
	obj->type = initial_type;
	obj->original_type = initial_type;
	obj->credit = &credit;
	obj->get_value = &obj_get_value;
	obj->len = &obj_len;
	new_obj2(obj);
	return (obj);
}
