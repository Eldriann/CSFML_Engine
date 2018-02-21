/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Physics engine that does all calculation (gravity, collisions...)
*/

/**
** \file my_sfml_physics.h
** \brief Header for a physic engine
**
** The speed and all mesurement are in pixels/seconds
*/

#ifndef __MY_SFML_PHYSICS_ENGINE_H_
#define __MY_SFML_PHYSICS_ENGINE_H_

#include "my_sfml_core.h"
#include "my_sfml_gameobject.h"

/* --------------------------------DEFINE-------------------------------- */
#define HITBOX_TEX "assets/sprites/hitbox.png"
#define DISPLAY_HITBOX 1

#define GRAVITY_FORCE 0
/* ------------------------------END-DEFINE------------------------------ */

/* ----------------------------PHYSICS-ENGINE---------------------------- */

struct my_sfml_physics_engine {
	sf_linked_list_t *physics_objects;
	float gravity_force;
	void (*destroy)(struct my_sfml_physics_engine *engine);
	int (*update)(struct my_sfml_physics_engine *engine, int time);
	int (*add_object)(struct my_sfml_physics_engine *engine, \
gameobject_t *object);
	int (*remove_object)(struct my_sfml_physics_engine *engine, \
gameobject_t *object);
	gameobject_t **(*get_collisions_rect)(\
struct my_sfml_physics_engine *engine, sfIntRect rect, \
int *size_buff, void *ignore);
	gameobject_t **(*get_collisions_point)(\
struct my_sfml_physics_engine *engine, vector_t point, int *size_buff);
	gameobject_t **(*get_collisions_go)(\
struct my_sfml_physics_engine *engine, gameobject_t *obj, int *size_buff);
};

typedef struct my_sfml_physics_engine sf_physics_engine_t;

sf_physics_engine_t *create_physics_engine(void);
void destroy_physics_engine(sf_physics_engine_t *engine);

int update_physics(sf_physics_engine_t *engine, int time);

int add_object_physics_engine(sf_physics_engine_t *engine, \
gameobject_t *object);
int remove_object_physics_engine(sf_physics_engine_t *engine, \
gameobject_t *obj);

gameobject_t **get_collisions_rect(sf_physics_engine_t *engine, \
sfIntRect rect, int *nb_collisions, void *ignore);
gameobject_t **get_collisions_point(sf_physics_engine_t *engine, \
vector_t point, int *nb_collisions);
gameobject_t **get_collisions_go(sf_physics_engine_t *engine, \
gameobject_t *obj, int *nb_collisions);

/* ------------------------------END-ENGINE------------------------------ */

#endif /* __MY_SFML_PHYSICS_ENGINE_H_ */