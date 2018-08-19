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

llval_t	*new_llval(void)
{
	llval_t	*new = malloc(sizeof(llval_t));
	
	if (!new) {
		return (NULL);
	}
	llval_init(new);
	return (new);
}

void	delete_llist(llval_t *start)
{
	llval_t	*cs = start;
	llval_t	*prev = NULL;

	while (cs->n != NULL) {
		prev = cs;
		cs = cs->n;
		llval_init(prev);
		free(prev);
	}
	prev = NULL;
	cs = NULL;
}

void	init_eqpt(eqpt_calculator_t *eqpt)
{
	int	i = 0;

	eqpt->volumes = NULL;
	eqpt->phs = NULL;
	eqpt->est = NULL;
	while (i < MAX_DERIVATIVE) {
		eqpt->deriv_head[i] = NULL;
		i++;
	}
}

void	eqpt_destroy(eqpt_calculator_t *eqpt)
{
	delete_llist(eqpt->deriv_head[0]);
	delete_llist(eqpt->deriv_head[1]);
	delete_llist(eqpt->volumes);
	delete_llist(eqpt->phs);
}

llval_t	*llval_get_nbh(int n, llval_t *val)
{
	llval_t	*cs = val;

	while (n > 0) {
		cs = cs->n;
		n--;
	}
	return (cs);
}
