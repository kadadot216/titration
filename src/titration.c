/*
** EPITECH PROJECT, 2018
** titration.c
** File description:
** Titration related funcs
*/

#include <stdlib.h>
#include "types.h"
#include "titration.h"

void	llval_init(llval_t *llval)
{
	llval->value = 0.0;
	llval->n = NULL;
}

llval_t	*new_llval(llval_t *new)
{
	new = malloc(sizeof(llval_t));
	
	if (!new) {
		return (NULL);
	}
	llval_init(new);
	return (new);
}

void	init_eqpt(eqpt_calculator_t *eqpt)
{
	int	i = 0;

	eqpt->volumes = NULL;
	eqpt->phs = NULL;
	while (i < MAX_DERIVATIVE) {
		eqpt->deriv_head[i] = NULL;
		i++;
	}
}
