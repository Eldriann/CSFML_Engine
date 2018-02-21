/*
** EPITECH PROJECT, 2017
** mysfml
** File description:
** Physic interface continuation
*/

/* File created the 20/02/2018 at 14:14:09 by julian.frabel@epitech.eu */

#include "my_sfml_engine.h"

int remove_physic_object_main_engine(sf_engine_t *engine, gameobject_t *object)
{
	if (engine == NULL || object == NULL || engine->current_scene == NULL)
		return (84);
	return (engine->current_scene->physic_engine->remove_object(\
engine->current_scene->physic_engine, object));
}