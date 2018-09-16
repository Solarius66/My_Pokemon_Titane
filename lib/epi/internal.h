/*
** EPITECH PROJECT, 2018
** lib 2.0
** File description:
** declaration file
*/

#pragma once

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>

#define ___true___ 1
#define ___false___ 0

void hash_gest(va_list list, char *, int *);
void epi_putstr_o(char *);
void switch_manage(va_list, char);
long long epi_putnbr_dec(char *, int);
long long epi_pow(int, int);
int epi_atoi(char *);
int epi_putchar(unsigned char);
int epi_putstr(char *);
int epi_puterr(char *);
int epi_strlen(char *);
int epi_dstrlen(char **);
int epi_start_with(char *, char *);
int epi_end_with(char *, char *, int);
int epi_ddestroy(char **);
int epi_printnbr_base_maj(long long, int);
int epi_reverse_str(char *);
int epi_replace_charac(char *, char, char);
int create_chained(void *, int);
int destroy_chained(void *);
int nmatch(char const *, char const *);
int epi_printf(char *, ...);
int epi_printd(char **);
int epi_printnbr_base(long long, int);
int epi_putfloat(double);
int epi_putfloat_err(double);
int length_nb(int);
int clear_malloc(char *, int);
int count_words(char *);
int epi_putnbr(int);
int epi_putnbr_err(int);
int epi_compare_str(char *, char *);
int epi_count_words(char *, char separator);
int epi_count_words_arg(char *, char separator);
int epi_dprintf(int, char *, ...);
int epi_free(void *);
char *fusion_str(char *, char *);
char *fusion_str_many(char *, ...);
char *epi_putnbr_base(long long, int);
char *epi_itoa(int);
char *epi_dtoa(double);
char *epi_join(char **, char);
char *epi_malloc(int);
char *epi_malloc_spe(int, char);
char *epi_remalloc(char *, int);
char *epi_stradd(char **, char);
//the return string is the one to free if possible (epi_remove_charac)
char *epi_remove_charac(char **, char);
char *epi_putnbr_base_maj(long long, int);
char *epi_putf(char *, ...);
char *epi_hash_gest(va_list, char *, int *);
char *epi_getstr_o(char *);
char *epi_getchar_o(char);
char *epi_vprintf(char *, va_list);
char **epi_split(char *, char);
char **epi_split_arg(char *, char);
char **epi_split_nb(char *, int, char *);
char **epi_split_many(char *, char *);
char **epi_split_many_arg(char *, char *);
char **epi_get_words(char *, char, int always_zero);
char **epi_dre_malloc(char **);
char **epi_dadd(char **, char *);
char **epi_dadd_start(char **, char *);
char **epi_remove_line(char ***, char *);
char **epi_remove_line_nb(char ***, int);
