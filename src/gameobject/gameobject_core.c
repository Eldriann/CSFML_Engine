/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Core for the game objects
*/

#include "my.h"
#include "my_sfml_core.h"
#include "my_sfml_gameobject.h"

gameobject_t *create_gameobject(char const *name)
{
	gameobject_t *new_go = malloc(sizeof(*new_go));

	if (new_go == NULL) {
		my_puterror("Create GO:\n    ");
		my_puterror(MSG_MY_SFML_MALLOC);
		return (NULL);
	}
	new_go->id = my_int_to_str((long)new_go);
	if (name == NULL)
		new_go->name = my_strdup("NO_NAME");
	else
		new_go->name = my_strdup(name);
	new_go->components = NULL;
	new_go->destroy = &destroy_gameobject;
	new_go->add_component = &add_component;
	new_go->add_custom_component = &add_custom_component;
	return (new_go);
}

void destroy_gameobject(gameobject_t *go)
{
	char *curr_id = NULL;

	if (go == NULL) {
		my_puterror("Destroy gameobject:\n    ");
		my_puterror(MSG_MY_SFML_ERR_NULL);
		return;
	}
	while (go->components != NULL) {
		curr_id = my_strdup(go->components->id);
		((component_cast_t *)go->components->data)->destroy(\
go->components->data);
		sf_remove(curr_id, &go->components);
		free(curr_id);
	}
	free(go->id);
	free(go->name);
	free(go);
}