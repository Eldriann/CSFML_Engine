/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Component collider_2d
*/

#include "my.h"
#include "my_sfml_gameobject.h"
#include "my_sfml_core.h"
#include <stdlib.h>

int default_trigger_function(gameobject_t *go, gameobject_t *go_collider)
{
	if (go == NULL || go_collider == NULL) {
		my_puterror("Default trigger:\n    ");
		my_puterror(MSG_MY_SFML_ERR_NULL);
		return (84);
	}
	my_puterror("[Default trigger]Probably not what expected here!\n");
	return (0);
}

sf_collider_2d_t *create_collider_2d(gameobject_t *parent)
{
	sf_collider_2d_t *new_collider = malloc(sizeof(*new_collider));

	if (new_collider == NULL) {
		my_puterror("Create collider 2d:\n    ");
		my_puterror(MSG_MY_SFML_MALLOC);
		return (NULL);
	}
	new_collider->parent = parent;
	new_collider->hitbox = (sfIntRect){0, 0, 32, 32};
	new_collider->trigger = 0;
	new_collider->destroy = &destroy_collider_2d;
	new_collider->triggered_func = &default_trigger_function;
	return (new_collider);
}

void destroy_collider_2d(sf_collider_2d_t *collider)
{
	free(collider);
}