#include "titration.h"

void	eqpt_routine(eqpt_calculator_t *eqpt)
{
	eqpt_sort_volumes(eqpt);
	eqpt_get_derivatives(eqpt);
	eqpt_print_derivative(eqpt);
	eqpt_print_estpt(eqpt);
	eqpt_print_derivative_2(eqpt);
	eqpt_print_estimate(2, eqpt->estimate);
	eqpt_print_estpt(eqpt);
}

void	eqpt_init(eqpt_calculator_t *eqpt)
{
	int	i = 0;

	eqpt->start = calcnode_new();
	eqpt->estimate = NULL;
	while (i < MAX_DERIVATIVE) {
		eqpt->deriv_head[i] = NULL;
		i++;
	}
}

void	eqpt_destroy(eqpt_calculator_t *eqpt)
{
	int	i = 0;

	while (i < MAX_DERIVATIVE && (eqpt->deriv_head[i])) {
		calclist_delete(eqpt->deriv_head[i]);
		eqpt->deriv_head[i] = NULL;
		i++;
	}
	calclist_delete(eqpt->start);
	eqpt->start = NULL;
	eqpt->estimate = NULL;
}
