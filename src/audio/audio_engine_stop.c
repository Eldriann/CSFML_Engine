/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Stop a sound from the audio engine
*/

#include "my_sfml_core.h"
#include "my_sfml_audio.h"
#include <SFML/Audio.h>

int stop_audio(sf_audio_engine_t *engine, const char *id)
{
	sfMusic *requested_music = NULL;

	if (engine == NULL || id == NULL) {
		my_puterror("Stop audio:\n    ");
		my_puterror(MSG_MY_SFML_ERR_NULL);
		return (84);
	}
	requested_music = (sfMusic *)get_data(id, engine->sound_list);
	if (requested_music == NULL)
		return (84);
	sfMusic_stop(requested_music);
	return (0);
}