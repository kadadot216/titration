/*
** EPITECH PROJECT, 2018
** titration.c
** File description:
** Titration related funcs
*/

#include <stdlib.h>
#include "types.h"
#include "titration.h"

void	calcnode_init(calcnode_t *calcnode)
{
	calcnode->vol = 0.0;
	calcnode->ph = 0.0;
	calcnode->n = NULL;
}

calcnode_t	*calcnode_new(calcnode_t *new)
{
	new = malloc(sizeof(calcnode_t));
	if (new == NULL) {
		return (new);
	}
	calcnode_init(new);
	return (new);
}

void	calclist_delete(calcnode_t *start)
{
	calcnode_t	*cs = start;
	calcnode_t	*prev = NULL;

	while (cs != NULL) {
		prev = cs;
		cs = cs->n;
		calcnode_init(prev);
		free(prev);
	}
	prev = NULL;
	cs = NULL;
}

calcnode_t	*calcnode_get_nbh(int n, calcnode_t *node)
{
	calcnode_t	*csort = node;

	while (n > 0) {
		csort = csort->n;
		n--;
	}
	return (csort);
}
