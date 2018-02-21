/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Function for creating and destroying the main engine
*/

#include "my_sfml_core.h"
#include "my_sfml_engine.h"
#include "my_sfml_graphics.h"
#include "my_sfml_audio.h"
#include "my_sfml_gameobject.h"
#include "my_sfml_physics.h"
#include <string.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

void destroy_engine(sf_engine_t *engine)
{
	char *curr_id = NULL;

	if (engine == NULL)
		return;
	while (engine->scenes != NULL) {
		curr_id = strdup(engine->scenes->id);
		destroy_scene(engine->scenes->data);
		sf_remove(curr_id, &engine->scenes);
		free(curr_id);
	}
	if (engine->window)
		sfRenderWindow_destroy(engine->window);
	if (engine->main_clock)
		sfClock_destroy(engine->main_clock);
	free(engine);
}

void set_physics_functions(sf_engine_t *engine)
{
	engine->add_physic_object = &add_physic_object_main_engine;
	engine->remove_physic_object = &remove_physic_object_main_engine;
	engine->get_collisions_go = &get_collisions_go_main_engine;
	engine->get_collisions_point = &get_collisions_point_main_engine;
	engine->get_collisions_rect = &get_collisions_rect_main_engine;
	engine->initialize_physic_state = &initialize_physic_state;
	engine->set_layer_type = &main_engine_set_layer_type;
	engine->remove_from_layers = &remove_from_layers_main_engine;
	engine->destroy_gameobject = &destroy_gameobject_main_engine;
}

void set_functions(sf_engine_t *engine)
{
	engine->destroy = &destroy_engine;
	engine->render = &render_main_engine;
	engine->add_to_layer = &add_to_layer_main_engine;
	engine->load_texture = &load_texture_main_engine;
	engine->get_texture = &get_texture_main_engine;
	engine->add_audio = &add_audio_main_engine;
	engine->play = &play_audio_main_engine;
	engine->stop = &stop_audio_main_engine;
	engine->set_volume = &set_audio_main_engine;
	engine->add_update = &add_update_main_engine;
	engine->update = &update_main_engine;
	engine->remove_update = &remove_update;
	engine->add_gameobject = &add_gameobject;
	engine->remove_gameobject = &remove_gameobject;
	engine->get_gameobject = &get_gameobject;
	engine->add_scene = &add_scene;
	engine->get_scene = &get_scene;
	engine->change_scene = &change_scene;
	engine->get_sprite = &get_sprite;
	set_physics_functions(engine);
}

sf_engine_t *create_engine(sfRenderWindow *window)
{
	sf_engine_t *engine = malloc(sizeof(*engine));

	if (window == NULL || engine == NULL)
		return (NULL);
	set_functions(engine);
	engine->window = window;
	engine->scenes = NULL;
	engine->current_scene = NULL;
	engine->main_clock = sfClock_create();
	if (engine->main_clock == NULL) {
		engine->destroy(engine);
		return (NULL);
	}
	return (engine);
}
