/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Functions related to the audio part
*/

/**
** \file my_sfml_audio.h
** \brief Audio engine, you should not need to use this file
**
** This file is used to declare the audio engine and it's functions
*/

#ifndef __MY_SFML_AUDIO_H_
#define __MY_SFML_AUDIO_H_

#include "my_sfml_core.h"

/* --------------------------------DEFINE-------------------------------- */
/* ------------------------------END-DEFINE------------------------------ */

/* -----------------------------AUDIO-ENGINE----------------------------- */

/**
** \struct my_sfml_audio_engine
** \brief The audio engine
**
** The audio engine handle basic audio settings and can play them.
*/
struct my_sfml_audio_engine {
	sf_linked_list_t *sound_list; /**< */
	void (*destroy)(); /**< Destroy the engine and clear audio */
	int (*add_audio)(); /**< Add an audio track to the engine */
	int (*play)(); /**< Play a loaded audio track */
	int (*stop)(); /**< Stop a loaded audio track */
	int (*set_volume)(); /**< Set the volume vor a given audio track */
};

typedef struct my_sfml_audio_engine sf_audio_engine_t;

/**
** \brief Create a blank audio engine
**
** Create the audio engine.
** Return the created engine.
*/
sf_audio_engine_t *create_audio_engine(void);
/**
** \brief Destroy an audio engine
** @param engine the audio engine to destroy
**
** Destroy the audio engine and free all it's loaded tracks.
*/
void destroy_audio_engine(sf_audio_engine_t *engine);

/**
** \brief Add a track to an audio engine
** @param engine the audio engine to add to
** @param path the path to the track
** @param loop [0,1] should the track loop at it's end
**
** Add the given track to an audio engine and load it.
** Return 84 if something went wrong, 0 otherwise.
*/
int add_audio_to_engine(sf_audio_engine_t *engine, const char *path, int loop);

/**
** \brief Play a track
** @param engine the audio engine that hold the loaded track
** @param id the id of the track (it's path)
**
** Play the given track if loaded.
** Return 84 if something went wrong, 0 otherwise.
*/
int play_audio(sf_audio_engine_t *engine, const char *id);
/**
** \brief Stop a track
** @param engine the audio engine that hold the loaded track
** @param id the id of the track (it's path)
**
** Stop the given track if loaded.
** Return 84 if something went wrong, 0 otherwise.
*/
int stop_audio(sf_audio_engine_t *engine, const char *id);

/**
** \brief Set the volume of a track
** @param engine the audio engine that hold the loaded track
** @param id the id of the track (it's path)
** @param volume the new volume of the track
**
** Set the volume of the given track if loaded.
** Return 84 if something went wrong, 0 otherwise.
*/
int set_audio_volume(sf_audio_engine_t *engine, char const *id, double volume);

/* ------------------------------END-ENGINE------------------------------ */

#endif /* __MY_SFML_AUDIO_H_ */