/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Header for gameobjects
*/

/**
** \file my_sfml_gameobject.h
** \brief Header file containing the gameobject struct and basic components
*/

#ifndef __MY_SFML_GAMEOBJECT_H_
#define __MY_SFML_GAMEOBJECT_H_

#include "my_sfml_core.h"
#include <SFML/Graphics.h>

/* --------------------------------DEFINE-------------------------------- */
/* ------------------------------END-DEFINE------------------------------ */

/* ------------------------------GAMEOBJECT------------------------------ */

/**
** \enum go_component
** \brief a struct used to identify a component easely in code
** if you define your own component use the default value of an enum as the \
5 biggest value of a int are reserved for builtin engine component.
*/
enum go_component {
	TRANSFORM = 2147483646,
	ANIMATION_2D = 2147483645,
	COLLIDER_2D = 2147483644,
	RIGIDBODY_2D = 2147483643,
	TEXT = 2147483642,
	BUTTON = 2147483641
};

typedef enum go_component go_component_t;

/**
** \struct my_sfml_gameobject
** \brief base struct for everything in the engine
** This structure contains a list of component.
** To add a builtin component run add_component().
** To add your own custom component run add_custom_component().
*/
struct my_sfml_gameobject {
	char *id; /**< The unique id of the gameobject */
	char *name; /**< A name describing the gameobject */
	sf_linked_list_t *components; /**< A list with all the obj component */
	void (*destroy)(struct my_sfml_gameobject *go); /**< Destroy function. \
Refer to destroy_gameobject() */
	void *(*add_component)(struct my_sfml_gameobject *go, \
go_component_t type); /**< Function to add a builtin component. \
Refer to add_component() */
	void *(*add_custom_component)(struct my_sfml_gameobject *go, \
void *(*create_func)(struct my_sfml_gameobject *parent), \
int custom_type); /**< Function to add custom component. \
Refer to add_custom_component() */
};

typedef struct my_sfml_gameobject gameobject_t;

/**
** \brief Create a new empty gameobject
** @param name the name to give to the gameobject
**
** Create a new gameobject with no components.
** Return NULL in case of error, the new gameobject otherwise.
*/
gameobject_t *create_gameobject(char const *name);
/**
** \brief Destroy a given gameobject
** @param go the gamobject to destroy
**
** This function will destroy the given gameobject and all it's components.
*/
void destroy_gameobject(gameobject_t *go);
/**
** \brief Add a builtin component to the gameobject
** @param go the gameobject to add the component to
** @param type the id of the builtin component defined in the go_component enum
**
** This will add the requested component to the given object
** If the gameobject already have this component type it will return it \
and not add a new component.
** This function will return the added component (NULL in case of an error)
*/
void *add_component(gameobject_t *go, go_component_t type);
/**
** \brief Add a custom component to the gameobject
** @param go the gameobject to add the component to
** @param create_func the function creating the component and returning it
** @param custom_type the id of the custom component
**
** This function add the component returned by create_func to the \
gameobject and link it with the custom type id.
** It is recomanded to create a custom_component_type enum.
** If the gameobject already have this component type it will return it \
and not add a new component.
** A custom component should always start with a destroy function \
and a pointer to it's parent: see my_sfml_component.
** This function will return the added component (NULL in case of an error)
*/
void *add_custom_component(gameobject_t *go, \
void *(*create_func)(gameobject_t *parent), int custom_type);
/**
** \brief Get a component from a gameobject
** @param go the gameobject to get the component from
** @param type the id of the component to get
**
** This function get the asked component from a given object.
** This function will return the asked component if found or NULL in case of \
an error or if the object does not have this component.
*/
void *get_component(gameobject_t *go, int type);

/* ----------------------------END-GAMEOBJECT---------------------------- */

/* ------------------------------COMPONENTS------------------------------ */

/**
** \struct my_sfml_component
** \brief struct used only for casting a component
** All component should start like this struct
*/
struct my_sfml_component {
	void (*destroy)(); /**< destroy function of the component */
	gameobject_t *parent; /**< parent gameobject */
};

typedef struct my_sfml_component component_cast_t;

/* ----------------------------END-COMPONENTS---------------------------- */

/* ------------------------------TRANSFORMS------------------------------ */

/**
** \struct my_sfml_transform
** \brief Component representing the transform of the gamobject
** This component is used by the physic engine to handle position calculation.
*/
struct my_sfml_transform {
	void (*destroy)(); /**< destroy function. Refer to destroy_transform()*/
	gameobject_t *parent; /**< parent of the transform */
	vector_t position; /**< Position of the gameobject in the world */
	vector_t rotation; /**< Rotation of the gamobject */
	vector_t scale; /**< Scale if the gameobject */
	int (*move)(); /**< Change the position of the transform. \
Refer to default_move_transform() */
	int (*rotate)(); /**< Change the rotation of the transform. \
Refer to default_rotate_transform() */
	int (*resize)(); /**< Change the scale of the transform. \
Refer to default_resize_transform() */
};

typedef struct my_sfml_transform sf_transform_t;

/**
** \brief function that create a transform component
** @param parent the parent gameobject
**
** Return the new transform or NULL in case of an error.
*/
sf_transform_t *create_transform(gameobject_t *parent);
/**
** \brief destroy the transform given
** @param transform the transform to be destroyed.
*/
void destroy_transform(sf_transform_t *transform);

/**
** \brief Default move function
** @param transform the transform to move
** @param movement the movement to apply on the transform
**
** This function will add the movement to the transform.
** Return 84 in case of an error, 0 otherwise.
*/
int default_move_transform(sf_transform_t *transform, vector_t movement);
/**
** \brief Default rotate function
** @param transform the transform to rotate
** @param rotation the rotation to apply on the transform
**
** This function will add the rotation to the transform.
** Return 84 in case of an error, 0 otherwise.
*/
int default_rotate_transform(sf_transform_t *transform, vector_t rotation);
/**
** \brief Default resize function
** @param transform the transform to move
** @param scale the scale to apply on the transform
**
** This function will add the scale to the transform.
** Return 84 in case of an error, 0 otherwise.
*/
int default_resize_transform(sf_transform_t *transform, vector_t scale);

/* ----------------------------END-TRANSFORMS---------------------------- */

/* -----------------------------ANIMATION_2D----------------------------- */

/**
** \struct my_sfml_animation_2d
** \brief Component representing the graphics of a 2d object
** This component will update it's graphics based on the update function.
*/
struct my_sfml_animation_2d {
	void (*destroy)(); /**< Destroy function. \
Refer to destroy_animation_2d() */
	gameobject_t *parent; /**< Parent of the animation */
	sfSprite *sprite; /**< The sprite of the gameobject */
	sfIntRect view_rect; /**< The view rect of the texture */
	sfIntRect max_rect; /**< The maximum and minimum position of view_rect*/
	float speed; /**< The time between to frames */
	float timer; /**< The current elapsed time since last frame */
	int (*set_sprite)(struct my_sfml_animation_2d *animation, \
sfSprite *sprite); /**< Set the animation sprite. \
Refer to set_sprite_animation_2d() */
	int (*update)(struct my_sfml_animation_2d *animation, int delta_time); \
/**< Function that update the animation.Refer to default_update_animation_2d()*/
};

typedef struct my_sfml_animation_2d sf_animation_2d_t;

/**
** \brief Create a new animation
** @param parent the parent of the animation
**
** This function will return a new animation.
** Return NULL in case of an error, the new transform otherwise.
*/
sf_animation_2d_t *create_animation_2d(gameobject_t *parent);
/**
** \brief Destroy an animation
** @param animation the animation to destroy
**
** This function will destroy an animation and it's sprite.
** Return NULL in case of an error, the new transform otherwise.
*/
void destroy_animation_2d(sf_animation_2d_t *animation);

/**
** \brief Default update animation that does nothing but print the time
** @param animation the animation to update
** @param delta_time the elapsed time since last update
**
** This function will do nothing but print the elapsed time.
** Return 84 in case of an error, 0 otherwise.
*/
int default_update_animation(sf_animation_2d_t *animation, int delta_time);
/**
** \brief Set the sprite of the given animation
** @param animation the animation to set the sprite to
** @param sprite the new sprite of the animation
**
** This function will set the new sprite to the animation and destroy last.
** Return 84 in case of an error, 0 otherwise.
*/
int set_sprite_animation_2d(sf_animation_2d_t *animation, sfSprite *sprite);

/* ---------------------------END-ANIMATION_2D--------------------------- */

/* -----------------------------COLLIDER_2D------------------------------ */

/**
** \struct my_sfml_collider_2d
** \brief Struct representing the collider/hitbox of the gameobject
** If trigger is enable on collision triggered_func() will be automaticaly run.
*/
struct my_sfml_collider_2d {
	void (*destroy)(); /**< Destroy func. Refer to destroy_collider_2d()*/
	gameobject_t *parent; /**< Parent of the collider */
	sfIntRect hitbox; /**< Hitbox of the gameobject */
	int collides; /**< Should the object collide in the physics engine */
	int layer; /**< The layer the object collide on 0:all other:specific */
	int trigger; /**< [0,1] Is the collider a trigger. If checked will run \
the triggered_func when detecting a collision */
	int (*triggered_func)(); /**< Function run when a gameobject \
collide with this collider. */
};

typedef struct my_sfml_collider_2d sf_collider_2d_t;

/**
** \brief Create a 2D collider
** @param parent parent of the collider to be created
**
** This function will return a new collider without trigger or trigger function.
** Return NULL in case of error, the new collider otherwise.
*/
sf_collider_2d_t *create_collider_2d(gameobject_t *parent);
/**
** \brief Destroy a 2D collider
** @param collider the collider to destroy
**
** This function will destroy a 2D collider.
*/
void destroy_collider_2d(sf_collider_2d_t *collider);

/**
** \brief Return if two gameobject collides
** @param go_1 the first gameobject
** @param go_2 the second gameobject
**
** Return 1 if there is collision, 0 otherwise.
*/
int does_gameobjects_collide(gameobject_t *go_1, gameobject_t *go_2);
/**
** \brief Return if a gameobject collide with a given point
** @param go the gameobject
** @param point the point to compare with
**
** Return 1 if there is collision, 0 otherwise.
*/
int does_point_collide(gameobject_t *go, vector_t point);
/**
** \brief Return if a gameobject collide with a given rect
** @param go the gameobject
** @param rectangle the rectangle to compare with
**
** Return 1 if there is collision, 0 otherwise.
*/
int does_rectangle_collide(gameobject_t *go, sfIntRect rectangle);

int default_trigger_function(gameobject_t *go, gameobject_t *go_collider);

/* ---------------------------END-COLLIDER_2D---------------------------- */

/* -----------------------------RIDIGBODY_2D----------------------------- */

/**
** \struct my_sfml_rigidbody_2d
** \brief Struct representing the physic body of a gameobject
**
** This struct is used for physics calculation by the physic engine.
*/
struct my_sfml_rigidbody_2d {
	void (*destroy)(); /**< Refer to destroy_rigidbody_2d() */
	gameobject_t *parent; /**< Parent of the rigidbody */
	int is_static; /**< [0,1] if is static no physics calculations will be \
performed on the gameobject but collisions and trigger will still work */
	vector_t charge; /**< Vector that can be used as temporary variable \
for acceleration or speed (jumping for exemple) */
	vector_t acceleration; /**< Acceleration vector of the gameobject */
	vector_t speed; /**< Speed vector of the gameobject */
	float mass; /**< Mass of the gameobject \
(currently not used in physics calculations) */
};

typedef struct my_sfml_rigidbody_2d sf_rigidbody_2d_t;

/**
** \brief Function that create a new rigidbody
** @param parent parent gameobject of the rigidbody
**
** Return NULL if an error occured, the new rigidbody otherwise.
*/
sf_rigidbody_2d_t *create_rigidbody_2d(gameobject_t *parent);
/**
** \brief Function that destroy a rigidbody
** @param rigidbody the rigidbody to destroy
**
** Destroy a given rigidbody and free all it's components.
*/
void destroy_rigidbody_2d(sf_rigidbody_2d_t *rigidbody);

/* ---------------------------END-RIDIGBODY_2D--------------------------- */

/* --------------------------------TEXT---------------------------------- */

/**
** \struct my_sfml_text
** \brief Text component used to display text on screen
**
** You need to set a font manually when creating a new sf_text_t.
** [WIP]Default font loading.
** You will not have to free the font as it will be handle by destroy().
*/
struct my_sfml_text {
	void (*destroy)(); /**< Refer to destroy_text() */
	gameobject_t *parent; /**< parent gameobject of the text */
	sfFont *font; /**< font used by the rendering engine ofr this text */
	sfText *text; /**< text object */
};

typedef struct my_sfml_text sf_text_t;

/**
** \brief Create a new text component and return it
** @param parent the parent of the new component
**
** Return NULL if an error occured, the new text otherwise.
*/
sf_text_t *create_text(gameobject_t *parent);
/**
** \brief Function that destroy a text
** @param text the text component to destroy
**
** Destroy the text component and it's sfFont/sfText if any.
*/
void destroy_text(sf_text_t *text);

/* ------------------------------END-TEXT-------------------------------- */

/* -------------------------------BUTTON--------------------------------- */

/**
** \struct my_sfml_button
** \brief component used by the button prefab (WIP)
*/
struct my_sfml_button {
	void (*destroy)(); /**< Refer to destroy_button() */
	gameobject_t *parent; /**< Parent of the component */
	sfSprite *curr_sprite; /**< Current rendered sprite */
	sfSprite *sprites[4]; /**< Sprites of the button NULL \
terminated [default, hovered, clicked] */
	sfIntRect position; /**< Position and size of the button */
	int state; /**< Used by the engine to know the state */
	struct main_engine *engine; /**< Main engine used for callback */
	void (*on_clicked)(struct my_sfml_button *button); /**< Function run \
when the button is clicked. \
Refer to default_button_clicked() as default. */
	void (*on_mouse_enter)(struct my_sfml_button *button); /**< Function \
run when the button is hovered.\
Refer to default_button_mouse_enter() as default. */
	void (*on_mouse_exit)(struct my_sfml_button *button); /**< Function \
run when the button is not \
hovered anymore. Refer to default_button_mouse_exit() as default. */
};

typedef struct my_sfml_button sf_button_t;

/**
** \brief Create and return a new button component
** @param parent the parent of the button
**
** Return NULL if an error occured, the new button component otherwise.
*/
sf_button_t *create_button(gameobject_t *parent);
/**
** \brief Destroy a button component
** @param button the button to destroy
**
** Destroy a button component and it's components.
*/
void destroy_button(sf_button_t *button);

/**
** \brief Default function run when the attached gameobject is clicked.
** @param button the button that was clicked
**
** This default function is run when the button is clicked.
*/
void default_button_clicked(sf_button_t *button);
/**
** \brief Default function run when the attached gameobject is hovered.
** @param button the button that was hovered
**
** This default function is run when the button is hovered.
*/
void default_button_mouse_enter(sf_button_t *button);
/**
** \brief Default function run when the attached gameobject is not hovered.
** @param button the button that was not hovered anymore
**
** This default function is run when the button is not hovered anymore.
*/
void default_button_mouse_exit(sf_button_t *button);

/* -----------------------------END-BUTTON------------------------------- */

#endif /* __MY_SFML_GAMEOBJECT_H_ */