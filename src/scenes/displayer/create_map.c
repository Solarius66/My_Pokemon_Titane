/*
** EPITECH PROJECT, 2018
** map_displayer
** File description:
**
*/

#include "declaration.h"

int define_move_map(int move, sfClock *clock, bool *booleen)
{
	if (sfClock_getElapsedTime(clock).microseconds > 100000) {
		if (booleen[0] == true)
			move++;
		else if (booleen[0] == false)
			move--;
		if (move <= -1)
			booleen[0] = true;
		if (move >= 1)
			booleen[0] = false;
		sfClock_restart(clock);
	}
	if (!move_bot() && !move_top() && !move_left() && !move_right())
		move = 0;
	return (move);
}

int define_block_type(char c)
{
	int x = 32;

	while (x < c)
		x++;
	if (x > 126)
		return (0);
	x = x - 32;
	return (x);
}

sfSprite *create_tile(float x, float y, int spr_type, sfTexture *texture,
sfSprite *sprite)
{
	sfVector2f pos = {x * 32, y * 32};
	sfIntRect rect = create_int_rect(0, 32 * spr_type, 32, 32);

	sfSprite_setTexture(sprite, texture, sfTrue);
	sfSprite_setTextureRect(sprite, rect);
	sfSprite_setPosition(sprite, pos);

	return (sprite);
}

void create_map(char *map_string, sfRenderWindow *window,
sfTexture *texture, sfVector2f pos)
{
	int x = 0;
	int y = pos.y - 1;
	int spr_type;
	int i = 0;
	sfSprite *sprite = sfSprite_create();

	for (int j = 0; j < y; ++j, ++i)
		for (; map_string[i] && map_string[i] != '\n'; ++i);
	if (y <= 0) {
		y = 0;
		i = 0;
	}
	for (; map_string[i] != '\0'; ++i) {
		if (map_string[i] == '\n') {
			y++;
			x = 0;
			continue;
		}
		if (y > pos.y + 21)
			break;
		if (y < pos.y - 1) {
			++y;
			x = 0;
			for (; map_string[i] && map_string[i] != '\n'; ++i);
			continue;
		}
		if (x < pos.x - 1) {
			++x;
			continue;
		}
		if (x > pos.x + 31) {
			++y;
			x = 0;
			for (; map_string[i] && map_string[i] != '\n'; ++i);
			continue;
		}
		spr_type = define_block_type(map_string[i]);
		sprite = create_tile(x - pos.x, y - pos.y, spr_type,
		texture, sprite);
		sfRenderWindow_drawSprite(window, sprite, NULL);
		x++;
	}
	sfSprite_destroy(sprite);
}

void map_displayer_main(game_t *game, bool bool)
{
	int x = epi_strlen(game->cur_scene->name);

	if (bool == true)
		move_player_management(game);
	create_map(game->cur_scene->layers[0], game->win,
	game->cur_scene->layer_ground, game->player->position);
	create_map(game->cur_scene->layers[1], game->win,
	game->cur_scene->layer_col, game->player->position);
	display_npcs(game, game->npc);
	display_player(game);
	create_map(game->cur_scene->layers[2], game->win,
	game->cur_scene->layer_top, game->player->position);
	create_color_rect(game->outline, create_vector2f(20 * x + 5, 40),
	create_vector2f(10, 10), game->win);
	create_color_rect_in(sfWhite, create_vector2f(20 * x + 5, 40),
	create_vector2f(10, 10), game->win);
	create_text_pause(game->texture->font, create_vector2f(15, 15),
	game->cur_scene->name, game->win);
}
