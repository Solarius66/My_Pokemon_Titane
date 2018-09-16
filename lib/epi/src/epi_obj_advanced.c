/*
** EPITECH PROJECT, 2018
** lib 3.0
** File description:
** more PO in a non PO language :D
*/

#include "../internal.h"

/*
**returns the type of an object
*/
char *obj_get_type(object_t obj)
{
	return (obj->type);
}

/*
**turns the object into an int
** /!\ not every objects can be turned into an int
*/
void obj_to_int(object_t obj)
{
	char *tmp;
	long long *temp;

	if (epi_compare_str("string", obj->type)) {
		tmp = (char *)obj->inside;
		obj->inside = malloc(sizeof(long long));
		temp = obj->inside;
		temp[0] = (long long)epi_atoi(tmp);
		obj->type = "int";
		epi_free(tmp);
	}
}

/*
**turns the object inside into string
** /!\ not every objects can be turned into a string
*/
void obj_to_string(object_t obj)
{
	long long *tmp = obj->inside;

	if (epi_compare_str("int", obj->type)) {
		obj->inside = epi_itoa((int)tmp[0]);
		epi_free(tmp);
		obj->type = "string";
	}
	if (epi_compare_str("array", obj->type))
		epi_printf("format array, use join() before converted.\n");
}

/*
**turns an object into it's original form
*/
void obj_to_origin(object_t obj)
{
	if (epi_compare_str("string", obj->original_type))
		obj->to_string(obj);
	if (epi_compare_str("int", obj->original_type))
		obj->to_int(obj);

}

/*
**destroy an object
*/
void obj_destroy(object_t obj)
{
	if (epi_compare_str("string", obj->type))
		epi_free(obj->inside);
	if (epi_compare_str("int", obj->type))
		epi_free(obj->inside);
	if (epi_compare_str("array", obj->type))
		epi_ddestroy((char **)obj->inside);
	epi_free(obj);
}
