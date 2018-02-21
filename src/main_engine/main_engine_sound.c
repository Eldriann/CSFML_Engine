/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Audio related functions for main engine
*/

#include "my.h"
#include "my_sfml_core.h"
#include "my_sfml_engine.h"

int add_audio_main_engine(sf_engine_t *engine, const char *path, int loop)
{
	if (engine == NULL || path == NULL) {
		my_puterror("Add audio main engine:\n    ");
		my_puterror(MSG_MY_SFML_ERR_NULL);
		return (84);
	}
	return (engine->current_scene->audio_engine->add_audio(\
engine->current_scene->audio_engine, path, loop));
}

int play_audio_main_engine(sf_engine_t *engine, const char *id)
{
	if (engine == NULL || id == NULL) {
		my_puterror("Add audio main engine:\n    ");
		my_puterror(MSG_MY_SFML_ERR_NULL);
		return (84);
	}
	return (engine->current_scene->audio_engine->play(\
engine->current_scene->audio_engine, id));
}

int stop_audio_main_engine(sf_engine_t *engine, const char *id)
{
	if (engine == NULL || id == NULL) {
		my_puterror("Add audio main engine:\n    ");
		my_puterror(MSG_MY_SFML_ERR_NULL);
		return (84);
	}
	return (engine->current_scene->audio_engine->stop(\
engine->current_scene->audio_engine, id));
}

int set_audio_main_engine(sf_engine_t *engine, char const *id, double volume)
{
	if (engine == NULL || id == NULL) {
		my_puterror("Add audio main engine:\n    ");
		my_puterror(MSG_MY_SFML_ERR_NULL);
		return (84);
	}
	return (engine->current_scene->audio_engine->set_volume(\
engine->current_scene->audio_engine, id, volume));
}