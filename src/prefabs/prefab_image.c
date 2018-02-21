/*
** EPITECH PROJECT, 2017
** mysfml
** File description:
** Prefab only containing an image
*/

#include "my_sfml_gameobject.h"
#include "my_sfml_engine.h"

gameobject_t *create_prefab_image(sf_engine_t *engine, char *texture, int layer)
{
	gameobject_t *go = create_gameobject("image");
	sf_animation_2d_t *anim = NULL;

	if (engine == NULL || go == NULL || texture == NULL)
		return (NULL);
	anim = go->add_component(go, ANIMATION_2D);
	if (anim == NULL) {
		go->destroy(go);
		return (NULL);
	}
	anim->set_sprite(anim, engine->get_sprite(engine, texture));
	engine->add_to_layer(engine, layer, (void **)&(anim->sprite));
	engine->add_gameobject(engine, go);
	return (go);
}