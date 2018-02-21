/*
** EPITECH PROJECT, 2017
** mysfml
** File description:
** put an error str
*/

/* File created the 21/02/2018 at 13:25:00 by julian.frabel@epitech.eu */

#include <unistd.h>
#include "my_sfml_core.h"

int my_putdebug(const char *debug)
{
	if (DEBUG_MSG_ACTIVE)
		return (write(2, debug, my_strlen(debug)));
	return (0);
}