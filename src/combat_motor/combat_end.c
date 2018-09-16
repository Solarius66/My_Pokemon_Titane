/*
** EPITECH PROJECT, 2018
** end fight
** File description:
** end management
*/

#include "declaration.h"

void win_fct2(game_t *game, player_t *p1)
{
	int dol = rand() % 1000 + 1000;
	char *money = epi_putf("Vous remportez %d $", dol);

	while (!press_b(game));
	text_displayer(game, money, false);
	sfRenderWindow_display(game->win);
	free(money);
	while (press_b(game));
	while (!press_b(game));
	p1->money = p1->money + dol;	
}

void win_fct(game_t *game, player_t *p1, player_t *p2)
{
	int xp = experience(p1->pokemons[p1->actual],
	p2->pokemons[p2->actual]);
	char *str = epi_putf("%s gagne %d xp", p1->pokemons[p1->actual]->name,
	xp);

	sfRenderWindow_clear(game->win, sfBlack);
	combat_displayer(game, p1, p2);
	text_displayer(game, "Vous avez gagne!", false);
	sfRenderWindow_display(game->win);
	while (!press_b(game));
	text_displayer(game, str, false);
	p1->pokemons[p1->actual]->xp = 	p1->pokemons[p1->actual]->xp + xp;
	sfRenderWindow_display(game->win);
	free(str);
	while (press_b(game));
	win_fct2(game, p1);
	evolve(game, p1);
}

void defeat_fct(game_t *game, player_t *player, player_t *npc)
{
	sfClock* clock = sfClock_create();

	sfRenderWindow_clear(game->win, sfBlack);
	combat_displayer(game, player, npc);
	text_displayer(game, "Vous avez perdu!", false);
	sfRenderWindow_display(game->win);
	while (sfClock_getElapsedTime(clock).microseconds < 150000);
	sfClock_restart(clock);
	while (!press_b(game));
	switch_scene(game, game->scenes->cities[0]);
	game->player->position = create_vector2f(3, 14);
	for (int x = 0; x < 6; x++)
		if (game->player->pokemons[x] != NULL)
			game->player->pokemons[x]->cur_health =
			game->player->pokemons[x]->max_health;
	sfClock_destroy(clock);
}

void win_management(int win, game_t *game, player_t *player, player_t *npc)
{
	if (win == 1)
		win_fct(game, player, npc);
	if (win == 2)
		defeat_fct(game, player, npc);
}

void music_management_fight(game_t *game, player_t *npc, bool x)
{
	if (x == false) {
		sfMusic_pause(game->musics->current);
		if (epi_compare_str(npc->name, "WILD") == 1)
			sfMusic_play(game->musics->fight_salvage);
		else
			sfMusic_play(game->musics->fight_trainer);
	}
	if (x == true) {
		if (epi_compare_str(npc->name, "WILD") == 1)
			sfMusic_stop(game->musics->fight_salvage);
		else
			sfMusic_stop(game->musics->fight_trainer);
		sfMusic_play(game->musics->current);
	}
}
