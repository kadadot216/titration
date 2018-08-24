/*
** EPITECH PROJECT, 2018
** print.c
** File description:
** Print related functions
*/

#include "titration.h"

double	step_compute(calcnode_t *node, calcnode_t *next)
{
	return ((next->ph - node->ph) / ((next->vol - node->vol) * 10));
}

void	eqpt_print_estimate(int n, calcnode_t *estimate)
{
	double	step = 0.0;
	double	eq_pt = 0.0;
	calcnode_t	*csor = estimate;
	calcnode_t	*next_stop = csor->n;

	printf("\nSecond derivative estimated:\n");
	step = step_compute(csor, next_stop);
	while (n > 0 && csor->vol < next_stop->vol && next_stop->n != NULL) {
		// Need to take next_stop->csor to - 2*OFFSET to update loop cycle
		if (n > 0 && csor->vol > next_stop->vol - 0.10) {
			csor = csor->n;
			next_stop = csor->n;
			step = step_compute(csor, next_stop);
			n--;
		}
		if (eq_pt == 0.0 && estimate->ph - 0.10 < 0.0)
			eq_pt = csor->vol;
		printf("volume: %g ml -> %.2f\n", csor->vol, csor->ph);
		csor->ph += step;
		csor->vol += 0.10;
	}
	estimate->vol = eq_pt;
}

void	eqpt_print_derivative(eqpt_calculator_t *eqpt)
{
	calcnode_t	*csor = eqpt->deriv_head[0];

	printf("Derivative:\n");
	while (calcnode_get_nbh(2, csor) != NULL) {
		if (eqpt->estimate == NULL || csor->ph > eqpt->estimate->ph) {
			eqpt->estimate = csor;
		}
		printf("volume: %g ml -> %.2f\n", csor->vol, csor->ph);
		csor = csor->n;
	}
}

void	eqpt_print_estpt(eqpt_calculator_t *eqpt)
{
	printf("\nEquivalent point at %g ml\n", eqpt->estimate->vol);
}

void	eqpt_print_derivative_2(eqpt_calculator_t *eqpt)
{
	calcnode_t	*csor = eqpt->deriv_head[1];

	printf("\n");
	printf("Second derivative:\n");
	while (calcnode_get_nbh(2, csor) != NULL) {
		if (eqpt->estimate == NULL || (csor->ph > 0 && csor->n->ph < 0)) {
			eqpt->estimate = csor;
		}
		printf("volume: %g ml -> %.2f\n", csor->vol, csor->ph);
		csor = csor->n;
	}
}
