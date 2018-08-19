/*
** EPITECH PROJECT, 2018
** calc.c
** File description:
** Calculation related functions
*/

#include "titration.h"
#include <stdio.h>

double	eqpt_derivative_old(int counter, double *phs, double *volumes)
{
	double	y1 = 0.0;
	double	y2 = 0.0;
	double	derivative_2 = 0.0;

	if (counter <= 1) {
		return ((phs[2] - phs[0]) / (volumes[2] - volumes[0]));
	}	
	y1 = eqpt_derivative_old((counter - 1), &phs[2], &volumes[2]);
	y2 = eqpt_derivative_old((counter - 1), &phs[0], &volumes[0]);
	derivative_2 = ((y2 - y1) / (volumes[3] - volumes[1]));
	return (derivative_2);
}

double	eqpt_derivative(llval_t *llv_a, llval_t *llv_b)
{
	double	num = 0.0;
	double	den = 0.0;
	double	derivative = 0.0;

	num = (llv_a->n->n->value - llv_a->value);
	den = (llv_b->n->n->value - llv_b->value);
	derivative = (num / den);
	return (derivative);
}

void	eqpt_calc_derivatives_run(eqpt_calculator_t *eqpt)
{
	llval_t	*cs = NULL;
	llval_t	*prev = NULL;
	llval_t	*v = eqpt->volumes;
	llval_t	*p = eqpt->phs;

	eqpt->deriv_head[0] = new_llval(eqpt->deriv_head[0]);
	cs = eqpt->deriv_head[0];
	while (p->n->n->n != NULL && v->n->n->n != NULL) {
		cs->value = eqpt_derivative(p, v);
		p = p->n;
		v = v->n;
		prev = cs;
		cs = cs->n;
		cs = new_llval(cs);
		prev->n = cs;
	}
	cs = NULL;
}
