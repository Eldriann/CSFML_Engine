/*
** EPITECH PROJECT, 2017
** mysfml
** File description:
** my_strlen function
*/

/* File created the 21/02/2018 at 13:17:41 by julian.frabel@epitech.eu */

#include <stdlib.h>

int my_strlen(const char *str)
{
	int len = 0;

	if (str == NULL)
		return (0);
	for (len = 0; str[len]; len++);
	return (len);
}