/*
** EPITECH PROJECT, 2018
** prnting.c
** File description:
** Debugging related functions
*/

#include "titration.h"
#include "file.h"

void	print_titr_vals(calcnode_t *node)
{
	calcnode_t	*csor = node;

	while (csor->n != NULL && csor->n != NULL) {
		printf("%g%c%g\n", csor->vol, DATA_SEP, csor->ph);
		csor = csor->n;
	}
}

void	print_calcnode(calcnode_t *val)
{
	calcnode_t	*cs = val;

	while (cs->n != NULL) {
		printf("%g\n", cs->vol);
		cs = cs->n;
	}
}
