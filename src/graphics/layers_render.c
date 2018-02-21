/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Render layers
*/

#include "my_sfml_core.h"
#include "my_sfml_graphics.h"
#include <stdlib.h>

void render_text(sf_layer_t *layer, sfRenderWindow *window)
{
	sf_linked_list_t *curr_text_elem = NULL;
	sfText *curr_text;

	if (layer == NULL || window == NULL)
		return;
	curr_text_elem = layer->sprite_list;
	while (curr_text_elem != NULL) {
		curr_text = *((sfText **)curr_text_elem->data);
		if (curr_text == NULL) {
			curr_text_elem = curr_text_elem->next;
			continue;
		}
		sfRenderWindow_drawText(window, curr_text, NULL);
		curr_text_elem = curr_text_elem->next;
	}
}

void render_sprite(sf_layer_t *layer, sfRenderWindow *window)
{
	sf_linked_list_t *curr_sprite_elem = NULL;
	sfSprite *curr_sprite;

	if (layer == NULL || window == NULL)
		return;
	curr_sprite_elem = layer->sprite_list;
	while (curr_sprite_elem != NULL) {
		curr_sprite = *((sfSprite **)curr_sprite_elem->data);
		if (curr_sprite == NULL) {
			curr_sprite_elem = curr_sprite_elem->next;
			continue;
		}
		sfRenderWindow_drawSprite(window, curr_sprite, NULL);
		curr_sprite_elem = curr_sprite_elem->next;
	}
}

void render_layer(sf_layer_t *layer, sfRenderWindow *window)
{
	if (layer == NULL || window == NULL)
		return;
	switch (layer->type) {
	case RTYPE_TEXT:
		render_text(layer, window);
		break;
	case RTYPE_SPRITE:
		render_sprite(layer, window);
		break;
	default:
		my_puterror("[ERROR]Layer type unknown!\n");
		break;
	}
}