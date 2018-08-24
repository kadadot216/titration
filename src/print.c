#include "titration.h"

int	exit_print_help(char **av, int status)
{
	printf("USAGE\n\t\t%s file\n\nDESCRIPTION\n\t\t"
	"file a csv containing \"vol;ph\" lines\n", av[0]);
	return (status);
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
		if (n > 0 && csor->vol > next_stop->vol - VOL_STEP) {
			csor = csor->n;
			next_stop = csor->n;
			step = step_compute(csor, next_stop);
			n--;
		}
		if (eq_pt == 0.0 && (estimate->ph + step) < 0.0)
			eq_pt = csor->vol;
		printf("volume: %g ml -> %.2f\n", csor->vol, csor->ph);
		csor->ph += step;
		csor->vol += VOL_STEP;
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
		if (eqpt->estimate == NULL || (csor->ph > 0 &&
		csor->n->ph < 0)) {
			eqpt->estimate = csor;
		}
		printf("volume: %g ml -> %.2f\n", csor->vol, csor->ph);
		csor = csor->n;
	}
}
