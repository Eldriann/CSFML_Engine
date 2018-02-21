/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Core of the audio engine
*/

#include "my_sfml_core.h"
#include "my_sfml_audio.h"
#include <SFML/Audio.h>
#include <stdlib.h>

sf_audio_engine_t *create_audio_engine(void)
{
	sf_audio_engine_t *new_engine = malloc(sizeof(*new_engine));

	if (new_engine == NULL) {
		my_putdebug("Create audio engine:\n    ");
		my_putdebug(MSG_MY_SFML_MALLOC);
		return (NULL);
	}
	new_engine->sound_list = NULL;
	new_engine->destroy = &destroy_audio_engine;
	new_engine->add_audio = &add_audio_to_engine;
	new_engine->play = &play_audio;
	new_engine->stop = &stop_audio;
	new_engine->set_volume = &set_audio_volume;
	return (new_engine);
}

void destroy_audio_engine(sf_audio_engine_t *engine)
{
	char *curr_id = my_strdup("");

	while (engine->sound_list != NULL) {
		free(curr_id);
		curr_id = my_strdup(engine->sound_list->id);
		sfMusic_destroy(engine->sound_list->data);
		sf_remove(curr_id, &(engine->sound_list));
	}
	free(curr_id);
	free(engine);
}