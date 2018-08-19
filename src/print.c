/*
** EPITECH PROJECT, 2018
** print.c
** File description:
** Print related functions
*/

#include "titration.h"

// Need to create funcs:
// eqpt_get_eqpt(&eqpt)
// ...
// print_first_derivative(&eqpt)
// print_sec_derivative(&eqpt)
// print_derivative_est(&eqpt)
// TODO: Need to add security checks

void	eqpt_print_derivative(eqpt_calculator_t *eqpt)
{
	llval_t	*x = llval_get_nbh(1, eqpt->volumes);
	llval_t	*fx = eqpt->deriv_head[0];
	llval_t	*eq = NULL;

	printf("Derivative:\n");
	while (llval_get_nbh(1, x) != NULL && llval_get_nbh(1, fx) != NULL) {
		if (eq == NULL || fx->value > eq->value) {
			eq = x;
		}
		printf("volume: %g ml -> %.2f\n", x->value, fx->value);
		x = x->n;
		fx = fx->n;
	}
	printf("\nEquivalent point at %g ml\n\n", eq->value);
	eq = NULL;
	x = NULL;
	fx = NULL;
}

void	eqpt_print_derivative_2(eqpt_calculator_t *eqpt)
{
	llval_t	*x = llval_get_nbh(2, eqpt->volumes);
	llval_t	*fx = eqpt->deriv_head[1];
	llval_t	*eq = NULL;
	llval_t	*fq = NULL;
	llval_t	*lim = NULL;
	double	coefficient = 0.0;
	double	eq_pt = 0.0;

	printf("Second derivative:\n");
	while (llval_get_nbh(2, x) != NULL && llval_get_nbh(1, fx) != NULL) {
		if (fx->value > 0 && llval_get_nbh(1, fx)->value < 0) {
			eq = x;
			fq = fx;
		}
		printf("volume: %g ml -> %.2f\n", x->value, fx->value);
		x = x->n;
		fx = fx->n;
	}
	printf("\nSecond derivative estimated:\n");
	lim = eq->n;
	// Compute the coeff value:
	// (2nd val - 1st val) <= the values difference
	// ((2nd vol - 1st vol) * 10) <= Nbs of iterations
	coefficient = ((fq->n->value - fq->value) / ((eq->n->value - eq->value) * 10));
	// On first node, while value is less than bound - 0.10
	while (eq->value < lim->value - 0.10) {
		// Save the equivalent pt in a way...
		if (eq_pt == 0.0 && fq->value - 0.10 < 0.0) {
			eq_pt = eq->value;
		}
		printf("volume: %g ml -> %.2f\n", eq->value, fq->value);
		fq->value += coefficient;
		eq->value += 0.10;
	}
	// This updates to the *next, needs to put inaloop
	eq = eq->n;
	lim = eq->n;
	fq = fq->n;
	coefficient = ((fq->n->value - fq->value) / ((eq->n->value - eq->value) * 10));
	// On nodes after, while value is less than bound
	while (eq->value < lim->value) {
		if (eq_pt == 0.0 && fq->value - 0.10 < 0.0) {
			eq_pt = eq->value;
		}
		printf("volume: %g ml -> %.2f\n", eq->value, fq->value);
		fq->value += coefficient;
		eq->value += 0.10;
	}
	printf("\nEquivalent point at %g ml\n", eq_pt);
	x = NULL;
	fx = NULL;
}
