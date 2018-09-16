/*
** EPITECH PROJECT, 2018
** SCENE_MANAGER.C
** File description:
** Manages scenes switch and current scene
*/

#include "declaration.h"

void switch_scene(game_t *game, scene_t *next)
{
	game->cur_scene = next;
	switch_music(game->musics, game->cur_scene);
}
