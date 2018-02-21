/*
** EPITECH PROJECT, 2017
** mysfml
** File description:
** put an int in an str
*/

/* File created the 21/02/2018 at 13:29:10 by julian.frabel@epitech.eu */

#include <stdlib.h>
#include "my_sfml_core.h"

static int my_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	else
		return (nb);
}

static int my_pow(int nb, int power)
{
	int result = 1;

	for (int i = 0; i < power; i++)
		result *= nb;
	return (result);
}

static int nb_size(int nb)
{
	int i = 1;

	if (nb < 0) {
		i++;
		nb = (nb + 1) * -1;
	}
	while (nb / 10 != 0) {
		i++;
		nb /= 10;
	}
	return (i);
}

char *my_int_to_str(int nb)
{
	int pos = 0;
	int div = my_pow(10, nb_size(nb) - (nb < 0) - 1);
	char *nb_str = malloc(sizeof(*nb_str) * (nb_size(nb) + 1));

	if (nb < 0) {
		nb_str[pos] = '-';
		pos++;
	}
	while (div != 0) {
		nb_str[pos] = ((my_abs(nb / div)) + '0');
		pos++;
		nb = nb % div;
		div /= 10;
	}
	nb_str[pos] = '\0';
	return (nb_str);
}