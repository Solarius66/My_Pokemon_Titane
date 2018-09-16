/*
** EPITECH PROJECT, 2017
** get_next_line
** File description:
** Returns a read line from a file descriptor MBND
*/

#include "gumiho_lib.h"

char *my_str_reallocf(char *str, int size)
{
	char *new_str = malloc(sizeof(char) * size + 1);
	int i = 0;

	if (new_str == NULL)
		return NULL;
	while (str[i] != '\0' && i != size) {
		new_str[i] = str[i];
		++i;
	}
	new_str[i] = '\0';
	free(str);
	return new_str;
}

void clear_buffer(char *buffer, int *buffer_cursor)
{
	int i = 0;

	*buffer_cursor = 0;
	while (i != READ_SIZE) {
		buffer[i] = '\0';
		++i;
	}
}

void fill_line(char *buffer, int *buffer_c, char *line, int *line_c)
{
	while (buffer[*buffer_c] != '\0' && buffer[*buffer_c] != '\n') {
		line[*line_c] = buffer[*buffer_c];
		++*line_c;
		++*buffer_c;
	}
	line[*line_c] = '\0';
	if (buffer[*buffer_c] != '\n')
		*buffer_c = READ_SIZE;
}

void *free_line(char *line)
{
	free(line);
	return NULL;
}

char *get_next_line(int fd)
{
	static char buffer[READ_SIZE + 1];
	static int buffer_cursor = 0;
	char *line = malloc(1);
	int line_cursor = 0;
	int line_size = READ_SIZE - buffer_cursor;

	if (fd == -1 || (line == NULL) || (line[0] = 0))
		return NULL;
	while (1) {
		if ((line = my_str_reallocf(line, line_size)) == NULL)
			return NULL;
		if (buffer_cursor != READ_SIZE)
			fill_line(buffer, &buffer_cursor, line, &line_cursor);
		if (buffer_cursor++ != READ_SIZE && buffer[0] != '\0')
			return line;
		line_size += READ_SIZE;
		clear_buffer(buffer, &buffer_cursor);
		if (read(fd, buffer, READ_SIZE) <= 0)
			return (line[0] ? line : free_line(line));
	}
}
