/*
** EPITECH PROJECT, 2018
** my_rPOKEMONg
** File description:
** another main because it's too long
*/

#include "declaration.h"

void define_click_quit(game_t *game, sfVector2i mouse)
{
	if (mouse.x < 546 && mouse.x > 346 &&
		mouse.y < 312 && mouse.y > 212)
		load_scene_main_menu(game);
	if (mouse.x < 763 && mouse.x > 563 &&
		mouse.y < 412 && mouse.y > 316)
		sfRenderWindow_close(game->win);
}

void display_quit(game_t *game)
{
	sfVector2f size = {200, 100};
	sfVector2i mouse_pos;

	while (sfRenderWindow_isOpen(game->win)) {
		sfRenderWindow_clear(game->win, sfBlack);
		create_text(game->texture->font, create_vector2f(0, 0),
		"BCS I MUST :)", game->win);
		create_color_rect_in(sfBlue, size,
		create_vector2f(346, 212), game->win);
		create_color_rect_in(sfRed, size,
		create_vector2f(563, 316), game->win);
		create_text(game->texture->font, create_vector2f(346, 212),
		"2 MAISON", game->win);
		create_text(game->texture->font, create_vector2f(563, 316),
		"2 KUIT", game->win);
		sfRenderWindow_display(game->win);
		mouse_pos = sfMouse_getPositionRenderWindow(game->win);
		if (sfMouse_isButtonPressed(sfMouseLeft))
			define_click_quit(game, mouse_pos);
		event_close(game->win);
	}
}

void time_manager(game_t *game, sfClock *clock)
{
	if (sfClock_getElapsedTime(clock).microseconds > 60000000) {
		sfClock_restart(clock);
		game->player->playtime_minutes++;
	}
	if (game->player->playtime_minutes == 60) {
		game->player->playtime_hours++;
		game->player->playtime_minutes = 0;
	}
}

int second_main(game_t *game)
{
	sfClock *clock = sfClock_create();

	while (sfRenderWindow_isOpen(game->win)) {
		sfRenderWindow_clear(game->win, sfBlack);
		map_displayer_main(game, true);
		sfRenderWindow_display(game->win);
		npc_interaction(game);
		if (press_y() == sfTrue)
			pause_menu(game);
		if (sfKeyboard_isKeyPressed(sfKeyEscape))
			display_quit(game);
		event_close(game->win);
		time_manager(game, clock);
		if (game->player->pokemons[game->player->actual]->lvl == 20)
			break;
	}
	if (game->player && game->player->pokemons && game->player->pokemons[game->player->actual]
		&& game->player->pokemons[game->player->actual]->lvl >= 20)
		end_main(game);
	sfClock_destroy(clock);
	return (0);
}
