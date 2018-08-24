/*
** EPITECH PROJECT, 2018
** t_print2_file.c
** File description:
** More TUs for printing
*/

#include "unit_testing.h"

Test(print_derivative, test1, .init=redirect_all_std)
{
	FILE	*fd = 0;
	eqpt_calculator_t	eqpt;

	if ((fd = file_open("tests/values.csv", "r")) != NULL) {
		fd_parse(&eqpt, fd);
		eqpt_get_derivatives(&eqpt);
		eqpt_print_derivative(&eqpt);
		eqpt_destroy(&eqpt);
		fflush(stdout);
		cr_assert_stdout_eq_str(T_DERIV1BUFF, "");
		fclose(fd);
	} else {
		cr_assert_eq(1, 0, "Open failed\n");
	}
}

Test(print_derivative_2, test1, .init=redirect_all_std)
{
	FILE	*fd = 0;
	eqpt_calculator_t	eqpt;

	if ((fd = file_open("tests/values.csv", "r"))) {
		fd_parse(&eqpt, fd);
		eqpt_get_derivatives(&eqpt);
		eqpt_print_derivative_2(&eqpt);
		eqpt_destroy(&eqpt);
		fflush(stdout);
		cr_assert_stdout_eq_str(T_DERIV2BUFF, "");
		fclose(fd);
	} else {
		cr_assert_eq(1, 0, "Open failed\n");
	}
}
