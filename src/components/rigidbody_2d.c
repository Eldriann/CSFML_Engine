/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Component rigidbody_2d
*/

#include "my_sfml_gameobject.h"
#include "my_sfml_core.h"
#include <stdlib.h>

sf_rigidbody_2d_t *create_rigidbody_2d(gameobject_t *parent)
{
	sf_rigidbody_2d_t *new_rigidbody = malloc(sizeof(*new_rigidbody));

	if (new_rigidbody == NULL) {
		my_puterror("Create rigidbody 2d:\n    ");
		my_puterror(MSG_MY_SFML_MALLOC);
		return (NULL);
	}
	new_rigidbody->parent = parent;
	new_rigidbody->charge = (vector_t){0.0, 0.0, 0.0};
	new_rigidbody->acceleration = (vector_t){0.0, 0.0, 0.0};
	new_rigidbody->speed = (vector_t){0.0, 0.0, 0.0};
	new_rigidbody->is_static = 0;
	new_rigidbody->mass = 1.0;
	new_rigidbody->destroy = &destroy_rigidbody_2d;
	return (new_rigidbody);
}

void destroy_rigidbody_2d(sf_rigidbody_2d_t *rigidbody)
{
	free(rigidbody);
}