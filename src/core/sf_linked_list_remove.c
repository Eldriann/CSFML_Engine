/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Remove data from a list
*/

#include "my_sfml_core.h"
#include <stdlib.h>

sf_linked_list_t *del_element(sf_linked_list_t *last, sf_linked_list_t *curr, \
sf_linked_list_t *next, sf_linked_list_t **list)
{
	if (last) {
		last->next = next;
		free(curr->id);
		free(curr);
		return (last);
	} else {
		*list = next;
		free(curr->id);
		free(curr);
		return (NULL);
	}
}

void sf_remove(char *id, sf_linked_list_t **list)
{
	sf_linked_list_t *last = NULL;
	sf_linked_list_t *curr = NULL;
	sf_linked_list_t *next = NULL;

	if (id == NULL || list == NULL || *list == NULL) {
		my_puterror("Remove from list:\n    ");
		my_puterror(MSG_MY_SFML_ERR_NULL);
		return;
	}
	curr = *list;
	next = curr->next;
	for (int i = 0; curr != NULL; i++) {
		if (my_strcmp(id, curr->id) == 0)
			curr = del_element(last, curr, next, list);
		last = curr;
		curr = next;
		if (next != NULL)
			next = curr->next;
	}
}

void sf_remove_node(sf_linked_list_t *node, sf_linked_list_t **list)
{
	sf_linked_list_t *last = NULL;
	sf_linked_list_t *curr = NULL;
	sf_linked_list_t *next = NULL;

	if (node == NULL || list == NULL || *list == NULL) {
		my_puterror("Remove from list:\n    ");
		my_puterror(MSG_MY_SFML_ERR_NULL);
		return;
	}
	curr = *list;
	next = curr->next;
	for (int i = 0; curr != NULL; i++) {
		if (node == curr)
			curr = del_element(last, curr, next, list);
		last = curr;
		curr = next;
		if (next != NULL)
			next = curr->next;
	}
}