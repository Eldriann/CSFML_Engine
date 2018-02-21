/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** my_strdup function
*/

/* File created the 21/02/2018 at 13:15:58 by julian.frabel@epitech.eu */

#include <stdlib.h>
#include "my_sfml_core.h"

char *my_strdup(const char *str)
{
	char *new_str = NULL;

	if (str == NULL)
		return (NULL);
	new_str = malloc(sizeof(*new_str) * (my_strlen(str) + 1));
	for (int i = 0; str[i]; i++)
		new_str[i] = str[i];
	new_str[my_strlen(str)] = '\0';
	return (new_str);
}