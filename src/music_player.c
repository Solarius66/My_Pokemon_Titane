/*
** EPITECH PROJECT, 2018
** MUSIC_PLAYER.C
** File description:
** Manages music in RPokémonG
*/

#include "declaration.h"

void play_music(musics_t *musics, sfMusic *music)
{
	if (!music)
		return;
	if (musics->current == music)
		return;
	if (musics->current)
		sfMusic_stop(musics->current);
	musics->current = music;
	sfMusic_setLoop(musics->current, true);
	sfMusic_play(musics->current);
}

void common_roads_music(musics_t *musics, char *n)
{
	int i = 0;
	char **parsed = NULL;

	if (!str_startwith(n, "ROUTE"))
		return;
	parsed = str_parse(n, ' ');
	i = epi_atoi(parsed[1]);
	if (i == 1 || i == 2 || i == 8 || i == 5)
		play_music(musics, musics->road);
	if (i == 4 || i == 6 || i == 7)
		play_music(musics, musics->road);
	stra_free(parsed);
}

void common_cities_music(musics_t *musics, char *n)
{
	if (str_iseq(n, "BOURG-JOY") || str_iseq(n, "PRAIMISSE"))
		play_music(musics, musics->city);
	if (str_iseq(n, "CREPUSCUL\'AIRE") || str_iseq(n, "CONTREFORT"))
		play_music(musics, musics->city);
	if (str_iseq(n, "SEOULOPOLIS") || str_iseq(n, "KORALGA"))
		play_music(musics, musics->city);
	if (str_iseq(n, "GEJUD\'O"))
		play_music(musics, musics->city);
}

void snow_music(musics_t *musics, char *n)
{
	if (str_iseq(n, "GOUFFRE ENTRENEIGE"))
		play_music(musics, musics->snow);
	if (str_iseq(n, "CRYONIS"))
		play_music(musics, musics->snow);
	if (str_iseq(n, "ROUTE 3"))
		play_music(musics, musics->snow);
}

void switch_music(musics_t *musics, scene_t *cur_scene)
{
	char *n = cur_scene->name;

	common_cities_music(musics, n);
	common_roads_music(musics, n);
	if (str_iseq(n, "ROUTE 6"))
		play_music(musics, musics->cave);
	snow_music(musics, n);
	if (str_iseq(n, "LIGUE POKEMON"))
		play_music(musics, musics->ligue);
	if (str_iseq(n, "ROUTE VICTOIRE"))
		play_music(musics, musics->victory);
	if (str_iseq(n, "VOLCAN KIBRUL"))
		play_music(musics, musics->volcano);
}
