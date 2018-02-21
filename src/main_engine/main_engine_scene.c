/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Scene management
*/

#include <stdlib.h>
#include "my_sfml_engine.h"

int add_scene(sf_engine_t *engine, sf_scene_t *scene)
{
	if (engine == NULL || scene == NULL)
		return (84);
	engine->scenes = sf_push(scene, my_strdup(scene->name), engine->scenes);
	return (0);
}

sf_scene_t *get_scene(sf_engine_t *engine, const char *name)
{
	if (engine == NULL || name == NULL)
		return (NULL);
	return ((sf_scene_t *)get_data(name, engine->scenes));
}

int update_selected_scene(sf_engine_t *engine)
{
	sf_scene_t *new_scene = get_scene(engine, engine->next_scene);

	if (engine == NULL || engine->next_scene == NULL || new_scene == NULL) {
		if (new_scene == NULL) {
			my_putdebug("[ERROR]Requested scene:");
			my_putdebug(engine->next_scene);
			my_putdebug(" not found!\n");
		}
		return (84);
	}
	if (engine->current_scene && engine->current_scene->unload)
		engine->current_scene->unload(engine, engine->data);
	engine->current_scene = new_scene;
	if (engine->current_scene && engine->current_scene->load)
		engine->current_scene->load(engine, engine->data);
	engine->data = NULL;
	free(engine->next_scene);
	engine->next_scene = NULL;
	return (0);
}

int change_scene(sf_engine_t *engine, const char *name, void *data)
{
	engine->next_scene = my_strdup(name);
	engine->data = data;
	return (0);
}