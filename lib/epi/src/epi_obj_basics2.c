/*
** EPITECH PROJECT, 2018
** lib 3.0
** File description:
** some PO in a non PO language :D
*/

#include "../internal.h"

/*
**instantiate a new object 2
*/
void new_obj2(object_t obj)
{
	obj->print = &obj_print;
	obj->to_string = &obj_to_string;
	obj->to_int = &obj_to_int;
	obj->to_origin = &obj_to_origin;
	obj->supported_types = &obj_supported_types;
	obj->destroy = &obj_destroy;
	obj->get_type = &obj_get_type;
}

/*
**Credits of the library (yup it's in the object lib whatcha gonna do?)
*/
void credit(void)
{
	epi_printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
	"This library is the epilib (and epilib_obj)",
	"It has been made by Az-Kalaak during 2017-2018",
	"Using the following functions:",
	"\tmalloc, free, write.",
	"BY USING THIS LIBRARY, YOU AGREE IN THE FOLLOWING THINGS:",
	"\tDon't use this library if you are not allowed to",
	"\tDo not claim that this code is yours.",
	"\tDo not modify this library;",
	"\tReport any bugs encountered (if possible)",
	"CONTACT:"
	"\tazkalaak@tutanota.com");
}
