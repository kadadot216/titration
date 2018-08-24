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

calcnode_t	*calcnode_new(void)
{
	calcnode_t	*new = malloc(sizeof(calcnode_t));
	
	if (!new) {
		return (NULL);
	}
	calcnode_init(new);
	return (new);
}

void	calclist_delete(calcnode_t *start)
{
	calcnode_t	*cs = start;
	calcnode_t	*prev = NULL;

	while (cs->n != NULL) {
		prev = cs;
		cs = cs->n;
		calcnode_init(prev);
		free(prev);
	}
	prev = NULL;
	cs = NULL;
}

void	eqpt_init(eqpt_calculator_t *eqpt)
{
	int	i = 0;

	eqpt->start = NULL;
	eqpt->estimate = NULL;
	while (i < MAX_DERIVATIVE) {
		eqpt->deriv_head[i] = NULL;
		i++;
	}
}

void	eqpt_destroy(eqpt_calculator_t *eqpt)
{
	int	i = 0;

	while (i < MAX_DERIVATIVE && (eqpt->deriv_head[i])) {
		calclist_delete(eqpt->deriv_head[i]);
		i++;
	}
	calclist_delete(eqpt->start);
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
