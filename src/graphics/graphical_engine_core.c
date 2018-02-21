/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Function that manage graphics
*/

#include <stdlib.h>
#include "my_sfml_core.h"
#include "my_sfml_graphics.h"

sf_graph_engine_t *create_graphical_engine(void)
{
	sf_graph_engine_t *new_graph_engine = malloc(sizeof(*new_graph_engine));

	if (new_graph_engine == NULL) {
		my_putdebug("Create graphical engine:\n    ");
		my_putdebug(MSG_MY_SFML_MALLOC);
		return (NULL);
	}
	new_graph_engine->layers_list = NULL;
	new_graph_engine->textures_list = NULL;
	new_graph_engine->destroy = &destroy_graphical_engine;
	new_graph_engine->load_texture = &load_texture_in_memory;
	new_graph_engine->get_texture = &get_texture_from_engine;
	new_graph_engine->render = &render_frame;
	new_graph_engine->add_to_layer = &add_to_layer;
	new_graph_engine->remove_from_layers = &remove_from_layers;
	new_graph_engine->set_type = &set_layer_render_type;
	return (new_graph_engine);
}

void destroy_graphical_engine(sf_graph_engine_t *engine)
{
	char *curr_id = my_strdup("");

	if (engine == NULL) {
		my_putdebug("Destroy graphical engine:\n    ");
		my_putdebug(MSG_MY_SFML_ERR_NULL);
		return;
	}
	unload_all_textures(engine);
	while (engine->layers_list != NULL) {
		free(curr_id);
		curr_id = my_strdup(engine->layers_list->id);
		destroy_layer(engine->layers_list->data);
		sf_remove(curr_id, &(engine->layers_list));
	}
	free(curr_id);
	free(engine);
}