/*
** EPITECH PROJECT, 2018
** combat display
** File description:
** combat display
*/

#include "declaration.h"

void display_hp_combat(game_t *game, player_t *player, sfVector2f pos, int x)
{
	sfVector2f size = {0, x};
	sfColor color;

	size.x = player->pokemons[player->actual]->cur_health * 200 /
	player->pokemons[player->actual]->max_health;
	if (player->pokemons[player->actual]->cur_health <=
		player->pokemons[player->actual]->max_health / 4)
		color = sfRed;
	else if (player->pokemons[player->actual]->cur_health <=
		player->pokemons[player->actual]->max_health / 2)
		color = sfYellow;
	else
		color = sfGreen;
	create_color_rect_in(color, size, pos, game->win);
}

void display_xp_combat(game_t *game, player_t *player)
{
	sfVector2f size = {0, 5};

	size.x = player->pokemons[player->actual]->xp * 265 /
	(player->pokemons[player->actual]->lvl + 1 *
	player->pokemons[player->actual]->lvl + 1 *
	player->pokemons[player->actual]->lvl + 1);
	create_color_rect_in(sfCyan, size, create_vector2f(673, 425),
	game->win);
}

void combat_displayer3(game_t *game, player_t *player, player_t *npc)
{
	char *lvl_ally = epi_itoa(player->pokemons[player->actual]->lvl);
	char *lvl_ennemy = epi_itoa(npc->pokemons[npc->actual]->lvl);

	create_text_pause(game->texture->font, create_vector2f(900, 353),
	lvl_ally, game->win);
	create_text_pause(game->texture->font, create_vector2f(245, 90),
	lvl_ennemy, game->win);
	display_xp_combat(game, player);
	epi_free(lvl_ally);
	epi_free(lvl_ennemy);
}

void combat_displayer2(game_t *game, player_t *player, player_t *npc)
{
	char *cur_hp = epi_putf("%d",
	player->pokemons[player->actual]->cur_health);
	char *max_hp = epi_putf("%d",
	player->pokemons[player->actual]->max_health);

	create_text_pause(game->texture->font, create_vector2f(660, 353),
	player->pokemons[player->actual]->name, game->win);
	create_text_pause(game->texture->font, create_vector2f(10, 87),
	npc->pokemons[npc->actual]->name, game->win);
	create_text_pause(game->texture->font, create_vector2f(780, 397),
	cur_hp, game->win);
	create_text_pause(game->texture->font, create_vector2f(880, 397),
	max_hp, game->win);
	display_rect_text(game, false);
	display_hp_combat(game, player, create_vector2f(738, 387), 7);
	display_hp_combat(game, npc, create_vector2f(85, 126), 9);
	free(cur_hp);
	free(max_hp);
}

void combat_displayer(game_t *game, player_t *player, player_t *npc)
{
	sfSprite *ally;
	sfSprite *ennemy;

	ally = create_sprite(game->texture->pokemons[find_pokemon_by_id(
	game->pokemons, player->pokemons[player->actual]->id)->id],
	create_vector2f(100, 120), create_int_rect(0, 320, 64, 64));
	ennemy = create_sprite(game->texture->pokemons[find_pokemon_by_id(
	game->pokemons, npc->pokemons[player->actual]->id)->id],
	create_vector2f(600, 50), create_int_rect(0, 128, 64, 64));
	create_rect(game->texture->fight_b, create_vector2f(0, 0),
	create_vector2f(960, 440), game->win);
	sfSprite_setScale(ally, create_vector2f(5, 5));
	sfSprite_setScale(ennemy, create_vector2f(4, 4));
	sfRenderWindow_drawSprite(game->win, ally, NULL);
	sfRenderWindow_drawSprite(game->win, ennemy, NULL);
	combat_displayer2(game, player, npc);
	combat_displayer3(game, player, npc);
	sfSprite_destroy(ally);
	sfSprite_destroy(ennemy);
}
