/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Function managing layers
*/

#include "my.h"
#include "my_sfml_core.h"
#include "my_sfml_graphics.h"
#include <stdlib.h>

sf_layer_t *create_layer(int priority)
{
	sf_layer_t *new_layer = malloc(sizeof(*new_layer));

	if (new_layer == NULL) {
		my_puterror("Create layer:\n    ");
		my_puterror(MSG_MY_SFML_MALLOC);
		return (NULL);
	}
	new_layer->priority = priority;
	new_layer->type = ((priority != UI_TEXT) ? RTYPE_SPRITE : RTYPE_TEXT);
	new_layer->sprite_list = NULL;
	return (new_layer);
}

void destroy_layer(sf_layer_t *layer)
{
	char *curr_id = my_strdup("");

	if (layer == NULL) {
		my_puterror("Destroy layer:\n    ");
		my_puterror(MSG_MY_SFML_ERR_NULL);
		return;
	}
	while (layer->sprite_list != NULL) {
		free(curr_id);
		curr_id = my_strdup(layer->sprite_list->id);
		sf_remove(curr_id, &layer->sprite_list);
	}
	free(curr_id);
	free(layer);
}