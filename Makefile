##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

NAME	= my_rpg

CC	= gcc

RM	= rm -f

SRC_DIR	= ./src

SCENES_DIR	= ./src/scenes

INI_DIR	= ./src/initializers

DES_DIR	= ./src/destructors

FUNC_DIR = ./functions

GLIB = ./gumiho_lib

SRCS	=	$(SRC_DIR)/main.c\
		$(SRC_DIR)/main_2.c\
		$(SRC_DIR)/usefull_fct.c\
		$(SRC_DIR)/usefull_fct2.c\
		$(SRC_DIR)/controllerinterract.c\
		$(SRC_DIR)/controllermove.c\
		$(SRC_DIR)/error_gest/error_function.c\
		$(SRC_DIR)/error_gest/error_main.c\
		$(SRC_DIR)/error_gest/error_map.c\
		$(SRC_DIR)/error_gest/error_music.c\
		$(SRC_DIR)/error_gest/error_texture.c\
		$(SRC_DIR)/anim/create_texture.c\
		$(SRC_DIR)/anim/destroy_texture.c\
		$(SRC_DIR)/window_manager.c\
		$(SRC_DIR)/text_displayer.c\
		$(SRC_DIR)/find_by.c\
		$(SRC_DIR)/anim/collision.c\
		$(SRC_DIR)/combat_motor/experience_gest.c\
		$(SRC_DIR)/combat_motor/combat_loop.c\
		$(SRC_DIR)/combat_motor/combat_display.c\
		$(SRC_DIR)/combat_motor/combat_main.c\
		$(SRC_DIR)/combat_motor/is_effective.c\
		$(SRC_DIR)/combat_motor/ath_combat.c\
		$(SRC_DIR)/combat_motor/text_manager.c\
		$(SRC_DIR)/combat_motor/combat_end.c\
		$(SRC_DIR)/constructor/attack_constructor.c\
		$(SRC_DIR)/constructor/npc_constructor.c\
		$(SCENES_DIR)/mains/scene_main_menu.c\
		$(SCENES_DIR)/mains/scene_intro.c\
		$(SCENES_DIR)/mains/scene_intro2.c\
		$(SCENES_DIR)/mains/end.c\
		$(SCENES_DIR)/mains/scene_main_save.c\
		$(SCENES_DIR)/mains/scene_main_save2.c\
		$(SCENES_DIR)/mains/scene_main_new.c\
		$(SCENES_DIR)/mains/scene_main_new2.c\
		$(SCENES_DIR)/displayer/create_map.c\
		$(SCENES_DIR)/displayer/move_player_management.c\
		$(SCENES_DIR)/displayer/player_position.c\
		$(SCENES_DIR)/displayer/pass_entrance.c\
		$(SCENES_DIR)/displayer/manage_build.c\
		$(SCENES_DIR)/displayer/shop_management.c\
		$(SCENES_DIR)/displayer/display_npc.c\
		$(SRC_DIR)/update/npc_action.c\
		$(SRC_DIR)/update/play_pause.c\
		$(SRC_DIR)/update/encounter.c\
		$(SRC_DIR)/ath/pause.c\
		$(SRC_DIR)/ath/display_pkmn.c\
		$(SRC_DIR)/ath/poke_inven.c\
		$(SRC_DIR)/ath/player_card.c\
		$(SRC_DIR)/ath/pokedex.c\
		$(SRC_DIR)/ath/pokedex_extended.c\
		$(SRC_DIR)/ath/options.c\
		$(SRC_DIR)/ath/options2.c\
		$(SRC_DIR)/ath/bag.c\
		$(SRC_DIR)/ath/bag_text.c\
		$(SRC_DIR)/constructor/pokemon_dup.c\
		$(SRC_DIR)/constructor/pokemon_constructor.c\
		$(SRC_DIR)/anim/my_create_array.c\
		$(SRC_DIR)/scene_manager.c\
		$(SRC_DIR)/config_static_data.c\
		$(SRC_DIR)/music_player.c\
		$(SRC_DIR)/check_buildings.c\
		$(INI_DIR)/initialize_textures.c\
		$(INI_DIR)/initialize_textures2.c\
		$(INI_DIR)/initialize_game.c\
		$(INI_DIR)/initialize_game_ext.c\
		$(INI_DIR)/initialize_layers.c\
		$(INI_DIR)/initialize_scenes.c\
		$(INI_DIR)/initialize_scene_buildings.c\
		$(INI_DIR)/initialize_scene_containt.c\
		$(INI_DIR)/initialize_scene_containt_ext.c\
		$(INI_DIR)/initialize_scene_containt_ext_ext.c\
		$(DES_DIR)/destruct_game.c\
		$(DES_DIR)/destruct_game_2.c\
		$(DES_DIR)/destruct_attacks.c\
		$(DES_DIR)/destruct_pokemons.c\
		$(DES_DIR)/destruct_npc.c\
		$(GLIB)/str_disp.c\
		$(GLIB)/str_len.c\
		$(GLIB)/get_next_line.c\
		$(GLIB)/str_iseq.c\
		$(GLIB)/str_parse.c\
		$(GLIB)/stra_free.c\
		$(GLIB)/stra_len.c\
		$(GLIB)/inta_malloc.c\
		$(GLIB)/str_cpy.c\
		$(GLIB)/str_startwith.c\
		$(SRC_DIR)/save/save.c\
		$(SRC_DIR)/save/save_pc.c\
		$(SRC_DIR)/save/save_bag.c\
		$(SRC_DIR)/save/save_player.c\
		$(SRC_DIR)/save/save_settings.c\
		$(SRC_DIR)/save/save_pokedex.c\
		$(SRC_DIR)/load_save/load_player.c\
		$(SRC_DIR)/load_save/load_save.c\
		$(SRC_DIR)/load_save/load_bag.c\
		$(SRC_DIR)/load_save/load_pc.c\
		$(SRC_DIR)/load_save/load_settings.c\
		$(SRC_DIR)/load_save/load_pokedex.c\
		$(SRC_DIR)/load_save/load_scene.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include -I ./gumiho_lib
CFLAGS += -W -Wall -Wextra -pedantic -Werror -g3 -fdiagnostics-color=always

LDFLAGS	= -L./lib/epi/ -lepi -l c_graph_prog

all: namebis

test_run:
	(cd tests && make)
	./GLaDOS

library:
	(cd lib/epi/ && make)

lib_fclean:
	(cd lib/epi/ && make fclean)

lib_clean:
	(cd lib/epi/ && make clean)

namebis: library $(OBJS) $(NAME)

$(NAME):
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean: lib_clean
	$(RM) $(OBJS)

fclean: clean lib_fclean
	$(RM) $(NAME)
	(cd tests/ && make fclean)

re: fclean all
