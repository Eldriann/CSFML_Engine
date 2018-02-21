/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Load a texture in memory to be used after
*/

#include <stdlib.h>
#include "my_sfml_core.h"
#include "my_sfml_graphics.h"

int load_texture_in_memory(sf_graph_engine_t *engine, char const *path)
{
	sfTexture *new_texture = engine->get_texture(engine, path);

	if (path == NULL) {
		my_puterror("Load texture:\n    ");
		my_puterror(MSG_MY_SFML_ERR_NULL);
		return (84);
	}
	if (new_texture != NULL) {
		my_puterror("Load texture:\n    [INFO]Already loaded!\n");
		return (0);
	}
	new_texture = sfTexture_createFromFile(path, NULL);
	if (new_texture == NULL) {
		my_puterror("Load texture:\n    ");
		my_puterror(MSG_MY_SFML_FILE_NOT_FOUND);
		return (84);
	}
	engine->textures_list = sf_push(new_texture, \
my_strdup(path), engine->textures_list);
	return (0);
}

void unload_all_textures(sf_graph_engine_t *engine)
{
	char *curr_id = my_strdup("");

	if (engine == NULL) {
		my_puterror("Unload texture:\n    ");
		my_puterror(MSG_MY_SFML_ERR_NULL);
		return;
	}
	while (engine->textures_list != NULL) {
		free(curr_id);
		curr_id = my_strdup(engine->textures_list->id);
		sfTexture_destroy(engine->textures_list->data);
		sf_remove(curr_id, &(engine->textures_list));
	}
	free(curr_id);
}

sfTexture *get_texture_from_engine(sf_graph_engine_t *engine, char const *id)
{
	if (engine == NULL || id == NULL)
		return (NULL);
	return (get_data(id, engine->textures_list));
}