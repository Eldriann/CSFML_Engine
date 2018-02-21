/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Create and destroy a scene respectivelly
*/

#include <string.h>
#include <stdlib.h>
#include "my_sfml_core.h"
#include "my_sfml_engine.h"
#include "my_sfml_scenes.h"

sf_scene_t *create_scene(char *name)
{
	sf_scene_t *scene = NULL;

	if (name == NULL) {
		my_putdebug("[ERROR]Create Scene:	\n");
		my_putdebug(MSG_MY_SFML_ERR_NULL);
		return (NULL);
	}
	scene = malloc(sizeof(*scene));
	if (scene == NULL)
		return (NULL);
	scene->name = strdup(name);
	scene->graphical_engine = create_graphical_engine();
	scene->audio_engine = create_audio_engine();
	scene->updaters = NULL;
	scene->gameobjects = NULL;
	scene->physic_engine = create_physics_engine();
	scene->load = NULL;
	scene->loop = NULL;
	scene->unload = NULL;
	return (scene);
}

void clean_gameobjects(sf_scene_t *scene)
{
	char *curr_id = NULL;

	if (scene == NULL)
		return;
	while (scene->gameobjects != NULL) {
		curr_id = strdup(scene->gameobjects->id);
		((gameobject_t *)scene->gameobjects->data)->destroy(\
scene->gameobjects->data);
		sf_remove(curr_id, &scene->gameobjects);
		free(curr_id);
	}
}

void clean_updaters(sf_scene_t *scene)
{
	if (scene == NULL)
		return;
	while (scene->updaters != NULL) {
		free(scene->updaters->data);
		sf_remove_node(scene->updaters, &scene->updaters);
	}
}

void reset_scene(sf_scene_t *scene)
{
	if (scene == NULL)
		return;
	clean_updaters(scene);
	clean_gameobjects(scene);
	scene->graphical_engine->destroy(scene->graphical_engine);
	scene->audio_engine->destroy(scene->audio_engine);
	scene->physic_engine->destroy(scene->physic_engine);
	scene->graphical_engine = create_graphical_engine();
	scene->audio_engine = create_audio_engine();
	scene->physic_engine = create_physics_engine();
}

void destroy_scene(sf_scene_t *scene)
{
	if (scene == NULL)
		return;
	clean_updaters(scene);
	clean_gameobjects(scene);
	scene->graphical_engine->destroy(scene->graphical_engine);
	scene->audio_engine->destroy(scene->audio_engine);
	scene->physic_engine->destroy(scene->physic_engine);
	free(scene->name);
	free(scene);
}
