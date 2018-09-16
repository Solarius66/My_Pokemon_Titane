/*
** EPITECH PROJECT, 2018
** GUMIHO_LIB.H
** File description:
** Header file for gumiho_lib files
*/

#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define READ_SIZE 56

char *str_cpy(char const *str);
int str_disp(char *str, int output);
char *get_next_line(int fd);
int str_len(char *str);
int str_iseq(char *str, char *expr);
char **str_parse(char *line, char del);
int stra_free(char **stra);
int *inta_malloc(int size);
int stra_len(char **stra);
int str_startwith(char *str, char *expr);
