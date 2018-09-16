/*
** EPITECH PROJECT, 2018
** my_rPOKEMONg
** File description:
** let's start with a main function
*/

#include "declaration.h"

void events(game_t *game, sfEvent *event)
{
	if (event->type == sfEvtClosed)
		win_close(game->win);
}

void delete_all(game_t *game)
{
	destroy_all_textures(game->texture);
	free(game->texture);
	destroy_game(game);
}

void display_starting(sfRenderWindow *window)
{
	sfTexture *logo = NULL;

	logo = sfTexture_createFromFile("assets/textures/logo.png", NULL);
	sfRenderWindow_clear(window, sfBlack);
	create_rect(logo, create_vector2f(0, 0), create_vector2f(960, 640),
	window);
	sfRenderWindow_display(window);
	sfTexture_destroy(logo);
}

void init_random(void)
{
	int seed;

	read(open("/dev/urandom", O_RDONLY), &seed, sizeof seed);
	srand(seed);
}

int main(void)
{
	game_t *game = initialize_game();

	if ((game->texture = malloc(sizeof(texture_t))) == NULL)
		return (84);
	init_random();
	display_starting(game->win);
	sfRenderWindow_display(game->win);
	game->attacks = create_all_attack();
	game->pokemons = create_all_pokemon(game->attacks);
	initialize_all_texture(game->texture);
	game->npc = create_npc(game->pokemons);
	play_pause(game);
	load_scene_main_menu(game);
	second_main(game);
	destruct_pokemons(game);
	destruct_npc(game->npc);
	destroy_all_attack(game->attacks);
	delete_all(game);
	return (0);
}
