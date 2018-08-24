/*
** EPITECH PROJECT, 2018
** eqpt.c
** File description:
** eqpt structure related functions
*/

#include <stdlib.h>
#include "titration.h"

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
		eqpt->deriv_head[i] = NULL;
		i++;
	}
	calclist_delete(eqpt->start);
	eqpt->start = NULL;
	eqpt->estimate = NULL;
}
