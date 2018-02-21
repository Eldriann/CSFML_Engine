/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Physics engine core
*/

#include "my.h"
#include "my_sfml_core.h"
#include "my_sfml_engine.h"
#include "my_sfml_physics.h"

sf_physics_engine_t *create_physics_engine(void)
{
	sf_physics_engine_t *new_engine = malloc(sizeof(*new_engine));

	if (new_engine == NULL) {
		my_puterror("Create physics engine:\n    ");
		my_puterror(MSG_MY_SFML_MALLOC);
		return (NULL);
	}
	new_engine->physics_objects = NULL;
	new_engine->gravity_force = GRAVITY_FORCE;
	new_engine->destroy = &destroy_physics_engine;
	new_engine->update = &update_physics;
	new_engine->add_object = &add_object_physics_engine;
	new_engine->remove_object = &remove_object_physics_engine;
	new_engine->get_collisions_point = &get_collisions_point;
	new_engine->get_collisions_rect = &get_collisions_rect;
	new_engine->get_collisions_go = &get_collisions_go;
	return (new_engine);
}

void destroy_physics_engine(sf_physics_engine_t *engine)
{
	char *curr_id = NULL;

	if (engine == NULL) {
		my_puterror("Destroy physics engine:\n    ");
		my_puterror(MSG_MY_SFML_ERR_NULL);
		return;
	}
	while (engine->physics_objects != NULL) {
		curr_id = my_strdup(engine->physics_objects->id);
		sf_remove(curr_id, &engine->physics_objects);
		free(curr_id);
	}
	free(engine);
}