/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Add a component to a gameobject
*/

#include <stdlib.h>
#include "my_sfml_core.h"
#include "my_sfml_gameobject.h"

void *get_component_struct(go_component_t type, gameobject_t *parent)
{
	switch (type) {
	case TRANSFORM: return (create_transform(parent));
	case ANIMATION_2D: return (create_animation_2d(parent));
	case COLLIDER_2D: return (create_collider_2d(parent));
	case RIGIDBODY_2D: return (create_rigidbody_2d(parent));
	case TEXT: return (create_text(parent));
	case BUTTON: return (create_button(parent));
	}
	return (NULL);
}

void *add_component(gameobject_t *go, go_component_t type)
{
	void *new_comp = NULL;

	if (go == NULL) {
		my_putdebug("Add component:\n    ");
		my_putdebug(MSG_MY_SFML_ERR_NULL);
		return (NULL);
	}
	if (get_component(go, type)) {
		my_putdebug("[INFO]Gamobject already have this component\n");
		return (get_component(go, type));
	}
	new_comp = get_component_struct(type, go);
	if (new_comp == NULL) {
		my_putdebug("Add component:\n    ");
		my_putdebug(MSG_MY_SFML_ERR_NULL);
		return (NULL);
	}
	go->components = sf_push(new_comp, my_int_to_str(type), go->components);
	return (new_comp);
}

void *add_custom_component(gameobject_t *go, \
void *(*create_func)(gameobject_t *parent), int type)
{
	void *new_comp = NULL;

	if (go == NULL || create_func == NULL) {
		my_putdebug("Add custom component:\n    ");
		my_putdebug(MSG_MY_SFML_ERR_NULL);
		return (NULL);
	}
	if (get_component(go, type)) {
		my_putdebug("[INFO]Gamobject already have this component\n");
		return (get_component(go, type));
	}
	new_comp = create_func(go);
	if (new_comp == NULL) {
		my_putdebug("Add component:\n    ");
		my_putdebug(MSG_MY_SFML_ERR_NULL);
		return (NULL);
	}
	go->components = sf_push(new_comp, my_int_to_str(type), go->components);
	return (new_comp);
}

void *get_component(gameobject_t *go, int type)
{
	sf_linked_list_t *current_component = NULL;

	if (go == NULL) {
		my_putdebug("Get component:\n    ");
		my_putdebug(MSG_MY_SFML_ERR_NULL);
		return (NULL);
	}
	current_component = go->components;
	while (current_component != NULL) {
		if (atoi(current_component->id) == type)
			return (current_component->data);
		current_component = current_component->next;
	}
	my_putdebug("Get component:\n    ");
	my_putdebug(MSG_MY_SFML_DATA_NOT_FOUND);
	return (NULL);
}
