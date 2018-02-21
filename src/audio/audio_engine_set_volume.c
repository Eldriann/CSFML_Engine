/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Set the volume of an audio track
*/

#include "my.h"
#include "my_sfml_core.h"
#include "my_sfml_audio.h"
#include <SFML/Audio.h>

int set_audio_volume(sf_audio_engine_t *engine, char const *id, double volume)
{
	sfMusic *requested_music = NULL;

	if (engine == NULL || id == NULL) {
		my_puterror("Set audio volume:\n    ");
		my_puterror(MSG_MY_SFML_ERR_NULL);
		return (84);
	}
	requested_music = (sfMusic *)get_data(id, engine->sound_list);
	if (requested_music == NULL)
		return (84);
	sfMusic_setVolume(requested_music, volume);
	return (0);
}