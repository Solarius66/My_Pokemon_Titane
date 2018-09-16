/*
** EPITECH PROJECT, 2018
** my_rPOKEMONg
** File description:
** matthieu's declaration.h
*/

#pragma once

#include "declaration.h"

void combat_loop(game_t *, player_t *, player_t *);
void destroy_all_textures(texture_t *);
void initialize_all_texture3(texture_t *);
void destruct_pokemon(pokemon_t *);
void bushes_gest(game_t *);
void raise_lvl(pokemon_t *);
void attack_ai(pokemon_t *);
void evolve(game_t *, player_t *);
void destruct_npc(player_t *npc);
void play_pause(game_t *);
int experience(pokemon_t *, pokemon_t *);
int change_scene(game_t *, int);
int error_graph(void);
int error_main(void);
int error_music(void);
int error_func(void);
int second_main(game_t *);
int collision(char *, int, int, int);
int collision_npc(game_t *);
int npc_interaction(game_t *);
int destroy_textures(sfTexture **);
int attack_dps(pokemon_t *, pokemon_t *);
int destroy_all_attack(attack_t *);
int speed_calculator(pokemon_t *, pokemon_t *);
int initialize_all_texture(texture_t *);
int destruct_pokemons(game_t *);
float get_stab(pokemon_t *p);
float is_effective(attack_t *, pokemon_type);
attack_t find_attack_by_id(attack_t *, int);
attack_t *create_all_attack(void);
sfTexture **my_create_array(int);
sfTexture **create_texture(char *, int, sfIntRect *);
pokemon_t *find_pokemon_by_id(pokemon_t *, int);
pokemon_t *pokemon_dup_by_id(int, int, pokemon_t *);
pokemon_t *find_pokemon_by_name(pokemon_t *, char *);
pokemon_t *create_all_pokemon(attack_t *);
player_t *create_npc(pokemon_t *);
