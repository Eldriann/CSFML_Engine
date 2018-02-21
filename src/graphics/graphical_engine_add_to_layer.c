/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Add a sprite to a render layer
*/

#include <stdlib.h>
#include "my_sfml_core.h"
#include "my_sfml_graphics.h"

int add_to_layer(sf_graph_engine_t *engine, int layer, void **sprite)
{
	sf_layer_t *requested_layer = NULL;

	if (engine == NULL || sprite == NULL || *sprite == NULL) {
		my_puterror("Add sprite to layer:\n    ");
		my_puterror(MSG_MY_SFML_ERR_NULL);
		return (84);
	}
	requested_layer = (sf_layer_t *)get_data_from_node(\
engine->layers_list, &layer, &layer_equals);
	if (requested_layer == NULL) {
		my_puterror("    [INFO]Just add missing layer don't bother\n");
		requested_layer = create_layer(layer);
		engine->layers_list = sf_push(requested_layer, \
my_int_to_str(layer), engine->layers_list);
	}
	requested_layer->sprite_list = sf_push(sprite, my_int_to_str(\
(long)sprite), requested_layer->sprite_list);
	return (0);
}

int remove_from_layers(sf_graph_engine_t *engine, void **object)
{
	sf_linked_list_t *curr_layer = NULL;
	sf_layer_t *layer = NULL;
	char *obj_id = my_int_to_str((long)object);

	if (engine == NULL || object == NULL || *object == NULL)
		return (84);
	curr_layer = engine->layers_list;
	for (int i = 0; curr_layer; i++) {
		layer = (sf_layer_t *)curr_layer->data;
		sf_remove(obj_id, &(layer->sprite_list));
		curr_layer = curr_layer->next;
	}
	free(obj_id);
	return (0);
}