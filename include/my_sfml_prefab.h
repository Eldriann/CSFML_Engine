/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Prefabs gameobject
*/

#ifndef __MY_SFML_PREFAB_H_
#define __MY_SFML_PREFAB_H_

/**
** \brief Create a new button and return it
** @param engine the main engine
** @param name the name of the button
** @param textures_path the path to the texture
** @param position the position of the button
*/
gameobject_t *create_prefab_button(sf_engine_t *engine, char *name, \
char *textures_path, sfIntRect position);

int button_update(sf_button_t *button, int delta_time);

gameobject_t *create_prefab_image(sf_engine_t *engine, \
char *texture, int layer);

#endif /* !__MY_SFML_PREFAB_H_ */