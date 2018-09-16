/*
** EPITECH PROJECT, 2018
** my_rPokemong
** File description:
** creating texture
*/

#include "declaration.h"

void destroy_all_textures2(texture_t *text)
{
	destroy_textures(text->pokemons);
	sfTexture_destroy(text->start_back);
	sfTexture_destroy(text->start_top);
	sfTexture_destroy(text->start_move1);
	sfTexture_destroy(text->start_move2);
	sfTexture_destroy(text->dex_font);
	sfTexture_destroy(text->dex_line);
	sfTexture_destroy(text->pokeball);
	sfTexture_destroy(text->bag);
	sfTexture_destroy(text->items);
	sfTexture_destroy(text->fight_b);
	sfTexture_destroy(text->ball_till);
	sfTexture_destroy(text->trainer_big);
	sfTexture_destroy(text->start_b);
	sfTexture_destroy(text->jerem);
}

void destroy_all_textures(texture_t *text)
{
	destroy_textures(text->man);
	destroy_textures(text->woman);
	for (int i = 0; text->npc[i]; ++i)
		destroy_textures(text->npc[i]);
	free(text->npc);
	sfTexture_destroy(text->trainer_card);
	sfTexture_destroy(text->font_inv);
	sfTexture_destroy(text->pause_inv);
	for (int i = 0; i < 7; ++i)
		destroy_textures(text->icons_inv[i]);
	free(text->icons_inv);
	destroy_textures(text->exit);
	destroy_textures(text->poke_inv);
	destroy_textures(text->status);
	destroy_textures(text->badges);
	sfFont_destroy(text->font);
	sfTexture_destroy(text->controls);
	destroy_all_textures2(text);
}

void initialize_all_texture2(texture_t *text)
{
	sfIntRect area = create_int_rect(0, 0, 125, 38);

	text->exit = create_texture("./assets/textures/exit.png", 2, &area);
	text->controls = sfTexture_createFromFile(CONTROLS_TEXT, NULL);
	text->font = sfFont_createFromFile("./assets/textures/font.ttf");
	area = create_int_rect(0, 0, 256, 128);
	text->poke_inv = create_texture(POKE_TEXT, 2, &area);
	area = create_int_rect(0, 0, 20, 8);
	text->status = create_texture(STATUS_TEXT, 7, &area);
	area = create_int_rect(0, 0, 100, 100);
	text->badges = create_texture(BADGES_TEXT, 5, &area);
	text->pokemons = malloc(sizeof(sfTexture *) * (PKM_NBR + 1));
	text->pokemons[PKM_NBR] = NULL;
	area = create_int_rect(0, 0, 384, 64);
	for (int i = 0; i < PKM_NBR; ++i, area.top = area.height + area.top)
		text->pokemons[i] = sfTexture_createFromFile(PKM_TEXT, &area);
	text->start_back = sfTexture_createFromFile(START4, NULL);
	text->start_top = sfTexture_createFromFile(START1, NULL);
	text->start_move1 = sfTexture_createFromFile(START2, NULL);
	text->start_move2 = sfTexture_createFromFile(START3, NULL);
}

int initialize_all_texture(texture_t *text)
{
	sfIntRect area = create_int_rect(0, 0, 32, 42);

	text->man = create_texture("./assets/textures/man.png", 24, &area);
	text->woman = create_texture("./assets/textures/woman.png", 24, &area);
	text->npc = malloc(sizeof(sfTexture **) * 23);
	text->npc[22] = NULL;
	for (int i = 0; i < 22; ++i, area.top += area.height)
		text->npc[i] = create_texture("./assets/textures/npc.png",
		12, &area);
	text->trainer_card = sfTexture_createFromFile(TRAINER_TEXT, NULL);
	text->font_inv = sfTexture_createFromFile(FONT_TEXT, NULL);
	text->pause_inv = sfTexture_createFromFile(PAUSE_TEXT, NULL);
	area = create_int_rect(0, 0, 90, 70);
	text->icons_inv = malloc(sizeof(sfTexture **) * 8);
	text->icons_inv[7] = NULL;
	for (int i = 0; i < 7; ++i, area.top = area.height + area.top)
		text->icons_inv[i] = create_texture(ICONS_TEXT, 2, &area);
	initialize_all_texture2(text);
	initialize_all_texture3(text);
	return (0);
}

int initialize_pkm_texture(pokemon_t *p)
{
	sfIntRect area = create_int_rect(0, 0, 64, 64);

	for (; p->next != NULL; p = p->next, area.left = 0,
		area.top += area.height)
		p->texture = create_texture(TEXT_PATH, 4, &area);
	return (0);
}
