/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Animation_t functions
*/

#include "my.h"
#include "my_sfml_core.h"
#include "my_sfml_gameobject.h"
#include <stdlib.h>

sf_animation_2d_t *create_animation_2d(gameobject_t *parent)
{
	sf_animation_2d_t *new_animation = malloc(sizeof(*new_animation));

	if (new_animation == NULL) {
		my_puterror("Create animation_2d:\n    ");
		my_puterror(MSG_MY_SFML_MALLOC);
		return (NULL);
	}
	new_animation->parent = parent;
	new_animation->speed = 1.0;
	new_animation->timer = 0.0;
	new_animation->destroy = &destroy_animation_2d;
	new_animation->update = &default_update_animation;
	new_animation->set_sprite = &set_sprite_animation_2d;
	new_animation->sprite = NULL;
	new_animation->max_rect = (sfIntRect){0, 0, 1, 1};
	new_animation->view_rect = (sfIntRect){0, 0, 1, 1};
	return (new_animation);
}

void destroy_animation_2d(sf_animation_2d_t *animation)
{
	if (animation == NULL) {
		my_puterror("Destroy animation:\n    ");
		my_puterror(MSG_MY_SFML_ERR_NULL);
		return;
	}
	if (animation->sprite != NULL) {
		sfSprite_destroy(animation->sprite);
		animation->sprite = NULL;
	}
	free(animation);
}

int set_sprite_animation_2d(sf_animation_2d_t *animation, sfSprite *sprite)
{
	if (animation == NULL || sprite == NULL) {
		my_puterror("Set sprite animation:\n    ");
		my_puterror(MSG_MY_SFML_ERR_NULL);
		return (84);
	}
	if (animation->sprite)
		sfSprite_destroy(animation->sprite);
	animation->sprite = sprite;
	return (0);
}

int default_update_animation(sf_animation_2d_t *anim, int milliseconds)
{
	char *time_as_str = my_int_to_str(milliseconds);

	if (anim == NULL || time_as_str == NULL) {
		my_puterror("Default update animation:\n    ");
		my_puterror(MSG_MY_SFML_ERR_NULL);
		if (time_as_str != NULL)
			free(time_as_str);
		return (84);
	}
	my_puterror("[INFO][UPDATE ANIMATION]This is the default update \
animation that does nothing!\n    Probably not what you want!\n    Time:");
	my_puterror(time_as_str);
	my_puterror("\n");
	free(time_as_str);
	return (0);
}