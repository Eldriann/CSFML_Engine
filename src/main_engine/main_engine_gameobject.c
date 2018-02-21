/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Manage the gameobject list of the main engine
*/

#include <string.h>
#include <stdlib.h>
#include "my_sfml_core.h"
#include "my_sfml_engine.h"
#include "my_sfml_gameobject.h"

int add_gameobject(sf_engine_t *engine, gameobject_t *object)
{
	if (engine == NULL || object == NULL) {
		my_putdebug("Add gameobject engine:\n    ");
		my_putdebug(MSG_MY_SFML_ERR_NULL);
		return (84);
	}
	engine->current_scene->gameobjects = sf_push(object, \
strdup(object->id), engine->current_scene->gameobjects);
	return (0);
}

int remove_gameobject(sf_engine_t *engine, gameobject_t *object)
{
	char *curr_id = strdup(object->id);

	object->destroy(object);
	sf_remove(curr_id, &engine->current_scene->gameobjects);
	free(curr_id);
	return (0);
}

gameobject_t *get_gameobject(sf_engine_t *engine, const char *name)
{
	sf_linked_list_t *curr_obj = NULL;

	if (engine == NULL || name == NULL)
		return (NULL);
	curr_obj = engine->current_scene->gameobjects;
	while (curr_obj != NULL) {
		if (!strcmp(name, ((gameobject_t *)curr_obj->data)->name))
			return (curr_obj->data);
		curr_obj = curr_obj->next;
	}
	return (NULL);
}

int destroy_gameobject_main_engine(sf_engine_t *engine, gameobject_t *obj)
{
	sf_animation_2d_t *anim = NULL;
	sf_text_t *text = NULL;

	if (engine == NULL || obj == NULL)
		return (84);
	anim = get_component(obj, ANIMATION_2D);
	text = get_component(obj, TEXT);
	if (anim != NULL)
		engine->remove_from_layers(engine, (void **)&(anim->sprite));
	if (text != NULL)
		engine->remove_from_layers(engine, (void **)&(text->text));
	for (sf_linked_list_t *list = obj->components; list; list = list->next)
		engine->remove_update(engine, list->data);
	engine->remove_update(engine, obj);
	engine->remove_physic_object(engine, obj);
	engine->remove_gameobject(engine, obj);
	return (0);
}
