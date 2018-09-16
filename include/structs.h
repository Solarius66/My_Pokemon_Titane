/*
** EPITECH PROJECT, 2018
** STRUCTS.H
** File description:
** Contains all used structs for my_rpg
*/

#pragma once

#include "declaration.h"

typedef struct sprite_s {
	sfSprite *renderer;
	sfTexture *texture;
	sfIntRect *rect;
} sprite_t;

typedef struct button_s {
	sfRectangleShape *shape;
	sfFloatRect *rect;
	sfText *text;
	sfTexture *texture;
	btn_state state;
} button_t;

typedef struct attack_s {
	char *name;
	int id;
	pokemon_type type;
	status status;
	int power;
	int precision;
	short priority;
	struct attack_s *next;
} attack_t;

typedef struct pokemon_s {
	int id;
	int id_evolve;
	int lvl_evolve;
	pokemon_type type1;
	pokemon_type type2;
	status status;
	char *name;
	int lvl;
	int xp;
	int cur_health;
	int max_health;
	int damage;
	int defense;
	int special_damage;
	int special_defense;
	int attack_speed;
	attack_t attack[4];
	attack_t attack_chosen;
	sfTexture **texture;
	bool is_discovered;
	struct pokemon_s *next;
} pokemon_t;

typedef struct player_s {
	char *name; // NULL
	int playtime_hours; // 0
	int playtime_minutes; // 0
	int actual;
	pokemon_t **pokemons; // size 6, with all NULL
	int badges; // 0
	int money; // 0
	int look_tile; // 2
	player_state state; // DEFAULT ENUM
	sfTexture **texture;
	bool gender;
	sfClock *move_c;
	sfClock *walk_c;
	sfVector2f position;
	int id; //reserved for NPC
	char *map_name;
	int skin_id;
	char *catchphrase;
	struct player_s *next;
} player_t;

typedef struct npc_s {
	char *name;
	char *source;
	bool has_been_defeated;
	sfVector2f position;
	struct npc_s *next;
} npc_t;

typedef struct interface_s {
	int no_warning;
} interface_t;

typedef struct scene_s {
	game_scenes type;
	char *name;
	char *map_file;
	int map_size;
	char **layers;
	npc_t *npcs;
	interface_t *interface;
	sfTexture *layer_ground;
	sfTexture *layer_col;
	sfTexture *layer_top;
	sfVector2i north;
	sfVector2i south;
	sfVector2i west;
	sfVector2i east;
	char *north_dest;
	char *south_dest;
	char *west_dest;
	char *east_dest;
	int *trainers;
	int median_level;
	int *pokemons;
	int *signs;
	int *homes;
	char *scene_type;
	int scene_index;
	sfVector2f arena_pos;
	sfVector2f center_pos;
	sfVector2f shop_pos;
} scene_t;

typedef struct musics_s {
	sfMusic *intro;
	sfMusic *cinematic;
	sfMusic *start;
	sfMusic *city;
	sfMusic *road;
	sfMusic *cave;
	sfMusic *snow;
	sfMusic *ligue;
	sfMusic *victory;
	sfMusic *end;
	sfMusic *volcano;
	sfMusic *fight_salvage;
	sfMusic *fight_trainer;
	sfMusic *current;
	bool isPaused;
	bool isPlaying;
	bool isStopped;
} musics_t;

typedef struct texture_s {
	sfTexture **man;
	sfTexture **woman;
	sfTexture ***npc;
	sfTexture *trainer_card;
	sfTexture *font_inv;
	sfTexture *pause_inv;
	sfTexture ***icons_inv;
	sfTexture **exit;
	sfTexture **poke_inv;
	sfTexture **status;
	sfTexture **badges;
	sfTexture **pokemons;
	sfFont *font;
	sfTexture *controls;
	sfTexture *start_back;
	sfTexture *start_top;
	sfTexture *start_move1;
	sfTexture *start_move2;
	sfTexture *dex_font;
	sfTexture *dex_line;
	sfTexture *pokeball;
	sfTexture *bag;
	sfTexture *items;
	sfTexture *fight_b;
	sfTexture *ball_till;
	sfTexture *start_b;
	sfTexture *trainer_big;
	sfTexture *jerem;
} texture_t;

typedef struct settings_s {
	int current_volume; // 50
	sfColor current_color; // red
} settings_t;

typedef struct progress_s {
	int current_progress; // 0
	scene_t *current_map; // NULL
	sfVector2f current_pos; // { 0; 0 }
	int discovered_pokemons_count; // 0
	bool *discovered_pokemons; // 0 or false is associated (!)
} progress_t;

typedef struct pc_s {
	pokemon_t **storage; // 256; null
} pc_t;

typedef struct bag_s {
	int default_potions; // 0
	int super_potions; // 0
	int hyper_potions; // 0
	int total_heal_potions; // 0
	int total_heal; //0
	int pokeballs; // 0
	int superballs; // 0
	int hyperballs; // 0
	int masterballs; // 0
	int honorballs; //0
} bag_t;

typedef struct scenes_s {
	scene_t **zones;
	scene_t **roads;
	scene_t **cities;
} scenes_t;

typedef struct game_s {
	sfRenderWindow *win;
	settings_t *settings;
	progress_t *progress;
	bag_t *bag;
	pc_t *pc;
	player_t *player;
	player_t *npc;
	scenes_t *scenes;
	scene_t *cur_scene;
	pokemon_t *pokemons;
	attack_t *attacks;
	musics_t *musics;
	texture_t *texture;
	sfColor outline;
} game_t;

typedef struct intro_s {
	sfTexture *bike;
	sfTexture *para1;
	sfTexture *para2;
	sfTexture *para3;
	sfTexture *para4;
	sfTexture *mew;
	sfClock *clock;
} intro_t;
