/*
** EPITECH PROJECT, 2018
** calc.c
** File description:
** Calculation related functions
*/

#include "titration.h"
#include <stdio.h>

double	eqpt_derivative_rec_old(int counter, double *phs, double *volumes)
{
	double	y1 = 0.0;
	double	y2 = 0.0;
	double	derivative_2 = 0.0;

	if (counter <= 1) {
		return ((phs[2] - phs[0]) / (volumes[2] - volumes[0]));
	}	
	y1 = eqpt_derivative_rec_old((counter - 1), &phs[2], &volumes[2]);
	y2 = eqpt_derivative_rec_old((counter - 1), &phs[0], &volumes[0]);
	derivative_2 = ((y2 - y1) / (volumes[3] - volumes[1]));
	return (derivative_2);
}

double	eqpt_derivative_rec(int n, llval_t *ph, llval_t *volume)
{
	double	y1 = 0.0;
	double	y2 = 0.0;
	double	derivative_n = 0.0;

	if (n <= 1) {
		return ((ph->value - ph->n->n->value) / (volume->value - volume->n->n->value));
	}
	y1 = eqpt_derivative_rec((n - 1), ph->n->n, volume->n->n);
	y2 = eqpt_derivative_rec((n - 1), ph, volume);
	derivative_n = ((y2 - y1) / volume->n->n->n->value - volume->n->value);
	return (derivative_n);
}

void	eqpt_calc_derivatives_run(int nth, eqpt_calculator_t *eqpt)
{
	int	ct = 0;
	
	if (nth == 1) {
		
	}

}
