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

double	eqpt_derivative(int n, llval_t *llv_a, llval_t *llv_b)
{
	double	num = 0.0;
	double	den = 0.0;
	double	derivative = 0.0;

	num = (llval_get_nbh(2, llv_a)->value - llv_a->value);
	den = (llval_get_nbh(n + 1, llv_b)->value - llval_get_nbh(n - 1,llv_b)->value);
	derivative = (num / den);
	return (derivative);
}

llval_t	*eqpt_calc_derivatives_run(int n, llval_t *llv_a, llval_t *llv_b)
{
	llval_t	*cs = NULL;
	llval_t	*prev = NULL;
	llval_t	*a = llv_a;
	llval_t	*b = llv_b;
	llval_t	*res = NULL;
	
	res = new_llval();
	cs = res;
	while (llval_get_nbh(n + 1, a) != NULL && llval_get_nbh(2, b)->n != NULL) {
		cs->value = eqpt_derivative(n, a, b);
		a = a->n;
		b = b->n;
		prev = cs;
		cs = cs->n;
		cs = new_llval();
		prev->n = cs;
	}
	cs = NULL;
	a = NULL;
	b = NULL;
	return (res);
}

void	eqpt_get_derivatives(eqpt_calculator_t *eqpt)
{
	eqpt->deriv_head[0] = eqpt_calc_derivatives_run(1, eqpt->phs, eqpt->volumes);
	eqpt->deriv_head[1] = eqpt_calc_derivatives_run(2, eqpt->deriv_head[0], eqpt->volumes);
}
