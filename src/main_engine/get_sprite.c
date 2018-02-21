/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Return a new sprite
*/

#include "my.h"
#include "my_sfml_core.h"
#include "my_sfml_engine.h"
#include <SFML/Graphics.h>

sfTexture *get_texture_and_load_if_needed(sf_engine_t *engine, char const *id)
{
	sfTexture *result = engine->current_scene->graphical_engine->\
get_texture(engine->current_scene->graphical_engine, id);

	if (result == NULL)
		engine->load_texture(engine, id);
	result = engine->current_scene->graphical_engine->get_texture(\
engine->current_scene->graphical_engine, id);
	return (result);
}

sfSprite *get_sprite(sf_engine_t *engine, char const *id)
{
	sfTexture *texture = NULL;
	sfSprite *new_sprite = sfSprite_create();

	if (engine == NULL || id == NULL || new_sprite == NULL) {
		my_puterror("Get sprite:\n    ");
		my_puterror(MSG_MY_SFML_ERR_NULL);
		if (new_sprite != NULL)
			sfSprite_destroy(new_sprite);
		return (NULL);
	}
	texture = get_texture_and_load_if_needed(engine, id);
	if (texture != NULL)
		sfSprite_setTexture(new_sprite, texture, sfTrue);
	return (new_sprite);
}