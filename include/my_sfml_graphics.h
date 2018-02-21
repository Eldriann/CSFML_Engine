/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Functions related to graphics
*/

/**
** \file my_sfml_graphics.h
** \brief Header for a graphic engine
*/

#ifndef __MY_SFML_GRAPHICS_H_
#define __MY_SFML_GRAPHICS_H_

#include "my_sfml_core.h"
#include <SFML/Graphics.h>

/* --------------------------------DEFINE-------------------------------- */
/* ------------------------------END-DEFINE------------------------------ */

/* ----------------------------GRAPHIC-ENGINE---------------------------- */

struct my_sfml_graphical_engine {
	sf_linked_list_t *layers_list;
	sf_linked_list_t *textures_list;
	void (*destroy)();
	int (*render)();
	int (*add_to_layer)();
	int (*remove_from_layers)();
	int (*load_texture)();
	int (*set_type)();
	sfTexture *(*get_texture)();
};

typedef struct my_sfml_graphical_engine sf_graph_engine_t;

sf_graph_engine_t *create_graphical_engine(void);
void destroy_graphical_engine(sf_graph_engine_t *graph_engine);
void unload_all_textures(sf_graph_engine_t *engine);

int load_texture_in_memory(sf_graph_engine_t *engine, char const *path);
sfTexture *get_texture_from_engine(sf_graph_engine_t *engine, char const *id);

int render_frame(sf_graph_engine_t *graph_engine, sfRenderWindow *window);
int add_to_layer(sf_graph_engine_t *engine, int layer, void **sprite);
int remove_from_layers(sf_graph_engine_t *engine, void **object);

/* ------------------------------END-ENGINE------------------------------ */

/* --------------------------------LAYERS-------------------------------- */

enum layer_enum {
	BACKGROUND = -1,
	GAME = 0,
	FOREGROUND = 1,
	UI_IMAGE = 2147483646,
	UI_TEXT = 2147483647
};

enum layer_render_type {
	RTYPE_SPRITE,
	RTYPE_TEXT
};

typedef enum layer_enum layer_enum_t;
typedef enum layer_render_type layer_render_type_t;

struct my_sfml_layer {
	int priority;
	layer_render_type_t type;
	sf_linked_list_t *sprite_list;
};

typedef struct my_sfml_layer sf_layer_t;

sf_layer_t *create_layer(int priority);
void destroy_layer(sf_layer_t *layer);
void sort_layers(sf_linked_list_t **layer_list);
void render_layer(sf_layer_t *layer, sfRenderWindow *window);
int compare_layer(void *layer_one, void *layer_two);
int layer_equals(sf_layer_t *layer, int *layer_nb);

int set_layer_render_type(sf_graph_engine_t *engine, int priority, \
layer_render_type_t new_type);

/* ------------------------------END-LAYERS------------------------------ */

#endif /* __MY_SFML_GRAPHICS_H_ */