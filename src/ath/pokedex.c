/*
** EPITECH PROJECT, 2018
** pokedex
** File description:
** pokedex
*/

#include "declaration.h"

void create_text_dex(sfFont *font,
sfVector2f pos, char *line, sfRenderWindow *win)
{
	int size = 30;
	sfText *text = sfText_create();

	sfText_setString(text, line);
	sfText_setPosition(text, pos);
	sfText_setCharacterSize(text, size);
	sfText_setFont(text, font);
	sfText_setColor(text, sfBlack);
	sfRenderWindow_drawText(win, text, NULL);
	sfText_destroy(text);
}

void display_pokedex3(game_t *game, int id, int i)
{
	pokemon_t *pkmn = find_pokemon_by_id(game->pokemons, id);
	sfSprite *sprite;

	if (pkmn->is_discovered == true) {
		create_rect(game->texture->pokeball,
		create_vector2f(495, 318 + 110 * i),
		create_vector2f(90, 90), game->win);
		create_text_dex(game->texture->font,
		create_vector2f(605, 320 + 110 * i), pkmn->name, game->win);
		if (i == 0) {
			sprite = create_sprite(game->texture->pokemons[id],
			create_vector2f(90, 200),
			create_int_rect(0, 128, 64, 64));
			sfSprite_setScale(sprite, create_vector2f(5, 5));
			sfRenderWindow_drawSprite(game->win, sprite, NULL);
			sfSprite_destroy(sprite);
		}
	} else
		create_text_dex(game->texture->font,
		create_vector2f(605, 320 + 110 * i), "???", game->win);
}

void display_pokedex2(game_t *game, int x, char *id)
{
	int id_nb;

	for (int i = -1; i <= 1; i++) {
		id_nb = x + i;
		if (id_nb <= 0)
			id_nb = id_nb + 151;
		if (id_nb > 151)
			id_nb = id_nb - 151;
		id = epi_itoa(id_nb);
		display_pokedex3(game, id_nb, i);
		create_text_dex(game->texture->font,
		create_vector2f(645, 370 + 110 * i), id, game->win);
		free(id);
	}
}

void display_pokedex(game_t *game, int x)
{
	char *id = NULL;

	create_rect(game->texture->dex_font, create_vector2f(0, 0),
	create_vector2f(960, 640), game->win);
	create_rect(game->texture->dex_line, create_vector2f(490, 203),
	create_vector2f(450, 100), game->win);
	create_rect(game->texture->dex_line, create_vector2f(490, 313),
	create_vector2f(450, 100), game->win);
	create_rect(game->texture->dex_line, create_vector2f(490, 423),
	create_vector2f(450, 100), game->win);
	display_pokedex2(game, x, id);
}

void pokedex_main(game_t *game)
{
	int x = 1;
	sfClock *clock = sfClock_create();

	while (sfRenderWindow_isOpen(game->win)) {
		sfRenderWindow_clear(game->win, sfBlack);
		display_pokedex(game, x);
		sfRenderWindow_display(game->win);
		event_close(game->win);
		x = pokedex_move(x, clock);
		if (press_a())
			break;
	}
	sfClock_destroy(clock);
}
