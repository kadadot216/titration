/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** GDB Testing main
*/

#include <stdio.h>
#include "titration.h"
#include "file.h"
#include "calc.h"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

	char	*file = "tests/values_unordered.csv";
	FILE	*fd = NULL;
	bool_t	status = FALSE;
	eqpt_calculator_t	eqpt;

	status = ((bool_t) file_open(&fd, file, OPEN_MODE));
	if (status == FALSE) {
		return (84);
	}
	eqpt_init(&eqpt);
	fd_parse(&eqpt, fd);
	fclose(fd);
	print_titr_vals(eqpt.start);
	eqpt_sort_volumes(&eqpt);
	//eqpt_get_derivatives(&eqpt);
	printf("\n\nAfter:\n");
	print_titr_vals(eqpt.start);
	//eqpt_print_derivative(&eqpt);
	//eqpt_print_estpt(&eqpt);
	//eqpt_print_derivative_2(&eqpt);
	//eqpt_print_estimate(2, eqpt.estimate);
	//eqpt_print_estpt(&eqpt);
	//eqpt_destroy(&eqpt);
	return (0);
}
