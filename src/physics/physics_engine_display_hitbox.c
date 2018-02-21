/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Display all hitbox as a pink rect
*/

#include "my.h"
#include "my_sfml_engine.h"
#include "my_sfml_gameobject.h"

static void display(gameobject_t *obj, sfSprite *spr, sf_engine_t *engine);

void display(gameobject_t *obj, sfSprite *spr, sf_engine_t *engine)
{
	sf_transform_t *tr = get_component(obj, TRANSFORM);
	sf_collider_2d_t *col = get_component(obj, COLLIDER_2D);

	if (tr == NULL || col == NULL)
		return;
	sfSprite_setPosition(spr, \
(sfVector2f){tr->position.x + col->hitbox.left, \
tr->position.y + col->hitbox.top});
	sfSprite_setScale(spr, \
(sfVector2f){col->hitbox.width, col->hitbox.height});
	sfRenderWindow_drawSprite(engine->window, spr, NULL);
}

int display_hitbox(sf_engine_t *engine)
{
	sfSprite *spr = engine->get_sprite(engine, "assets/sprites/hitbox.png");
	sf_linked_list_t *curr_elem = NULL;

	if (DISPLAY_HITBOX == 0 || spr == NULL) {
		if (spr)
			sfSprite_destroy(spr);
		return (0);
	}
	curr_elem = engine->current_scene->physic_engine->physics_objects;
	for (int i = 0; curr_elem != NULL; i++) {
		display(curr_elem->data, spr, engine);
		curr_elem = curr_elem->next;
	}
	sfSprite_destroy(spr);
	sfRenderWindow_display(engine->window);
	return (0);
}