/*
** EPITECH PROJECT, 2018
** my_RPokemonG
** File description:
** AAAAAAAAAAAAAAH 20 MINUTES LEFT!!!!!!!!!!
*/

#include "declaration.h"

void do_play(game_t *game)
{
	sfMusic_setVolume(game->musics->intro, 70);
	sfMusic_setVolume(game->musics->cinematic, 100);
	sfMusic_setVolume(game->musics->start, 100);
	sfMusic_setVolume(game->musics->city, 100);
	sfMusic_setVolume(game->musics->road, 100);
	sfMusic_setVolume(game->musics->cave, 100);
	sfMusic_setVolume(game->musics->snow, 100);
	sfMusic_setVolume(game->musics->ligue, 100);
	sfMusic_setVolume(game->musics->victory, 100);
	sfMusic_setVolume(game->musics->end, 100);
	sfMusic_setVolume(game->musics->volcano, 100);
	sfMusic_setVolume(game->musics->fight_salvage, 100);
	sfMusic_setVolume(game->musics->fight_trainer, 100);
}

void do_pause(game_t *game)
{
	sfMusic_setVolume(game->musics->intro, 0);
	sfMusic_setVolume(game->musics->cinematic, 0);
	sfMusic_setVolume(game->musics->start, 0);
	sfMusic_setVolume(game->musics->city, 0);
	sfMusic_setVolume(game->musics->road, 0);
	sfMusic_setVolume(game->musics->cave, 0);
	sfMusic_setVolume(game->musics->snow, 0);
	sfMusic_setVolume(game->musics->ligue, 0);
	sfMusic_setVolume(game->musics->victory, 0);
	sfMusic_setVolume(game->musics->end, 0);
	sfMusic_setVolume(game->musics->volcano, 0);
	sfMusic_setVolume(game->musics->fight_salvage, 0);
	sfMusic_setVolume(game->musics->fight_trainer, 0);
}

void play_pause(game_t *game)
{
	static bool is_playing = false;

	if (is_playing == true) {
		do_pause(game);
		is_playing = false;
	} else {
		do_play(game);
		is_playing = true;
	}
	while (press_b(game));
}
