/*
** EPITECH PROJECT, 2018
** my_rPOKEMONg
** File description:
** alexandre's declaration.h
*/

#include "declaration.h"

#ifndef ALEX_H
#define ALEX_H

sfVector2f create_vector2f(int, int);
sfIntRect create_int_rect(int, int, int, int);
void create_text(sfFont *, sfVector2f, char *, sfRenderWindow *);
void create_text_inv(sfFont *, sfVector2f, char *, sfRenderWindow *);
void display_pokemon(game_t *, sfRenderWindow *, sfClock *);
void pause_menu(game_t *);
sfSprite *create_sprite(sfTexture *, sfVector2f, sfIntRect);
sfIntRect create_int_rect(int, int, int, int);
sfIntRect *create_int_rect_star(int, int, int, int);
void create_rect(sfTexture *, sfVector2f, sfVector2f, sfRenderWindow *);
void create_color_rect(sfColor, sfVector2f, sfVector2f, sfRenderWindow *);
void event_close(sfRenderWindow *);
void poke_inventory(game_t *);
void player_card(game_t *);
void pause_menu(game_t *);
void pokedex_main(game_t *);
int pokedex_move(int, sfClock *);
void save_menu(game_t *);
void option_main(game_t *);
void create_text_dex(sfFont *, sfVector2f, char *, sfRenderWindow *);
void create_text_start(sfFont *, sfVector2f, char *, sfRenderWindow *);
void create_color_rect_in(sfColor, sfVector2f, sfVector2f, sfRenderWindow *);
sfBool press_x(void);
sfBool press_a(void);
sfBool press_b(game_t *);
sfBool press_y(void);
sfBool press_start(void);
sfBool press_select(void);
sfBool move_top(void);
sfBool move_bot(void);
sfBool move_right(void);
sfBool move_left(void);
void define_outline_color(game_t *, sfClock *);
void text_displayer(game_t *, char *, bool);
void bag_main(game_t *);
void create_text_bag(sfFont *, sfVector2f, char *, sfRenderWindow *);
void option_main(game_t *);
void display_item_heal(sfTexture *, sfRenderWindow *, sfVector2i);
void display_item_ball(sfTexture *, sfRenderWindow *, sfVector2i);
void move_player_management(game_t *);
void display_player(game_t *);
void map_displayer_main(game_t *, bool);
void display_heal_nb(game_t *);
void display_balls_nb(game_t *);
void display_intro(game_t *);
void intro_display(intro_t *, int, game_t *);
void display_mew_intro(sfTexture *, int, sfRenderWindow *);
void create_text_save(sfFont *, sfVector2f, char *, sfRenderWindow *);
int define_move_map(int, sfClock *, bool *);
void display_rect_text(game_t *, bool);
void display_save_loop(game_t *, int, int, sfClock *);
void display_save(game_t *, int, int);
int manage_event_save(int, sfClock *);
void define_save_load(game_t *, int, int);
void start_new_game(game_t *);
void define_gender_player(game_t *);
void choose_starter(game_t *);
void define_starter(game_t *, int, sfClock *);
int manage_tilt_new(int, sfClock*, int);
pokemon_t *pokemon_dup_by_id(int, int, pokemon_t *);
void define_name(game_t *);
int manage_x_new(int, sfClock *, int);
void create_text_pause(sfFont *, sfVector2f, char *, sfRenderWindow *);
void end_main(game_t *);
intro_t *create_intro_str(void);
void destroy_intro(intro_t *);
void intro_display(intro_t *, int, game_t *);
void combat_displayer(game_t *, player_t *, player_t *);
int display_ath_fight(game_t *, player_t *, player_t *);
void text_manager_fight(int, game_t *, player_t *, player_t *);
void win_fct(game_t *, player_t *, player_t *);
void combat_displayer2(game_t *, player_t *, player_t *);
void display_question_save(game_t *, int);
int define_x_save(int, sfClock *);
void poke_center_management(game_t *);
void win_management(int, game_t *, player_t *, player_t *);
void music_management_fight(game_t *, player_t *, bool);
void shop_management(game_t *);
void display_map_ath(game_t *);
void display_npcs(game_t *, player_t *);

#endif /*ALEX_H*/
