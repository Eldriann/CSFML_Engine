/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Update the physics states
*/

#include <stdlib.h>
#include "my_sfml_core.h"
#include "my_sfml_physics.h"

int has_physics_collisions(sfIntRect pos, sf_physics_engine_t *engine, \
gameobject_t *obj)
{
	int nb_collisions = 0;
	gameobject_t **collide = NULL;
	int return_value = 0;
	sf_collider_2d_t *current_collider = NULL;

	collide = engine->get_collisions_rect(engine, pos, &nb_collisions, obj);
	for (int i = 0; i < nb_collisions; i++) {
		current_collider = get_component(collide[i], COLLIDER_2D);
		if (current_collider->collides) {
			return_value = 1;
		}
	}
	if (collide)
		free(collide);
	return (return_value);
}

void do_movement(sf_physics_engine_t *engine, gameobject_t *obj, float time)
{
	sf_transform_t *tr = get_component(obj, TRANSFORM);
	sf_rigidbody_2d_t *rb = get_component(obj, RIGIDBODY_2D);
	sf_collider_2d_t *collider = get_component(obj, COLLIDER_2D);
	sfIntRect new_pos;

	if (tr == NULL || rb == NULL || collider == NULL || rb->is_static)
		return;
	new_pos = collider->hitbox;
	(new_pos.left) += (rb->speed.x * time + tr->position.x);
	(new_pos.top) += (tr->position.y);
	if (!has_physics_collisions(new_pos, engine, obj))
		tr->position.x = (rb->speed.x * time + tr->position.x);
	else
		rb->speed.x = 0;
	new_pos = collider->hitbox;
	(new_pos.left) += (tr->position.x);
	(new_pos.top) += (rb->speed.y * time + tr->position.y);
	if (!has_physics_collisions(new_pos, engine, obj))
		tr->position.y = (rb->speed.y * time + tr->position.y);
	else
		rb->speed.y = 0;
}

void update_gameobject_physics(sf_physics_engine_t *engine, \
gameobject_t *obj, float time)
{
	sf_rigidbody_2d_t *rb = get_component(obj, RIGIDBODY_2D);

	if (rb == NULL || rb->is_static)
		return;
	rb->acceleration.y += engine->gravity_force;
	rb->speed.x = rb->acceleration.x * time + rb->speed.x;
	rb->speed.y = rb->acceleration.y * time + rb->speed.y;
	rb->speed.z = rb->acceleration.z * time + rb->speed.z;
	do_movement(engine, obj, time);
}

void update_triggers(sf_physics_engine_t *engine, gameobject_t *obj)
{
	sf_collider_2d_t *col = get_component(obj, COLLIDER_2D);
	int nb_collisions = 0;
	gameobject_t **collides = NULL;

	if (engine == NULL || obj == NULL || col == NULL)
		return;
	if (col->trigger == 0 || col->triggered_func == NULL)
		return;
	collides = engine->get_collisions_go(engine, obj, &nb_collisions);
	if (nb_collisions == 0) {
		return;
	}
	for (int i = 0; i < nb_collisions; i++) {
		col->triggered_func(obj, collides[i]);
	}
	if (collides)
		free(collides);
}

int update_physics(sf_physics_engine_t *engine, int time)
{
	sf_linked_list_t *curr_object = NULL;

	if (engine == NULL) {
		my_putdebug("Update physics:\n    ");
		my_putdebug(MSG_MY_SFML_ERR_NULL);
		return (84);
	}
	curr_object = engine->physics_objects;
	while (curr_object != NULL) {
		update_gameobject_physics(engine, curr_object->data, \
(float)time / 1000.0);
		update_triggers(engine, curr_object->data);
		curr_object = curr_object->next;
	}
	return (0);
}