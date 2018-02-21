/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Linked list functions
*/

#include "my_sfml_core.h"
#include <stdlib.h>

sf_linked_list_t *sf_push(void *data, char *id, sf_linked_list_t *list)
{
	sf_linked_list_t *new_element = malloc(sizeof(*new_element));

	if (new_element == NULL) {
		my_puterror("Push in list:\n    ");
		my_puterror(MSG_MY_SFML_MALLOC);
		return (list);
	}
	new_element->data = data;
	new_element->id = id;
	new_element->next = list;
	return (new_element);
}