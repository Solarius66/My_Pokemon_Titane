/*
** EPITECH PROJECT, 2018
** my_rPOKEMONg
** File description:
** michael's declaration.h
*/

#ifndef MICHAEL_H
#define MICHAEL_H
#include "declaration.h"

void save_pokemons(int fd, pokemon_t **pokemons);
void save_player(int fd, player_t *player, game_t *);
void save_pc(int fd, pc_t *pc);
void save_color(int fd, sfColor c);
void save_settings(int fd, settings_t *settings);
void save_progress(int fd, progress_t *progress);
void save_bag(int fd, bag_t *bag);
void save_pokedex(int fd, pokemon_t *pokemons);
void save(game_t *game);
void clean_get_next_line(int fd);
int load_int(int fd);
void load_pokemons(int fd, pokemon_t **pokemons, pokemon_t *all_pokemons);
void load_player(int fd, game_t *);
void load_pc(int fd, pc_t *pc, pokemon_t *all_pokemons);
void load_color(int fd, game_t *game);
void load_settings(int fd, settings_t *settings);
void load_progress(int fd, game_t *game);
void load_bag(int fd, bag_t *bag);
void load_pokedex(int fd, pokemon_t *pokemons);
void load_save(game_t *game, int fd);
#endif /*MICHAEL_H*/
