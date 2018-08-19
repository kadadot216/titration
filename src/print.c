/*
** EPITECH PROJECT, 2018
** print.c
** File description:
** Print related functions
*/

#include "titration.h"

void	eqpt_print_derivative(eqpt_calculator_t *eqpt)
{
	llval_t	*x = llval_get_nbh(1, eqpt->volumes);
	llval_t	*fx = eqpt->deriv_head[0];
	double	*eq = NULL;

	printf("Derivative:\n");
	while (llval_get_nbh(1, x) != NULL && llval_get_nbh(1, fx) != NULL) {
		if (eq == NULL || *eq < fx->value) {
			eq = &x->value;
		}
		printf("volume: %g ml -> %.2f\n", x->value, fx->value);
		x = x->n;
		fx = fx->n;
	}
	printf("\nEquivalent point at %g ml\n\n", *eq);
	eq = NULL;
	x = NULL;
	fx = NULL;
}

void	eqpt_print_derivative_2(eqpt_calculator_t *eqpt)
{
	llval_t	*x = llval_get_nbh(2, eqpt->volumes);
	llval_t	*fx = eqpt->deriv_head[1];
	double	*eq = NULL;

	printf("Second derivative:\n");
	while (llval_get_nbh(2, x) != NULL && llval_get_nbh(1, fx) != NULL) {
		if (eq == NULL || *eq < fx->value) {
			eq = &x->value;
		}
		printf("volume: %g ml -> %.2f\n", x->value, fx->value);
		x = x->n;
		fx = fx->n;
	}
	eq = NULL;
	x = NULL;
	fx = NULL;
}
