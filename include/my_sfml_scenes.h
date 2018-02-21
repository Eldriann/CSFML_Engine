/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Scenes
*/

/**
** \file my_sfml_scenes.h
** \brief Header for the scenes
*/

#ifndef __MY_SFML_SCENES_H_
#define __MY_SFML_SCENES_H_

#include "my_sfml_audio.h"
#include "my_sfml_graphics.h"
#include "my_sfml_gameobject.h"
#include "my_sfml_physics.h"
#include <SFML/Graphics.h>

/* --------------------------------DEFINE-------------------------------- */

#define UPDATER int (*)(void *, int)

/* ------------------------------END-DEFINE------------------------------ */

/* --------------------------------UPDATE-------------------------------- */

struct updater {
	void *object;
	int (*update)(void *object, int time_milliseconds);
};

typedef struct updater updater_t;

/* ------------------------------END-UPDATE------------------------------ */

/* --------------------------------SCENES-------------------------------- */

struct scene {
	char *name;
	int (*load)();
	int (*loop)();
	int (*unload)();
	sf_graph_engine_t *graphical_engine;
	sf_audio_engine_t *audio_engine;
	sf_physics_engine_t *physic_engine;
	sf_linked_list_t *updaters;
	sf_linked_list_t *gameobjects;
};

typedef struct scene sf_scene_t;

sf_scene_t *create_scene(char *name);
void destroy_scene(sf_scene_t *scene);
void reset_scene(sf_scene_t *scene);

/* ------------------------------END-SCENES------------------------------ */

#endif /* __MY_SFML_SCENES_H_ */