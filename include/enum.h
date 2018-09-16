/*
** EPITECH PROJECT, 2018
** my_RpokemonG
** File description:
** LES ENUM
*/

#include "declaration.h"

typedef enum boolean {
	false, true
} bool;
//0: rien; 1: multi(5); 2: 2a 5 tours; 3: recover /2 pv; 4: blesse lanceur
// si rate;
// 5: blesse lanceur;
//        0,      1       2     3     4     5      6      7      8    9
//        10     11     12     13     14      15*/
typedef enum pokemon_type_e {
	NO_TYPE, NORMAL, FIRE, PLANT, ELEC, ICE, WATER, POISON, PSY, ROCK,
	PHANTOM, FLY, FIGHT, DRAGON, INSECT, GROUND
} pokemon_type;
typedef enum player_state_e {
	IDLING, WALKING, RUNNING
} player_state;
typedef enum pkm_status {
	OKAY, POISONNED, BURNED, SLEEPING, PARALYSED, CONFUSED, FROZEN
} status;
typedef enum game_scenes_e {
	MENU, BATTLE, WAY, BOAT,
	ARENA_1, ARENA_2, ARENA_3, ARENA_4, ARENA_5,
	LIGUE_1, LIGUE_2, LIGUE_3, LIGUE_4, LIGUE_5,
	ROAD_1, ROAD_2, ROAD_3, ROAD_4, ROAD_5, ROAD_6, ROAD_7, ROAD_8,
	CITY_1, CITY_2, CITY_3, CITY_4, CITY_5, CITY_6, CITY_7, CITY_8
} game_scenes;

typedef enum btn_state_e {
	IDLE, HOVERED, CLICKED
} btn_state;
