/*
** EPITECH PROJECT, 2018
** my_rPOKEMONg
** File description:
** yannick's declaration.h
*/

#pragma once

#include "declaration.h"
// WINDOW_MANAGER
sfRenderWindow *win_create(sfVideoMode mode, char *name);
int win_close(sfRenderWindow *win);
int win_destroy(sfRenderWindow *win);
// SRC/MAIN.C
void displayer(game_t *game);
void events(game_t *game, sfEvent *event);
void initialize_all(game_t *game);
void delete_all(game_t *game);
int main(void);
// SRC/MUSIC_PLAYER.C
void play_music(musics_t *muscis, sfMusic *music);
void switch_music(musics_t *music, scene_t *cur_scene);

// src/check_buildings.c
int check_buildings(game_t *game);

// src/initializers/initalize_game.c
int initialize_settings(game_t *game);
int initialize_progress(game_t *game);
int initialize_bag(game_t *game);
int initialize_game_extended(game_t *game);
game_t *initialize_game(void);

// src/initializers/initialize_game_ext.c
int initialize_player(game_t *game);
int initialize_music_extended(game_t *game);
int initialize_music(game_t *game);
int initialize_pc(game_t *game);
int initialize_window(game_t *game);

// src/initializers/initialize_layers.c
void fill_layer_ground(int fd, char **layers, int size);
void fill_layer_col(int fd, char **layers, int size);
void fill_layer_top(int fd, char **layers, int size);

// src/initializers/initialize_scene_buildings.c
int create_arena(int fd, scene_t *scene);
int create_center(int fd, scene_t *scene);
int create_shop(int fd, scene_t *scene);

// src/initializers/initialize_scene_containt.c
void fill_layers(int fd, char **layers, int size);
int create_textures(int fd, scene_t *scene);
int create_entries_extended(int fd, scene_t *scene);
int create_entries(int fd, scene_t *scene);
int initialize_scene(char *path, scene_t *scene);

// src/initializers/initialize_scene_containt_ext.c
int create_trainers(int fd, scene_t *scene);
int create_bushes(int fd, scene_t *scene);
int create_signs(int fd, scene_t *scene);
int create_objects(int fd, scene_t *scene);

// src/initializers/initialize_scene_containt_ext_ext.c
int create_default_scene_extended(scene_t *scene);
int create_default_scene(scene_t *scene);
int create_scene_properties(scene_t *scene);
int create_entrances(int fd, scene_t *scene);

// src/initialiers/initialize_scenes.c
int initialize_zones(game_t *game);
int initialize_cities(game_t *game);
int initialize_roads(game_t *game);
int initialize_scenes(game_t *game);

// src/initialize_textures2.c
void initialize_all_texture3(texture_t *text);

// src/initialize_textures.c
void destroy_all_textures2(texture_t *text);
void destroy_all_textures(texture_t *text);
void initialize_all_texture2(texture_t *text);
int initialize_all_texture(texture_t *text);
int initialize_pkm_texture(pokemon_t *p);

// SRC/DESTROY_GAME.C
int destroy_settings(game_t *game);
int destroy_progress(game_t *game);
int destroy_bag(game_t *game);
int destroy_pc(game_t *game);
int destroy_game(game_t *game);
// SRC/DESTROY_GAME_2.C
int destroy_player(game_t *game);
int destroy_scenes(game_t *game);
int destroy_window(game_t *game);
int destroy_musics(game_t *game);
//CREATE ROAD AND SWITCH SCENE AND LOAD_MAP_FROM_PATH
int create_roads(game_t *);
void switch_scene(game_t *, scene_t *);
void load_map_from_path(scene_t *);
void load_each_layer(int stream, char **layers);
void load_scene_main_menu(game_t *);
void config_static_data(scene_t *, char *, game_scenes);
// MORE WARNINGS LOL
int create_default_scene(scene_t *);
int create_objects(int, scene_t *);
// SRC/SCENES/DISPLAYER/PLAYER_POSITION.C
void check_player_pos(game_t *game, sfVector2f *cur_pos);
// SRC/SCENES/DISPLAYER/PASS_ENTRANCE.C
void to_north_scene(game_t *game, sfVector2f *cp);
void to_south_scene(game_t *game, sfVector2f *cp);
void to_west_scene(game_t *game, sfVector2f *cp);
void to_east_scene(game_t *game, sfVector2f *cp);
