/*
** EPITECH PROJECT, 2018
** calc.c
** File description:
** Calculation related functions
*/

#include "titration.h"
#include <stdio.h>

double	step_compute(calcnode_t *node, calcnode_t *next)
{
	return ((next->ph - node->ph) / ((next->vol - node->vol) * 10));
}

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

double	eqpt_derivative(calcnode_t *node)
{
	double	num = 0.0;
	double	den = 0.0;
	double	derivative = 0.0;

	num = node->n->n->ph - node->ph;
	den = (node->n->n->vol - node->vol);
	derivative = (num / den);
	return (derivative);
}

calcnode_t	*eqpt_calc_derivatives_run(int n, calcnode_t *start)
{
	calcnode_t	*csor = NULL;
	calcnode_t	*prev = NULL;
	calcnode_t	*res = NULL;
	calcnode_t	*res_head = NULL;

	csor = start;
	res = calcnode_new(res);
	res_head = res;
	while (calcnode_get_nbh(n + 1, csor) != NULL) {
		res->ph = eqpt_derivative(csor);
		res->vol = csor->n->vol;
		prev = res;
		csor = csor->n;
		res = res->n;
		res = calcnode_new(res);
		prev->n = res;
	}
	return (res_head);
}

void	eqpt_get_derivatives(eqpt_calculator_t *eqpt)
{
	eqpt->deriv_head[0] = eqpt_calc_derivatives_run(1, eqpt->start);
	eqpt->deriv_head[1] = eqpt_calc_derivatives_run(2, eqpt->deriv_head[0]);
}
