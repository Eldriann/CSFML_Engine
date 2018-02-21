/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Graphical related functions
*/

#include "my.h"
#include "my_sfml_core.h"
#include "my_sfml_engine.h"
#include <SFML/Graphics.h>

int render_main_engine(sf_engine_t *engine)
{
	if (engine == NULL) {
		my_puterror("Render main engine:\n    ");
		my_puterror(MSG_MY_SFML_ERR_NULL);
		return (84);
	}
	return (engine->current_scene->graphical_engine->render(\
engine->current_scene->graphical_engine, engine->window));
}

int add_to_layer_main_engine(sf_engine_t *engine, int layer, void **data)
{
	if (engine == NULL || data == NULL) {
		my_puterror("Render main engine:\n    ");
		my_puterror(MSG_MY_SFML_ERR_NULL);
		return (84);
	}
	return (engine->current_scene->graphical_engine->add_to_layer(\
engine->current_scene->graphical_engine, layer, data));
}

int load_texture_main_engine(sf_engine_t *engine, char const *path)
{
	if (engine == NULL || path == NULL) {
		my_puterror("Render main engine:\n    ");
		my_puterror(MSG_MY_SFML_ERR_NULL);
		return (84);
	}
	return (engine->current_scene->graphical_engine->load_texture(\
engine->current_scene->graphical_engine, path));
}

sfTexture *get_texture_main_engine(sf_engine_t *engine, char const *id)
{
	if (engine == NULL || id == NULL) {
		my_puterror("Render main engine:\n    ");
		my_puterror(MSG_MY_SFML_ERR_NULL);
		return (NULL);
	}
	return (engine->current_scene->graphical_engine->get_texture(\
engine->current_scene->graphical_engine, id));
}

int main_engine_set_layer_type(sf_engine_t *engine, int priority, \
layer_render_type_t new_type)
{
	if (engine == NULL) {
		my_puterror("Render main engine:\n    ");
		my_puterror(MSG_MY_SFML_ERR_NULL);
		return (84);
	}
	return (engine->current_scene->graphical_engine->set_type(\
engine->current_scene->graphical_engine, priority, new_type));
}