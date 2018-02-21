/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Add an object to the physics update
*/

#include <stdlib.h>
#include "my_sfml_core.h"
#include "my_sfml_gameobject.h"
#include "my_sfml_physics.h"

int add_object_physics_engine(sf_physics_engine_t *engine, gameobject_t *object)
{
	sf_transform_t *tr = NULL;
	sf_rigidbody_2d_t *rb = NULL;
	sf_collider_2d_t *collider = NULL;

	if (engine == NULL || object == NULL) {
		my_puterror("Add physic object:\n    ");
		my_puterror(MSG_MY_SFML_ERR_NULL);
		return (84);
	}
	tr = get_component(object, TRANSFORM);
	rb = get_component(object, RIGIDBODY_2D);
	collider = get_component(object, COLLIDER_2D);
	if (tr == NULL || rb == NULL || collider == NULL) {
		my_puterror("Object doesn't have the required components!\n");
		return (84);
	}
	engine->physics_objects = sf_push(object, my_strdup(object->id), \
engine->physics_objects);
	return (0);
}

int remove_object_physics_engine(sf_physics_engine_t *engine, gameobject_t *obj)
{
	char *id = NULL;

	if (engine == NULL || obj == NULL) {
		my_puterror("Add physic object:\n    ");
		my_puterror(MSG_MY_SFML_ERR_NULL);
		return (84);
	}
	id = my_strdup(obj->id);
	sf_remove(id, &(engine->physics_objects));
	free(id);
	return (0);
}