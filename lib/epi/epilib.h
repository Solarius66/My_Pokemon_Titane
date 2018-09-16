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
#include "epi_struct.h"
#define ___true___ 1
#define ___false___ 0

void epi_sort(char **tab);
void epi_add_chained(chained_t *, int);
void epi_add_dchained(chained_t *, int);
void epi_destruct_chained(chained_t *);
void epi_remove_chained(chained_t *, int);
int epi_count_words_words(char *, char *);
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
int epi_is_digit(char *);
int epi_reverse_str(char *);
int epi_replace_charac(char *, char, char);
int epi_nmatch(char const *, char const *);
int epi_printf(char *, ...);
int epi_printd(char **);
int epi_printnbr_base(long long, int);
int epi_putfloat(double);
int epi_putfloat_err(double);
int epi_clear_malloc(char *, int);
int epi_putnbr(int);
int epi_putnbr_err(int);
int epi_compare_str(char *, char *);
int epi_count_words(char *, char separator);
int epi_count_words_arg(char *, char separator);
int epi_dprintf(int, char *, ...);
int epi_free(void *);
int epi_free_many(void *, ...);
long long epi_putnbr_dec(char *, int);
long long epi_pow(int, int);
char *epi_fusion_str(char *, char *);
char *epi_fusion_str_many(char *, ...);
char *epi_putnbr_base(long long, int);
char *epi_itoa(int);
char *epi_dtoa(double);
char *epi_join(char **, char);
char *epi_join_words(char **, char *);
char *epi_malloc(int);
char *epi_malloc_spe(int, char);
char *epi_remalloc(char *, int);
char *epi_stradd(char **, char);
char *epi_get_word(char *, char *, char *);
char *epi_lower_str(char *);
char *epi_remove_charac(char **, char);
char *epi_putnbr_base_maj(long long, int);
char *epi_base_to_base(char *, int, int, int);
char *epi_putf(char *, ...);
char *epi_vprintf(char *, va_list);
char **epi_split(char *, char);
char **epi_split_light(char *, char, int);
char **epi_split_arg(char *, char);
char **epi_split_nb(char *, int, char *);
char **epi_split_words(char *, char *);
char **epi_split_facade(char *, char *, int *);
char **epi_split_many(char *, char *);
char **epi_split_many_arg(char *, char *);
char **epi_get_words(char *, char, int always_zero);
char **epi_dre_malloc(char **);
char **epi_dadd(char **, char *);
char **epi_dadd_start(char **, char *);
char **epi_remove_line(char ***, char *);
char **epi_remove_line_nb(char ***, int);
chained_t *epi_create_chained(int);
chained_t *epi_create_dchained(int);
object_t new_obj(void *, char *);
