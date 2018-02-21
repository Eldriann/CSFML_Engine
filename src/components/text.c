/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Text component
*/

#include "my_sfml_gameobject.h"
#include <stdlib.h>

sf_text_t *create_text(gameobject_t *parent)
{
	sf_text_t *new_text = malloc(sizeof(*new_text));

	if (new_text == NULL)
		return (NULL);
	new_text->parent = parent;
	new_text->font = NULL;
	new_text->text = sfText_create();
	new_text->destroy = &destroy_text;
	return (new_text);
}

void destroy_text(sf_text_t *text)
{
	if (text == NULL)
		return;
	if (text->font)
		sfFont_destroy(text->font);
	text->font = NULL;
	if (text->text)
		sfText_destroy(text->text);
	text->text = NULL;
	free(text);
}