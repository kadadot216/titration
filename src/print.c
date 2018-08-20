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

double	get_coefficient_est(llval_t *llv_a, llval_t *llv_b)
{
	return ((llv_a->n->value - llv_a->value) / (llv_b->n->value - llv_b->value) * 10);
}

void	print_est_ptprog(int n, llval_t *vol, llval_t *est)
{
	double	coefficient = 0.0;
	double	eq_pt = 0.0;
	llval_t	*lim = vol->n;

	coefficient = ((est->n->value - est->value) / ((vol->n->value - vol->value) * 10));
	while (n > 0 && vol->value <= lim->value - 0.10) {
		// Need to take lim->value to - 2*OFFSET to update loop cycle
		if (n > 0 && vol->value > lim->value - 0.20) {
			est = est->n;
			vol = vol->n;
			lim = vol->n;
			coefficient = ((est->n->value - est->value) / ((vol->n->value - vol->value) * 10));
			n--;
		}
		if (eq_pt == 0.0 && est->value - 0.10 < 0.0)
			eq_pt = vol->value;
		printf("volume: %g ml -> %.2f\n", vol->value, est->value);
		est->value += coefficient;
		vol->value += 0.10;
	}
	printf("\nEquivalent point at %g ml\n", eq_pt);
}

void	eqpt_get_est(eqpt_calculator_t *eqpt)
{
	printf("\nSecond derivative estimated:\n");
	print_est_ptprog(2, eqpt->volest, eqpt->est);
}

void	eqpt_print_derivative_2(eqpt_calculator_t *eqpt)
{
	llval_t	*x = llval_get_nbh(2, eqpt->volumes);
	llval_t	*fx = eqpt->deriv_head[1];

	printf("Second derivative:\n");
	while (llval_get_nbh(2, x) != NULL && llval_get_nbh(1, fx) != NULL) {
		if (fx->value > 0 && llval_get_nbh(1, fx)->value < 0) {
			eqpt->volest = x;
			eqpt->est = fx;
		}
		printf("volume: %g ml -> %.2f\n", x->value, fx->value);
		x = x->n;
		fx = fx->n;
	}
	x = NULL;
	fx = NULL;
}
