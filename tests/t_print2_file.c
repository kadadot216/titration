/*
** EPITECH PROJECT, 2018
** t_print2_file.c
** File description:
** More TUs for printing
*/

#include "unit_testing.h"
#include "file.h"
#include "titration.h"

Test(print_derivative, test1, .init=redirect_all_std)
{
	FILE	*fd = 0;
	eqpt_calculator_t	eqpt;
	char	*buffer = "Derivative:\n"
		"volume: 2 ml -> 1.00\n"
		"volume: 3 ml -> 0.47\n"
		"volume: 5 ml -> 0.20\n"
		"volume: 6 ml -> 0.80\n"
		"volume: 7 ml -> 1.47\n"
		"volume: 7.5 ml -> 2.00\n"
		"volume: 8 ml -> 2.13\n"
		"volume: 9 ml -> 0.83\n"
		"volume: 12 ml -> 0.29\n"
		"volume: 14 ml -> 0.07\n"
		"volume: 16 ml -> 0.06\n\n"
		"Equivalent point at 8 ml\n\n\n";

	if (file_open(&fd, "tests/values.csv", "r")) {
		fd_parse(&eqpt, fd);
		eqpt_get_derivatives(&eqpt);
		eqpt_print_derivative(&eqpt);
		eqpt_destroy(&eqpt);
		fflush(stdout);
		cr_assert_stdout_eq_str(buffer, "");
		fclose(fd);
	} else {
		cr_assert_eq(1, 0, "Open failed\n");
	}
}

Test(print_derivative_2, test1, .init=redirect_all_std)
{
	FILE	*fd = 0;
	eqpt_calculator_t	eqpt;
	char	*buffer = "Second derivative:\n"
		"volume: 3 ml -> -0.27\n"
		"volume: 5 ml -> 0.11\n"
		"volume: 6 ml -> 0.63\n"
		"volume: 7 ml -> 0.80\n"
		"volume: 7.5 ml -> 0.67\n"
		"volume: 8 ml -> -0.78\n"
		"volume: 9 ml -> -0.46\n"
		"volume: 12 ml -> -0.15\n"
		"volume: 14 ml -> -0.06\n\n";

	if (file_open(&fd, "tests/values.csv", "r")) {
		fd_parse(&eqpt, fd);
		eqpt_get_derivatives(&eqpt);
		eqpt_print_derivative_2(&eqpt);
		eqpt_destroy(&eqpt);
		fflush(stdout);
		cr_assert_stdout_eq_str(buffer, "");
		fclose(fd);
	} else {
		cr_assert_eq(1, 0, "Open failed\n");
	}
}
