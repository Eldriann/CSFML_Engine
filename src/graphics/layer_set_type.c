/*
** EPITECH PROJECT, 2017
** mysfml
** File description:
** Set the layer render type based on it's priority
*/

#include "my.h"
#include "my_sfml_graphics.h"

int set_layer_render_type(sf_graph_engine_t *engine, int priority, \
layer_render_type_t new_type)
{
	sf_linked_list_t *current_layer = NULL;

	if (engine == NULL)
		return (84);
	current_layer = engine->layers_list;
	while (current_layer != NULL) {
		if (((sf_layer_t *)current_layer->data)->priority == priority) {
			((sf_layer_t *)current_layer->data)->type = new_type;
			return (0);
		}
		current_layer = current_layer->next;
	}
	my_puterror("[ERROR]Set layer render type:\n\tLayer not found!\n");
	return (84);
}