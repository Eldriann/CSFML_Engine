/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Update for the main engine
*/

#include <stdlib.h>
#include "my_sfml_core.h"
#include "my_sfml_engine.h"

int add_update_main_engine(sf_engine_t *engine, void *object, \
int (*update)(void *object, int time))
{
	updater_t *new_updater = malloc(sizeof(*new_updater));

	if (object == NULL || update == NULL || new_updater == NULL) {
		my_puterror("Add updater:\n    ");
		my_puterror(MSG_MY_SFML_ERR_NULL);
		if (new_updater != NULL)
			free(new_updater);
		return (84);
	}
	new_updater->object = object;
	new_updater->update = update;
	engine->current_scene->updaters = sf_push(\
new_updater, my_int_to_str((long)object), \
engine->current_scene->updaters);
	return (0);
}

int remove_update(sf_engine_t *engine, void *object)
{
	char *curr_id = my_int_to_str((long)object);
	updater_t **array = (updater_t **)get_data_array(curr_id, \
engine->current_scene->updaters);

	if (array) {
		for (int i = 0; array[i]; i++)
			free(array[i]);
		free(array);
	}
	sf_remove(curr_id, &engine->current_scene->updaters);
	free(curr_id);
	return (0);
}

void update_main_engine(sf_engine_t *engine)
{
	sf_linked_list_t *curr_index = NULL;
	int delta_time = 0;

	if (engine == NULL) {
		my_puterror("Update engine:\n    ");
		my_puterror(MSG_MY_SFML_ERR_NULL);
		return;
	}
	if (engine->next_scene)
		update_selected_scene(engine);
	if (engine->main_clock)
		delta_time = sfTime_asMilliseconds(\
sfClock_restart(engine->main_clock));
	if (engine->current_scene)
		curr_index = engine->current_scene->updaters;
	while (curr_index != NULL) {
		((updater_t *)curr_index->data)->update(\
((updater_t *)curr_index->data)->object, delta_time);
		curr_index = curr_index->next;
	}
}