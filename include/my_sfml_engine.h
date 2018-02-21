/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Main engine
*/

/**
** \file my_sfml_engine.h
** \brief Main engine
**
** Main engine and it's functions.
*/

/**
** \mainpage mysfml engine
** \section engine_sec Engine
** \subsection intro_sec Introduction
** The \ref main_engine is the only engine you should use directly.
** All of the sub engines are run by the main engine.
** \section gameobject_sec Gameobjects
** \subsection intro_sec Introduction
** \ref my_sfml_gameobject are the core of a game.
** They represent all elements in a \ref scene.
** Refer to the \ref main_engine to know how to register one.
** A gameobject consist of a set of one or more \ref my_sfml_component.
** \subsection component_sec Components
** Components are small amount of data that serve for one job.
** Some are already builtin the engine like:
** \ref my_sfml_transform , \ref my_sfml_animation_2d ,\
** \ref my_sfml_collider_2d , \ref my_sfml_rigidbody_2d , \ref my_sfml_text ,\
**  \ref my_sfml_button [WIP].
** Other can be created as you need if you respect the norm given by
** \ref my_sfml_component
** \section owner_sec Owner
** This engine was created by Julian Fräbel on top of the CSFML library.
** It was created for the Graphical module of Epitech.
*/

#ifndef __MY_SFML_ENGINE_H_
#define __MY_SFML_ENGINE_H_

#include "my_sfml_scenes.h"
#include <SFML/Graphics.h>

/* --------------------------------DEFINE-------------------------------- */
/* ------------------------------END-DEFINE------------------------------ */

/* --------------------------------ENGINE-------------------------------- */

/**
** \struct main_engine
** \brief main engine
**
** Struct representing the main engine, handle the scenes and it's functions.
*/
struct main_engine {
	sfRenderWindow *window; /**< Window used by the engine */
	sfClock *main_clock;
	sf_scene_t *current_scene; /**< Current playing scene */
	char *next_scene; /**< Next scene name to be loaded */
	void *data; /**< The data to give to the next scene */
	sf_linked_list_t *scenes; /**< List of existing scenes */
	void (*destroy)(struct main_engine *engine);\
/**< destroy the engine. Refer to destroy_engine() */
	void (*update)(struct main_engine *engine);\
/**< run all the updaters in current scene. Refer to update_main_engine() */
	int (*add_update)(struct main_engine *engine, void *object, \
int (*update)(void *object, int delta_time));\
/**< Register an updater to the current scene. \
Refer to add_update_main_engine() */
	int (*remove_update)(struct main_engine *engine, void *object);\
/**< Unregister an updater from the current scene. Refer to remove_update() */
	int (*add_gameobject)(struct main_engine *engine, gameobject_t *obj);\
/**< Register a gameobject to the current scene. Refer to add_gameobject() */
	int (*remove_gameobject)(struct main_engine *engine, \
gameobject_t *obj); /**< Unregister a gameobject from the current \
scene and destroy it. Best use destroy_gameobject to clean updaters/renderer.\
Refer to remove_gameobject() */
	int (*destroy_gameobject)(struct main_engine *engine, \
gameobject_t *obj); /**< Destroy a gameobject by doing some cleaning \
on the updaters/renderer. Refer to destroy_gameobject_main_engine() */
	int (*render)(struct main_engine *engine);\
/**< Render the current frame to the window. Refer to render_main_engine() */
	int (*add_to_layer)(struct main_engine *engine, int layer, \
void **data);/**< Add data to a render layer. Refer to \
add_to_layer_main_engine() */
	int (*remove_from_layers)(struct main_engine *engine, void **object);\
/**< Remove an object added to a layer from all the layers he is in \
refer to remove_from_layers_main_engine()*/
	int (*set_layer_type)(struct main_engine *engine, int priority, \
layer_render_type_t new_type); /**< Set the type of the asked layer to \
new_type. Refer to main_engine_set_layer_type() */
	int (*load_texture)(struct main_engine *engine, const char *path);\
/**< Load a texture to the current render engine. \
Refer to load_texture_main_engine() */
	int (*add_audio)(struct main_engine *engine, \
const char *path, int loop); /**< Add audio to the current audio engine. \
Refer to add_audio_main_engine() */
	int (*play)(struct main_engine *engine, const char *id);\
/**< Play an audio track. Refer to play_audio_main_engine() */
	int (*stop)(struct main_engine *engine, const char *id);\
/**< Stop an audio track. Refer to stop_audio_main_engine() */
	int (*set_volume)(struct main_engine *engine, const char *id, \
double volume); /**< Set volume of a track. Refer to set_audio_main_engine() */
	int (*add_scene)(struct main_engine *engine, sf_scene_t *scene);\
/**< Add a scene to the main engine. Refer to add_scene() */
	int (*change_scene)(struct main_engine *engine, \
const char *name, void *data); /**< Change the current scene. \
Refer to change_scene() */
	int (*add_physic_object)(struct main_engine *engine, \
gameobject_t *object); /**< Add an object to the current physic engine. \
Refer to add_physic_object_main_engine() */
	int (*remove_physic_object)(struct main_engine *engine, \
gameobject_t *object); /**< Remove an object from the current physic engine. \
Refer to remove_physic_object_main_engine() */
	gameobject_t **(*get_collisions_rect)(\
struct main_engine *engine, sfIntRect rect, int *size_buff, void *ignore);\
/**< Get an array of gameobjects colliding with the given rect. \
Refer to get_collisions_rect_main_engine() */
	gameobject_t **(*get_collisions_point)(\
struct main_engine *engine, vector_t point, int *size_buff);\
/**< Get an array of gameobjects colliding with the given point. \
Refer to get_collisions_point_main_engine() */
	gameobject_t **(*get_collisions_go)(\
struct main_engine *engine, gameobject_t *obj, int *size_buff);\
/**< Get an array of gameobjects colliding with the given gamobject. \
Refer to get_collisions_go_main_engine() */
	gameobject_t *(*get_gameobject)(struct main_engine *engine, \
const char *name); /**< Get a gameobject given it's name. \
Refer to get_gameobject() */
	void (*initialize_physic_state)(struct main_engine *engine);\
/**< Initialise a physic state (register updaters). \
Refer to initialize_physic_state() */
	sfTexture *(*get_texture)(struct main_engine *engine, const char *id);\
/**< Get a loaded texture given the texture id (path). \
Refer to get_texture_main_engine() */
	sfSprite *(*get_sprite)(struct main_engine *engine, const char *id);\
/**< Get an allocated sprite with the correct texture given the texture id. \
Refer to get_sprite() */
	sf_scene_t *(*get_scene)(struct main_engine *engine, const char *name);\
/**< Get a scene based on it's name. Refer to get_scene() */
};

typedef struct main_engine sf_engine_t;

/**
** \brief Create a new engine
** @param window the window assotiated with this engine
**
** Return the new engine.
*/
sf_engine_t *create_engine(sfRenderWindow *window);
/**
** \brief Destroy the given engine
** @param engine the engine to destroy
**
** Destroy the given engine and handle all the frees.
*/
void destroy_engine(sf_engine_t *engine);

/**
** \brief Add an updater to the current scene
** @param engine the engine to add to
** @param object the object to give to the updater
** @param update the update function of the updater
**
** Add an updater that run update with the given object and the time passed.
** Return 84 in case of an error, 0 otherwise.
*/
int add_update_main_engine(sf_engine_t * engine, void *object, \
int (*update)(void *object, int time));
/**
** \brief Remove an updater
** @param engine the engine to remove from
** @param object the object to unregister
**
** Remove all the updaters linked to the given object.
** Return 84 in case of an error, 0 otherwise.
*/
int remove_update(sf_engine_t *engine, void *object);
/**
** \brief Run all the updaters of the current scene
** @param engine the engine to update
** @param time the time passed since the last call of update (sfClock_restart)
**
** Run all the updaters of the given engine current loaded scene.
*/
void update_main_engine(sf_engine_t *engine);

/**
** \brief Add gameobject to the current scene
** @param engine the engine to add too
** @param object the object to register
**
** Add the given object to the main engine so that it handle it's destruction.
** Added object allowed also to find them by name.
** Object added will be added to the current scene only but will be destroy\
when the engine will be destroyed careless of the current scene.
** Return 84 in case of an error, 0 otherwise.
*/
int add_gameobject(sf_engine_t *engine, gameobject_t *object);
/**
** \brief Remove an object from the main engine
** @param engine the engine to update
** @param object the gameobject to remove from the engine.
**
** Remove the given object from the engin handeling.
** The given object will be destroyed after beeing removed.
** Return 84 in case of an error, 0 otherwise.
*/
int remove_gameobject(sf_engine_t *engine, gameobject_t *object);
/**
** \brief Destroy an object from the engines
** @param engine the engine to update
** @param object the gameobject to destroy from the engine.
**
** Remove the given object from the engin handeling, will also try \
to destroy all updaters/physics upaters/renderer.
** It will clean base on the components and will remove sprite from \
animation2d/text from sf_text but more specifics componenets like custom \
sprites will not be handeled and need to be removed manually.
** If updaters are created base on variables in a component they need \
to be handeled manually too
** The given object will be destroyed after all cleaning.
** Return 84 in case of an error, 0 otherwise.
*/
int destroy_gameobject_main_engine(sf_engine_t *engine, gameobject_t *obj);

/**
** \brief Render a frame to the engine window
** @param engine the engine to render
**
** Render the current frame of the engine to the engine window.
** Return 84 in case of an error, 0 otherwise.
*/
int render_main_engine(sf_engine_t *engine);
/**
** \brief Add the given data to the render list of the current graphical engine
** @param engine the engine to add to
** @param layer the layer priority, you can use the layer enum for easy priority
** @param data a the adress of the data to add to the render list
**
** Add the given data to the render list, take as data sfSprite or sfText.
** sfText can only be added on the layers that have been marked to render text\
or errors can occure.
** Return 84 in case of an error, 0 otherwise.
*/
int add_to_layer_main_engine(sf_engine_t *engine, int layer, void **data);
/**
** \brief Remove the data to the render list of the current graphical engine
** @param engine the engine to add to
** @param data a the adress of the data to add to the render list
**
** Remove the given data to the render list, take as data sfSprite or sfText.
** Return 84 in case of an error, 0 otherwise.
*/
int remove_from_layers_main_engine(sf_engine_t *engine, void **data);
/**
** \brief Set a layer render type
** @param engine the engine to serach in
** @param priority the searched layer
** @param new_type the new render type of the layer
**
** Function that changed the render type of the requested layer to new_type.
** Return 84 in case of an error, 0 otherwise.
*/
int main_engine_set_layer_type(sf_engine_t *engine, int priority, \
layer_render_type_t new_type);
/**
** \brief Load a texture on the current graphical engine
** @param engine the engine to load to
**
** Render the current frame of the engine to the engine window.
** Return 84 in case of an error, 0 otherwise.
*/
int load_texture_main_engine(sf_engine_t *engine, const char *path);
/**
** \brief Get a loaded texture given it's id
** @param engine the engine to search in
** @param id the texture id (path)
**
** Get a previously loaded texture (with load_texture_main_engine).
** Return NULL in case of an error, the texture asked otherwise.
*/
sfTexture *get_texture_main_engine(sf_engine_t *engine, const char *id);

/**
** \brief Add an audio track to the current audio engine
** @param engine the engine to add to
** @param path the path to the audio engine (will also be it's id)
** @param loop [0,1] should the track loop when finished (for music mainly)
**
** Add the track to the current audio engine.
** Return 84 in case of an error, 0 otherwise.
*/
int add_audio_main_engine(sf_engine_t *engine, const char *path, int loop);
/**
** \brief Play an audio track
** @param engine the engine to search the audio from
** @param id the audio track id (path)
**
** Play the asked track if loaded in the current scene.
** Return 84 in case of an error, 0 otherwise.
*/
int play_audio_main_engine(sf_engine_t *engine, const char *id);
/**
** \brief Stop an audio track
** @param engine the engine to search the audio from
** @param id the audio track id (path)
**
** Stop the asked track from beeing played.
** Return 84 in case of an error, 0 otherwise.
*/
int stop_audio_main_engine(sf_engine_t *engine, const char *id);
/**
** \brief Set the volume for a given audio track
** @param engine the engine to search the audio from
** @param id the audio track id (path)
** @param volume the volume to set the track to
**
** If the current track exist in the curretn scene will set it's volume.
** Return 84 in case of an error, 0 otherwise.
*/
int set_audio_main_engine(sf_engine_t *engine, const char *id, double volume);

/**
** \brief Get a gameobject from the current scene given it's name
** @param engine the engine to seach the object from
** @param name the name of the gameobject
**
** Get the first gameobject in the current scene to match the asked name.
** Return NULL in case of an error, the asked gameobject otherwise.
*/
gameobject_t *get_gameobject(sf_engine_t *engine, const char *name);

/**
** \brief Get a new sprite with the asked texture
** @param engine the engine to search the texture from
** @param id the texture id (path)
**
** Get a newly allocated texture with the requireded texture loaded.
** If the texture wasn't found the sprite will be return with a NULL texture.
** [WIP]Try to load the texture from path if not found.
** Return NULL in case of an error, a sfSprite otherwise.
*/
sfSprite *get_sprite(sf_engine_t *engine, char const *id);

/**
** \brief Add a scene to the main engine
** @param engine the engine to add to
** @param scene the scene to be added
**
** Add a scene to the main engine that can be run.
** Return 84 in case of an error, 0 otherwise.
*/
int add_scene(sf_engine_t *engine, sf_scene_t *scene);
/**
** \brief Get the first scene in the engine to have the given name
** @param engine the engine to search from
** @param name the name of the researched scene
**
** Get the first scene in the engine to have this name.
** Return NULL in case of an error or if scene wasn't found, scene otherwise.
*/
sf_scene_t *get_scene(sf_engine_t *engine, const char *name);
/**
** \brief Change the current scene
** @param engine the engine to search the scene from
** @param name the name of the scene to change to
** @param data the data to transfer to the next scene
**
** Change the current scene of the engine.
** Data can be what you like it will be passed from a scene to an other.
** This function will call the current scene unload() function.
** This function will call the new scene load() function.
** If the new scene does not exist the scene won't change.
** Return 84 in case of an error, 0 otherwise.
*/
int change_scene(sf_engine_t *engine, const char *name, void *data);
/**
** \brief DO NOT USE
**
** do the actual scene changement.
*/
int update_selected_scene(sf_engine_t *engine);

/**
** \brief Add a physic object to the current physic engine
** @param engine the engine to add to
** @param object the gameobject to add to physics update
**
** Add a gameobject to the physic engine so that it's physics component work.
** Will then handle collisions, triggers, gravity...
** The gameobject require a transform, a rigidbody and a collider to be added.
** Return 84 in case of an error, 0 otherwise.
*/
int add_physic_object_main_engine(sf_engine_t *engine, gameobject_t *object);
/**
** \brief Remove a physic object to the current physic engine
** @param engine the engine to remove from
** @param object the gameobject to remove from physics update
**
** Remove a gameobject to the physic engine.
** Will no longer handle collisions, triggers, gravity...
** Return 84 in case of an error, 0 otherwise.
*/
int remove_physic_object_main_engine(sf_engine_t *engine, gameobject_t *object);
/**
** \brief Get all the collisions with a given rect
** @param engine the engine to detect from
** @param rect the rect to search collisions from
** @param size_buff the buffer with the number of collisions detected
** @param ignore a gameobject to ignore in the detection
**
** Get all the gameobject colliding with the given rect.
** Will set *size_buff to the number of collisions found.
** Return NULL in case of an error, an array of gameobjects otherwise.
*/
gameobject_t **get_collisions_rect_main_engine(sf_engine_t *engine, \
sfIntRect rect, int *size_buff, void *ignore);
/**
** \brief Get all the collisions with a given point
** @param engine the engine to detect from
** @param point the point to search collisions from
** @param size_buff the buffer with the number of collisions detected
**
** Get all the gameobject colliding with the given point.
** Will set *size_buff to the number of collisions found.
** Return NULL in case of an error, an array of gameobjects otherwise.
*/
gameobject_t **get_collisions_point_main_engine(sf_engine_t *engine, \
vector_t point, int *size_buff);
/**
** \brief Get all the collisions with a given gameobject
** @param engine the engine to detect from
** @param obj the gameobject to search collisions from
** @param size_buff the buffer with the number of collisions detected
**
** Get all the gameobject colliding with the given gameobject.
** The given gameobject will not be count as colliding with himself.
** Will set *size_buff to the number of collisions found.
** Return NULL in case of an error, an array of gameobjects otherwise.
*/
gameobject_t **get_collisions_go_main_engine(sf_engine_t *engine, \
gameobject_t *obj, int *size_buff);
/**
** \brief Function that initialize physic state
** @param engine the engine to initialize the current scene physics
**
** This function link the physics update from the current scene \
to the main engine updaters.
** You need to run this function only ONCE per scene or the physics of the \
scene will be multiplied each time you run it.
** You still need to rerun this function after a reset_scene() call.
*/
void initialize_physic_state(sf_engine_t *engine);

/* ------------------------------END-ENGINE------------------------------ */

/**
** \brief Render all hitbox from the given engine
** @param engine the engine to render the hitbox from
**
** Render the current scene hitbox to the engine window.
** Function should be called after render_main_engine or the texture will not \
appear on screen as they will be drawn under the scene.
** the hitbox texture should be 1 pixel by 1 pixel and should be found in \
the HITBOX_TEX folder.
** the hitbox texture should have been previously loaded in the current scene.
** SHOULD ONLY BE USED FOR DEBUGING AS IT CAUSES FLICKERING!
** Return 84 in case of an error, 0 otherwise.
*/
int display_hitbox(sf_engine_t *engine);

#endif /* __MY_SFML_ENGINE_H_ */