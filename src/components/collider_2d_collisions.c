/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Collision logic funcs
*/

#include "my.h"
#include "my_sfml_gameobject.h"
#include "my_sfml_core.h"
#include <stdlib.h>

int does_point_collide(gameobject_t *go, vector_t point)
{
	sf_collider_2d_t *collider = get_component(go, COLLIDER_2D);
	sf_transform_t *transform = get_component(go, TRANSFORM);
	sfIntRect hitbox = collider->hitbox;

	if (collider == NULL || transform == NULL || go == NULL)
		return (0);
	hitbox.left += transform->position.x;
	hitbox.top += transform->position.y;
	if (point.x <= hitbox.left + hitbox.width && point.x >= hitbox.left && \
point.y <= hitbox.top + hitbox.height && point.y >= hitbox.top)
		return (1);
	return (0);
}

int does_gameobjects_collide(gameobject_t *go_1, gameobject_t *go_2)
{
	sf_collider_2d_t *col_1 = get_component(go_1, COLLIDER_2D);
	sf_transform_t *tr_1 = get_component(go_1, TRANSFORM);
	sfIntRect rect_1;

	if (col_1 == NULL || tr_1 == NULL || go_1 == go_2)
		return (0);
	rect_1 = col_1->hitbox;
	rect_1.left += tr_1->position.x;
	rect_1.top += tr_1->position.y;
	if (does_rectangle_collide(go_2, rect_1))
		return (1);
	return (0);
}

int does_rectangles_collide(sfIntRect rect_1, sfIntRect rect_2)
{
	if (rect_1.left < rect_2.left + rect_2.width && \
rect_1.left + rect_1.width > rect_2.left && \
rect_1.top < rect_2.top + rect_2.height && \
rect_1.height + rect_1.top > rect_2.top)
		return (1);
	return (0);
}

int does_rectangle_collide(gameobject_t *go, sfIntRect rectangle)
{
	sf_collider_2d_t *col = get_component(go, COLLIDER_2D);
	sf_transform_t *tr = get_component(go, TRANSFORM);
	sfIntRect go_rect;

	if (col == NULL || tr == NULL)
		return (0);
	go_rect = col->hitbox;
	go_rect.left += tr->position.x;
	go_rect.top += tr->position.y;
	if (does_rectangles_collide(rectangle, go_rect))
		return (1);
	return (0);
}