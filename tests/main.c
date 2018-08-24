#include "titration.h"

int	main(int ac, char **av)
{
	eqpt_calculator_t	eqpt;
	FILE	*fd = NULL;

	if ((ac != 2) || (((fd = file_open(av[1], OPEN_MODE)) == NULL))) {
		return (exit_print_help(av, 84));
	}
	if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
		return (exit_print_help(av, 0));
	}
	eqpt_init(&eqpt);
	if (!fd_parse(&eqpt, fd)) {
		fclose(fd);
		calclist_delete(eqpt.start);
		return (exit_print_help(av, 84));
	}
	fclose(fd);
	eqpt_routine(&eqpt);
	eqpt_destroy(&eqpt);
	return (0);
}
