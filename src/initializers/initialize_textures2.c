/*
** EPITECH PROJECT, 2018
** texture_init2
** File description:
** texture_init2
*/

#include "declaration.h"

void initialize_all_texture3(texture_t *text)
{
	text->dex_font = sfTexture_createFromFile(DEX_FONT, NULL);
	text->dex_line = sfTexture_createFromFile(DEX_LINE, NULL);
	text->pokeball = sfTexture_createFromFile(POKEBALL, NULL);
	text->bag = sfTexture_createFromFile(BAG, NULL);
	text->items = sfTexture_createFromFile(ITEMS, NULL);
	text->fight_b = sfTexture_createFromFile(FIGHT_BACK, NULL);
	text->ball_till = sfTexture_createFromFile(BALL, NULL);
	text->trainer_big = sfTexture_createFromFile(TRAINER, NULL);
	text->start_b = sfTexture_createFromFile(START, NULL);
	text->jerem = sfTexture_createFromFile(PROF, NULL);
}
