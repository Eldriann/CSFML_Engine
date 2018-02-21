/*
** EPITECH PROJECT, 2017
** mysfml
** File description:
** Component that represent a button
*/

#include "my.h"
#include "my_sfml_gameobject.h"
#include <stdlib.h>

sf_button_t *create_button(gameobject_t *parent)
{
	sf_button_t *new_button = malloc(sizeof(*new_button));

	if (new_button == NULL)
		return (NULL);
	new_button->parent = parent;
	new_button->destroy = &destroy_button;
	new_button->on_clicked = &default_button_clicked;
	new_button->on_mouse_enter = &default_button_mouse_enter;
	new_button->on_mouse_exit = &default_button_mouse_exit;
	for (int i = 0; i < 4; i++)
		new_button->sprites[i] = NULL;
	new_button->curr_sprite = NULL;
	new_button->position = (sfIntRect){0, 0, 16, 32};
	new_button->engine = NULL;
	new_button->state = 0;
	return (new_button);
}

void destroy_button(sf_button_t *button)
{
	for (int i = 0; i < 4; i++) {
		if (button->sprites[i])
			sfSprite_destroy(button->sprites[i]);
	}
	free(button);
}

void default_button_clicked(sf_button_t *button)
{
	if (button == NULL)
		return;
}

void default_button_mouse_enter(sf_button_t *button)
{
	if (button == NULL)
		return;
	sfSprite_setColor(button->curr_sprite, sfColor_fromRGB(211, 211, 211));
}

void default_button_mouse_exit(sf_button_t *button)
{
	if (button == NULL)
		return;
	sfSprite_setColor(button->curr_sprite, sfWhite);
}