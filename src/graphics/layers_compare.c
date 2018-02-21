/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Functions used to compare layers
*/

#include "my_sfml_core.h"
#include "my_sfml_graphics.h"

int compare_layer(void *layer_one, void *layer_two)
{
	int layer_one_priority;
	int layer_two_priority;

	if (layer_one == NULL || layer_two == NULL)
		return (0);
	layer_one_priority = ((sf_layer_t *)layer_one)->priority;
	layer_two_priority = ((sf_layer_t *)layer_two)->priority;
	if (layer_one_priority >= 0 && layer_two_priority >= 0)
		return (layer_one_priority - layer_two_priority);
	else if (layer_one_priority < 0 && layer_two_priority < 0)
		return ((-layer_two_priority) - (-layer_one_priority));
	else
		return ((layer_two_priority < 0) ? 1 : 0);
}

int layer_equals(sf_layer_t *layer, int *layer_nb)
{
	if (layer == NULL)
		return (1);
	return (layer->priority - *layer_nb);
}