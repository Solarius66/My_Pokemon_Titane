/*
** EPITECH PROJECT, 2018
** INITIALIZE_GAME_2.C
** File description:
** Extension of initialize_game.c file
*/

#include "declaration.h"

int initialize_player(game_t *game)
{
	sfVector2f pos = {3, 14};

	if (!(game->player = malloc(sizeof(player_t))))
		return (84);
	game->player->playtime_hours = 0;
	game->player->playtime_minutes = 0;
	game->player->actual = 0;
	if (!(game->player->pokemons = malloc(sizeof(pokemon_t *) * 7)))
		return (84);
	for (int i = 0; i < 7; i++)
		game->player->pokemons[i] = NULL;
	game->player->badges = 0;
	game->player->money = 0;
	game->player->look_tile = 2;
	game->player->state = IDLING;
	game->player->move_c = sfClock_create();
	game->player->walk_c = sfClock_create();
	game->player->position = pos;
	game->player->name = NULL;
	return (0);
}

int initialize_music_extended(game_t *game)
{
	musics_t *musics = game->musics;
	char *snow = "assets/musics/snow.ogg";
	char *ligue = "assets/musics/ligue.ogg";
	char *victory = "assets/musics/victory.ogg";
	char *end = "assets/musics/end.ogg";
	char *volcano = "assets/musics/volcano.ogg";
	char *fight_salvage = "assets/musics/fight_salvage.ogg";
	char *fight_trainer = "assets/musics/fight_trainer.ogg";

	musics->snow = sfMusic_createFromFile(snow);
	musics->ligue = sfMusic_createFromFile(ligue);
	musics->victory = sfMusic_createFromFile(victory);
	musics->end = sfMusic_createFromFile(end);
	musics->volcano = sfMusic_createFromFile(volcano);
	musics->fight_salvage = sfMusic_createFromFile(fight_salvage);
	musics->fight_trainer = sfMusic_createFromFile(fight_trainer);
	return (0);
}

int initialize_music(game_t *game)
{
	char *intro = "assets/musics/intro.ogg";
	char *cinematic = "assets/musics/cinematic.ogg";
	char *start = "assets/musics/start.ogg";
	char *city = "assets/musics/city.ogg";
	char *road = "assets/musics/road.ogg";
	char *cave = "assets/musics/cave.ogg";

	if ((game->musics = malloc(sizeof(musics_t))) == NULL)
		return (84);
	game->musics->current = NULL;
	game->musics->intro = sfMusic_createFromFile(intro);
	game->musics->cinematic = sfMusic_createFromFile(cinematic);
	game->musics->start = sfMusic_createFromFile(start);
	game->musics->city = sfMusic_createFromFile(city);
	game->musics->road = sfMusic_createFromFile(road);
	game->musics->cave = sfMusic_createFromFile(cave);
	initialize_music_extended(game);
	return (0);
}

int initialize_pc(game_t *game)
{
	game->pc = malloc(sizeof(pc_t));
	if (!game->pc)
		return (84);
	game->pc->storage = malloc(sizeof(pokemon_t) * 257);
	if (!game->pc->storage)
		return (84);
	game->pc->storage[256] = NULL;
	for (int i = 0; i < 256; i++)
		game->pc->storage[i] = NULL;
	return (0);
}

int initialize_window(game_t *game)
{
	sfVideoMode mode = {960, 640, 32};
	sfRenderWindow *win = win_create(mode, "MY_POKEMON");

	if (!win)
		return (84);
	game->win = win;
	sfRenderWindow_setFramerateLimit(game->win, 60);
	return (0);
}
