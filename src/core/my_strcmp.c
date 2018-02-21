/*
** EPITECH PROJECT, 2017
** mysfml
** File description:
** my_strcmp function
*/

/* File created the 21/02/2018 at 13:47:21 by julian.frabel@epitech.eu */

#include <unistd.h>
#include "my_sfml_core.h"

int my_strcmp(char const *s1, char const *s2)
{
	int i = 0;

	for (; s1[i] != '\0' && s2[i] != '\0'; i++) {
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	if (s1[i] != '\0' || s2[i] != '\0')
		return ((s1[i] != '\0') ? s1[i] : -s2[i]);
	return (0);
}