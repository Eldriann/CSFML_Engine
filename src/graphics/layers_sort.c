/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Sort a layer list
*/

#include "my_sfml_core.h"
#include "my_sfml_graphics.h"
#include <stdlib.h>

void sort_layers(sf_linked_list_t **layer_list)
{
	if (layer_list == NULL || *layer_list == NULL) {
		my_puterror("Sort layer:\n    ");
		my_puterror(MSG_MY_SFML_ERR_NULL);
		return;
	}
	my_sort_sf_list(layer_list, &compare_layer);
}