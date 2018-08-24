#include "titration.h"

void	print_titr_vals(calcnode_t *node)
{
	calcnode_t	*csor = node;

	while (csor->n != NULL && csor->n != NULL) {
		printf("%g%c%g\n", csor->vol, DATA_SEP, csor->ph);
		csor = csor->n;
	}
}

void	print_calcnode(calcnode_t *val)
{
	calcnode_t	*cs = val;

	while (cs->n != NULL) {
		printf("%g\n", cs->vol);
		cs = cs->n;
	}
}

void	file_print_ctnt(FILE *fd)
{
	char	*str = NULL;
	size_t	n = 0;

	while (getline(&str, &n, fd) != -1) {
		printf("%s", str);
	}
	free(str);
}
