/*
** EPITECH PROJECT, 2018
** display_pkmn
** File description:
** display pokemon
*/

#include "declaration.h"

void create_text_inv(sfFont *font, sfVector2f pos, char *sentence,
sfRenderWindow *window)
{
	int size = 15;
	sfText *text = sfText_create();

	sfText_setString(text, sentence);
	sfText_setPosition(text, pos);
	sfText_setCharacterSize(text, size);
	sfText_setFont(text, font);
	sfText_setColor(text, sfWhite);
	sfRenderWindow_drawText(window, text, NULL);
	sfText_destroy(text);
}

void create_rect_shape(pokemon_t *poke, sfRenderWindow *window, int i)
{
	sfVector2f size = {poke->cur_health * 96 / poke->max_health, 6};
	sfRectangleShape *rect = sfRectangleShape_create();
	sfColor color;
	sfVector2f pos = {330 + 450 * (i % 2), 194 + 150 * (i / 2)};

	if (poke->cur_health >= poke->max_health)
		size.x = 96;
	if (poke->cur_health <= (poke->max_health / 4))
		color = sfRed;
	else if (poke->cur_health <= (poke->max_health / 2))
		color = sfYellow;
	else
		color = sfGreen;
	sfRectangleShape_setPosition(rect, pos);
	sfRectangleShape_setSize(rect, size);
	sfRectangleShape_setFillColor(rect, color);
	sfRenderWindow_drawRectangleShape(window, rect, NULL);
	sfRectangleShape_destroy(rect);
}

void display_name_lvl_inven(game_t *game, int i)
{
	char *lvl;

	lvl = epi_itoa(game->player->pokemons[i]->lvl);
	create_text_inv(game->texture->font,
	create_vector2f(270 + 450 * (i % 2), 144 + 150 * (i / 2)),
	game->player->pokemons[i]->name, game->win);
	create_text_inv(game->texture->font,
	create_vector2f(252 + 450 * (i % 2),
	187 + 150 * (i / 2)), lvl, game->win);
	free(lvl);
}

void display_pkmn(game_t *game, sfRenderWindow *window, int x)
{
	sfSprite *sprite;

	for (int i = 0; i < 6; i++) {
		if (game->player->pokemons[i] != NULL) {
			display_name_lvl_inven(game, i);
			sprite = create_sprite(
			game->texture->pokemons[game->player->pokemons[i]->id],
			create_vector2f(202 + 450 * (i % 2),
			100 + 150 * (i / 2)),
			create_int_rect(0, 64 * x, 64, 64));
			sfRenderWindow_drawSprite(window, sprite, NULL);
			sfSprite_destroy(sprite);
			create_rect_shape(game->player->pokemons[i],
			window, i);
		}
	}
}

void display_pokemon(game_t *game, sfRenderWindow *window,
sfClock *c)
{
	static int x = 0;
	sfInt64 time = sfClock_getElapsedTime(c).microseconds;

	if (time >= 100000) {
		if (x == 0)
			x = 1;
		else
			x = 0;
		sfClock_restart(c);
	}
	display_pkmn(game, window, x);
}
