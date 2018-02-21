/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Return the size of the list
*/

#include "my_sfml_core.h"
#include <stdlib.h>

int my_sf_list_size(sf_linked_list_t const *begin)
{
	int i = 0;
	sf_linked_list_t *next = (sf_linked_list_t *)begin;

	for (i = 0; next != NULL; i++) {
		next = next->next;
	}
	return (i);
}