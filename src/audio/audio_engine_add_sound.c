/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Add a sound to the audio engine
*/

#include "my_sfml_core.h"
#include "my_sfml_audio.h"
#include <stdlib.h>
#include <string.h>
#include <SFML/Audio.h>

int add_audio_to_engine(sf_audio_engine_t *engine, const char *path, int loop)
{
	sfMusic *new_music = NULL;

	if (engine == NULL || path == NULL) {
		my_putdebug("Add audio to engine:\n    ");
		my_putdebug(MSG_MY_SFML_ERR_NULL);
		return (84);
	}
	new_music = sfMusic_createFromFile(path);
	if (new_music == NULL) {
		my_putdebug(MSG_MY_SFML_ERR_NULL);
		return (84);
	}
	sfMusic_setLoop(new_music, loop);
	engine->sound_list = sf_push(new_music, strdup(path), \
engine->sound_list);
	return (0);
}
