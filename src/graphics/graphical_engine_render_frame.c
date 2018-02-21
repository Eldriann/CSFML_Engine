/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Render a frame of the graphical engine
*/

#include "my.h"
#include "my_sfml_core.h"
#include "my_sfml_graphics.h"

int render_frame(sf_graph_engine_t *graph_engine, sfRenderWindow *window)
{
	sf_linked_list_t *curr_pos_list = NULL;
	sf_layer_t *curr_layer = NULL;

	if (graph_engine == NULL)
		return (84);
	sfRenderWindow_clear(window, sfBlack);
	sort_layers(&(graph_engine->layers_list));
	curr_pos_list = graph_engine->layers_list;
	while (curr_pos_list != NULL) {
		curr_layer = (sf_layer_t *)curr_pos_list->data;
		if (curr_layer == NULL) {
			curr_pos_list = curr_pos_list->next;
			continue;
		}
		render_layer(curr_layer, window);
		curr_pos_list = curr_pos_list->next;
	}
	sfRenderWindow_display(window);
	return (0);
}