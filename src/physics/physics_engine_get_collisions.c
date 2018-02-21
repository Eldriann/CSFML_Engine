/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Return an array with the gameobject colliding
*/

#include <stdlib.h>
#include "my_sfml_core.h"
#include "my_sfml_physics.h"

gameobject_t **get_collisions_go(sf_physics_engine_t *engine, \
gameobject_t *obj, int *nb_collisions)
{
	sf_linked_list_t *curr_obj = NULL;
	gameobject_t **result = NULL;

	curr_obj = engine->physics_objects;
	*nb_collisions = 0;
	for (; curr_obj != NULL; curr_obj = curr_obj->next)
		if (does_gameobjects_collide(curr_obj->data, obj) \
&& curr_obj->data != obj)
			*nb_collisions = (*nb_collisions) + 1;
	if (*nb_collisions == 0)
		return (NULL);
	result = malloc(sizeof(*result) * (*nb_collisions));
	curr_obj = engine->physics_objects;
	for (int i = 0; i < *nb_collisions; curr_obj = curr_obj->next)
		if (does_gameobjects_collide(curr_obj->data, obj) \
&& curr_obj->data != obj && result != NULL) {
			result[i] = curr_obj->data;
			i++;
		}
	return (result);
}

gameobject_t **get_collisions_rect(sf_physics_engine_t *engine, \
sfIntRect rect, int *nb_collisions, void *ignore)
{
	sf_linked_list_t *curr_obj = NULL;
	gameobject_t **result = NULL;

	curr_obj = engine->physics_objects;
	*nb_collisions = 0;
	for (; curr_obj != NULL; curr_obj = curr_obj->next)
		if (does_rectangle_collide(curr_obj->data, rect) \
&& curr_obj->data != ignore)
			*nb_collisions = (*nb_collisions) + 1;
	if (*nb_collisions == 0)
		return (NULL);
	result = malloc(sizeof(*result) * (*nb_collisions));
	curr_obj = engine->physics_objects;
	for (int i = 0; i < *nb_collisions; curr_obj = curr_obj->next)
		if (does_rectangle_collide(curr_obj->data, rect) \
&& curr_obj->data != ignore && result != NULL) {
			result[i] = curr_obj->data;
			i++;
		}
	return (result);
}

gameobject_t **get_collisions_point(sf_physics_engine_t *engine, \
vector_t point, int *nb_collisions)
{
	sf_linked_list_t *curr_obj = NULL;
	gameobject_t **result = NULL;

	if (engine == NULL || nb_collisions == NULL)
		return (NULL);
	curr_obj = engine->physics_objects;
	*nb_collisions = 0;
	for (; curr_obj != NULL; curr_obj = curr_obj->next)
		if (does_point_collide(curr_obj->data, point))
			*nb_collisions = (*nb_collisions) + 1;
	if (*nb_collisions == 0)
		return (NULL);
	result = malloc(sizeof(*result) * (*nb_collisions));
	curr_obj = engine->physics_objects;
	for (int i = 0; i < *nb_collisions; curr_obj = curr_obj->next)
		if (does_point_collide(curr_obj->data, point) && result != 0) {
			result[i] = curr_obj->data;
			i++;
		}
	return (result);
}