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

	char	*file = "tests/values.csv";
	FILE	*fd = NULL;
	bool_t	status = FALSE;
	eqpt_calculator_t	eqpt;

	status = ((bool_t) file_open(&fd, file, OPEN_MODE));
	if (status == FALSE) {
		return (84);
	}
	fd_parse(&eqpt, fd);
	fclose(fd);
	eqpt_get_derivatives(&eqpt);
	eqpt_print_derivative(&eqpt);
	eqpt_print_derivative_2(&eqpt);
	eqpt_destroy(&eqpt);
	return (0);
}
