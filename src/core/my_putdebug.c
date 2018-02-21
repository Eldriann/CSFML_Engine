/*
** EPITECH PROJECT, 2017
** mysfml
** File description:
** put an error str
*/

/* File created the 21/02/2018 at 13:25:00 by julian.frabel@epitech.eu */

#include <stdio.h>
#include "my_sfml_core.h"

void my_putdebug(const char *debug)
{
	if (DEBUG_MSG_ACTIVE)
		perror(debug);
}
