/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "declaration.h"

void define_badges_displayed(sfTexture **texture,
sfRenderWindow *window, int x)
{
	sfVector2f counter[5] = {{646, 232}, {542, 309}, {752, 309},
		{595, 413}, {701, 413}};
	sfIntRect rect;
	sfSprite *sprite;

	for (int i = 1; i <= x; i++) {
		rect = create_int_rect(0, 0, 100, 100);
		sprite = create_sprite(texture[i - 1], counter[i - 1], rect);
		sfRenderWindow_drawSprite(window, sprite, NULL);
		sfSprite_destroy(sprite);
	}
}

void display_element_card(game_t *game)
{
	char *money = epi_itoa(game->player->money);
	char *hours = epi_itoa(game->player->playtime_hours);
	char *minutes = epi_itoa(game->player->playtime_minutes);
	char *discovered = epi_itoa(game->progress->discovered_pokemons_count);

	create_text(game->texture->font, create_vector2f(300, 130),
	game->player->name, game->win);
	create_text(game->texture->font, create_vector2f(300, 265),
	money, game->win);
	create_text(game->texture->font, create_vector2f(430, 350),
	discovered, game->win);
	create_text(game->texture->font, create_vector2f(350, 435),
	hours, game->win);
	create_text(game->texture->font, create_vector2f(450, 435),
	minutes, game->win);
	free(money);
	free(hours);
	free(minutes);
	free(discovered);
}

void player_card(game_t *game)
{
	sfClock *clock = sfClock_create();

	while (sfRenderWindow_isOpen(game->win)) {
		sfRenderWindow_clear(game->win, sfBlack);
		create_rect(game->texture->trainer_card, create_vector2f(0, 0),
		create_vector2f(960, 640), game->win);
		define_badges_displayed(game->texture->badges,
		game->win, game->player->badges);
		display_element_card(game);
		sfRenderWindow_display(game->win);
		while (sfClock_getElapsedTime(clock).microseconds <= 100000);
		sfClock_restart(clock);
		event_close(game->win);
		if (press_a())
			break;
	}
	sfClock_destroy(clock);
}
