/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** transform component
*/

#include "my_sfml_core.h"
#include "my_sfml_gameobject.h"
#include <stdlib.h>

sf_transform_t *create_transform(gameobject_t *parent)
{
	sf_transform_t *new_transform = malloc(sizeof(*new_transform));

	if (new_transform == NULL) {
		my_putdebug("Create transform:\n    ");
		my_putdebug(MSG_MY_SFML_MALLOC);
		return (NULL);
	}
	new_transform->parent = parent;
	new_transform->position = (vector_t){0.0, 0.0, 0.0};
	new_transform->rotation = (vector_t){0.0, 0.0, 0.0};
	new_transform->scale = (vector_t){1.0, 1.0, 1.0};
	new_transform->destroy = &destroy_transform;
	new_transform->move = &default_move_transform;
	new_transform->rotate = &default_rotate_transform;
	new_transform->resize = &default_resize_transform;
	return (new_transform);
}

void destroy_transform(sf_transform_t *transform)
{
	if (transform == NULL) {
		my_putdebug("Destroy transform:\n    ");
		my_putdebug(MSG_MY_SFML_ERR_NULL);
		return;
	}
	free(transform);
}

int default_move_transform(sf_transform_t *transform, vector_t movement)
{
	if (transform == NULL) {
		my_putdebug("Default move transform function:\n    ");
		my_putdebug(MSG_MY_SFML_ERR_NULL);
		return (84);
	}
	transform->position.x += movement.x;
	transform->position.y += movement.y;
	transform->position.z += movement.z;
	return (0);
}

int default_rotate_transform(sf_transform_t *transform, vector_t rotation)
{
	if (transform == NULL) {
		my_putdebug("Default rotate transform function:\n    ");
		my_putdebug(MSG_MY_SFML_ERR_NULL);
		return (84);
	}
	transform->rotation.x += rotation.x;
	transform->rotation.y += rotation.y;
	transform->rotation.z += rotation.z;
	return (0);
}

int default_resize_transform(sf_transform_t *transform, vector_t scale)
{
	if (transform == NULL) {
		my_putdebug("Default resize transform function:\n    ");
		my_putdebug(MSG_MY_SFML_ERR_NULL);
		return (84);
	}
	transform->scale.x += scale.x;
	transform->scale.y += scale.y;
	transform->scale.z += scale.z;
	return (0);
}