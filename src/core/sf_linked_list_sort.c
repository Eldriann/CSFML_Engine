/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Sort a list given a compare function
*/

#include "my.h"
#include "my_sfml_core.h"
#include <stdlib.h>

sf_linked_list_t **list_to_list_array(sf_linked_list_t *list)
{
	int list_size = my_sf_list_size(list);
	sf_linked_list_t **list_array = malloc(sizeof(*list_array) * list_size);
	sf_linked_list_t *next = list;

	if (list_array == NULL) {
		my_puterror(MSG_MY_SFML_MALLOC);
		return (NULL);
	}
	if (list == NULL) {
		free(list_array);
		my_puterror(MSG_MY_SFML_ERR_NULL);
		return (NULL);
	}
	for (int i = 0; i < list_size; i++) {
		list_array[i] = next;
		next = next->next;
	}
	return (list_array);
}

void swap_if_needed(sf_linked_list_t **elem1, sf_linked_list_t **elem2, \
int (*cmp)())
{
	sf_linked_list_t *temp = NULL;

	if ((*cmp)((*elem1)->data, (*elem2)->data) > 0) {
		temp = *elem1;
		*elem1 = *elem2;
		*elem2 = temp;
	}
}

void my_sort_sf_list(sf_linked_list_t **list, int (*cmp)())
{
	int list_size = my_sf_list_size(*list);
	sf_linked_list_t **list_array = list_to_list_array(*list);
	int i;

	for (i = 0; i < list_size; i++) {
		for (int j = 0; j < list_size - 1 - i; j++) {
			swap_if_needed(&list_array[j], &list_array[j + 1], cmp);
		}
	}
	for (i = 0; i < list_size - 1; i++) {
		list_array[i]->next = list_array[i + 1];
	}
	list_array[i]->next = NULL;
	*list = *list_array;
	free(list_array);
}