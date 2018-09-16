/*
** EPITECH PROJECT, 2018
** bag text
** File description:
** bag text
*/

#include "declaration.h"

void create_text_bag(sfFont *font, sfVector2f pos, char *sentence,
sfRenderWindow *window)
{
	int size = 20;
	sfText *text = sfText_create();

	sfText_setString(text, sentence);
	sfText_setPosition(text, pos);
	sfText_setCharacterSize(text, size);
	sfText_setFont(text, font);
	sfText_setColor(text, sfBlack);
	sfRenderWindow_drawText(window, text, NULL);
	sfText_destroy(text);
}

void display_heal_nb(game_t *game)
{
	char **nb = malloc(sizeof(char *) * 5);

	if (nb == NULL)
		return;
	nb[0] = epi_itoa(game->bag->default_potions);
	nb[1] = epi_itoa(game->bag->super_potions);
	nb[2] = epi_itoa(game->bag->hyper_potions);
	nb[3] = epi_itoa(game->bag->total_heal_potions);
	nb[4] = epi_itoa(game->bag->total_heal);
	for (int x = 0; x < 5; x++) {
		create_text_bag(game->texture->font,
		create_vector2f(870, 80 + 50 * x), nb[x], game->win);
		free(nb[x]);
	}
	free(nb);
}

void display_balls_nb(game_t *game)
{
	char **nb = malloc(sizeof(char *) * 5);

	if (nb == NULL)
		return;
	nb[0] = epi_itoa(game->bag->pokeballs);
	nb[1] = epi_itoa(game->bag->superballs);
	nb[2] = epi_itoa(game->bag->hyperballs);
	nb[3] = epi_itoa(game->bag->masterballs);
	nb[4] = epi_itoa(game->bag->honorballs);
	for (int x = 0; x < 5; x++) {
		create_text_bag(game->texture->font,
		create_vector2f(870, 80 + 50 * x), nb[x], game->win);
		free(nb[x]);
	}
	free(nb);
}

void display_item_heal(sfTexture *texture, sfRenderWindow *window,
sfVector2i pos)
{
	sfSprite *sprite = NULL;

	if (pos.y == 5)
		sprite = create_sprite(texture, create_vector2f(820, 480),
		create_int_rect(0, 120 * 10, 120, 120));
	else
		sprite = create_sprite(texture, create_vector2f(820, 480),
		create_int_rect(0, 120 * (pos.y + 5), 120, 120));
	sfRenderWindow_drawSprite(window, sprite, NULL);
	sfSprite_destroy(sprite);
}

void display_item_ball(sfTexture *texture, sfRenderWindow *window,
sfVector2i pos)
{
	sfSprite *sprite = NULL;

	if (pos.y == 5)
		sprite = create_sprite(texture, create_vector2f(820, 480),
		create_int_rect(0, 120 * 10, 120, 120));
	else
		sprite = create_sprite(texture, create_vector2f(820, 480),
		create_int_rect(0, 120 * pos.y, 120, 120));
	sfRenderWindow_drawSprite(window, sprite, NULL);
	sfSprite_destroy(sprite);
}
