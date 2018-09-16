/*
** EPITECH PROJECT, 2018
** my_RPokemonG
** File description:
** experience gest
*/

#include "declaration.h"

void evolve2(game_t *game, player_t *pkm, pokemon_t *new, int i)
{
	char *str = epi_putf("quoi? %s evolue en %s", pkm->pokemons[i]->name,
	new->name);

	text_displayer(game, str, false);
	sfRenderWindow_display(game->win);
	destruct_pokemon(pkm->pokemons[i]);
	raise_lvl(new);
	--new->lvl;
	pkm->pokemons[i] = new;
	epi_free(str);
}

void evolve(game_t *game, player_t *pkm)
{
	pokemon_t *new;
	int i;

	for (i = 0; i < 6; ++i) {
		if (pkm->pokemons[i] &&
			pkm->pokemons[i]->lvl >= pkm->pokemons[i]->lvl_evolve)
			break;
	}
	if (!pkm->pokemons[i] || (i == 5 && pkm->pokemons[i]->lvl <
		pkm->pokemons[i]->lvl_evolve))
		return;
	new = pokemon_dup_by_id(pkm->pokemons[i]->id_evolve,
	pkm->pokemons[i]->lvl, game->pokemons);
	evolve2(game, pkm, new, i);
	while (press_b(game));
	while (!press_b(game));
}

void raise_lvl(pokemon_t *pkm)
{
	pkm->max_health += 3;
	++pkm->lvl;
	pkm->damage += 3;
	pkm->defense += 3;
	pkm->special_damage += 3;
	pkm->special_defense += 3;
	pkm->attack_speed += 3;
}

int experience(pokemon_t *player, pokemon_t *ia)
{
	int temp = 0;
	int exp_temp = 1;

	if (player->lvl >= 100)
		return (0);
	for (int i = 1; i < player->lvl; ++i)
		exp_temp += (player->lvl - i) *
		(player->lvl - i) * (player->lvl - i);
	temp = 100 * ia->lvl / 7;
	player->xp += temp;
	if (player->xp >= player->lvl * player->lvl * player->lvl + exp_temp)
		raise_lvl(player);
	return (temp);
}
