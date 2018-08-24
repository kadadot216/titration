#include "titration.h"

void	swap_nodes(calcnode_t *n1, calcnode_t *n2)
{
	calcnode_t	hold = *n1;

	n1->vol = n2->vol;
	n1->ph = n2->ph;
	n2->vol = hold.vol;
	n2->ph = hold.ph;
}

void	eqpt_sort_volumes(eqpt_calculator_t *eqpt)
{
	calcnode_t	*start = eqpt->start;
	calcnode_t	*csor = start;

	while (csor->n->n != NULL) {
		if (csor->vol > csor->n->vol) {
			swap_nodes(csor, csor->n);
			csor = start;
		} else {
			csor = csor->n;
		}
	}
	start = NULL;
	csor = NULL;
}
