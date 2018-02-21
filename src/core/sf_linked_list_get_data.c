/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Get data from a linked list
*/

#include "my.h"
#include "my_sfml_core.h"
#include <stdlib.h>

void *get_data_from_node(sf_linked_list_t *list, void *comp, int (*cmp)())
{
	int list_size = 0;

	if (list == NULL || comp == NULL || cmp == NULL) {
		my_puterror("Get data from comp:\n    ");
		my_puterror(MSG_MY_SFML_ERR_NULL);
		return (NULL);
	}
	list_size = my_sf_list_size(list);
	for (int i = 0; i < list_size; i++) {
		if ((*cmp)(list->data, comp) == 0)
			return (list->data);
		list = list->next;
	}
	my_puterror(MSG_MY_SFML_DATA_NOT_FOUND);
	return (NULL);
}

void *get_data(char const *id, sf_linked_list_t *list)
{
	if (id == NULL || list == NULL) {
		my_puterror("Get data from id:\n    ");
		my_puterror(MSG_MY_SFML_ERR_NULL);
		return (NULL);
	}
	while (list != NULL) {
		if (my_strcmp(id, list->id) == 0)
			return (list->data);
		list = list->next;
	}
	my_puterror(MSG_MY_SFML_DATA_NOT_FOUND);
	return (NULL);
}

void **get_data_array(char const *id, sf_linked_list_t *list)
{
	int nb_elements = 0;
	void **return_array = NULL;
	sf_linked_list_t *list_cpy = list;

	if (id == NULL || list == NULL)
		return (NULL);
	for (; list != NULL; list = list->next)
		if (my_strcmp(id, list->id) == 0)
			nb_elements++;
	return_array = malloc(sizeof(*return_array) * (nb_elements + 1));
	if (return_array == NULL)
		return (NULL);
	for (int i = 0; list_cpy; list_cpy = list_cpy->next) {
		if (my_strcmp(id, list_cpy->id) == 0) {
			return_array[i] = list_cpy->data;
			i++;
		}
		return_array[i] = NULL;
	}
	return (return_array);
}