/*
** EPITECH PROJECT, 2018
** palyer moving
** File description:
** player move
*/

#include "declaration.h"

void move_player_management_3(game_t *game)
{
	if (move_left()) {
		game->player->look_tile = 2;
		if (0 != collision(game->cur_scene->layers[1],
			game->player->look_tile,
			game->player->position.x + 15,
			game->player->position.y + 10) &&
			collision_npc(game))
			game->player->position.x--;
		return;
	}
	if (move_right()) {
		game->player->look_tile = 3;
		if (0 != collision(game->cur_scene->layers[1],
			game->player->look_tile,
			game->player->position.x + 15,
			game->player->position.y + 10) &&
			collision_npc(game))
			game->player->position.x++;
	}
}

void move_player_management_2(game_t *game)
{
	if (move_top()) {
		game->player->look_tile = 1;
		if (0 != collision(game->cur_scene->layers[1],
			game->player->look_tile,
			game->player->position.x + 15,
			game->player->position.y + 10) &&
			collision_npc(game))
			game->player->position.y--;
		return;
	}
	if (move_bot()) {
		game->player->look_tile = 0;
		if (0 != collision(game->cur_scene->layers[1],
			game->player->look_tile,
			game->player->position.x + 15,
			game->player->position.y + 10) &&
			collision_npc(game))
			game->player->position.y++;
	}
}

sfBool define_move_available(game_t *game)
{
	int x = 50000;

	if (press_a())
		x = 20000;
	if (sfClock_getElapsedTime(game->player->walk_c).microseconds <= x)
		return (sfFalse);
	return (sfTrue);
}

void move_player_management(game_t *game)
{
	sfVector2f tempo = game->player->position;

	check_player_pos(game, &game->player->position);
	if (define_move_available(game) == sfFalse)
		return;
	sfClock_restart(game->player->walk_c);
	move_player_management_2(game);
	if (tempo.x != game->player->position.x ||
	game->player->position.y != tempo.y) {
		bushes_gest(game);
		return;
	}
	move_player_management_3(game);
	if (tempo.x != game->player->position.x ||
		game->player->position.y != tempo.y)
		bushes_gest(game);
	return;
}

void display_player(game_t *game)
{
	static int move = 0;
	static bool bool = true;
	int x = 1 + 6 * game->player->look_tile + move;

	if (press_a())
		x = x + 3;
	move = define_move_map(move, game->player->move_c, &bool);
	create_rect(game->player->texture[x], create_vector2f(480, 310),
	create_vector2f(32, 42), game->win);
}
