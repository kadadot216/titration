/*
** EPITECH PROJECT, 2018
** t_print_file.c
** File description:
** UT for printing file
*/

#include "file.h"
#include "unit_testing.h"
#include "titration.h"

Test(string_print_csv_filename, t1, .init=redirect_all_std)
{
	FILE	*fd = NULL;

	if (file_open(&fd, "tests/values.csv", "r")) {
		file_print_ctnt(fd);
		fflush(stdout);
		cr_assert_stdout_eq_str(T_FILEBUFF, "");
		fclose(fd);
	} else {
		cr_assert_eq(1, 0);
	}
}

Test(print_titration_calclist, test1, .init=redirect_all_std)
{
	FILE	*fd = 0;
	eqpt_calculator_t	eqpt;

	if (file_open(&fd, "tests/values.csv", "r")) {
		fd_parse(&eqpt, fd);
		print_titr_vals(eqpt.start);
		fflush(stdout);
		cr_assert_stdout_eq_str(T_FILEBUFF, "");
		fclose(fd);
	} else {
		cr_assert_eq(1, 0, "Open failed\n");
	}
}

Test(print_derivative_2_data, test1, .init=redirect_all_std)
{
	char	*buffer = "0.27\n"
	"-0.11\n"
	"-0.63\n"
	"-0.80\n"
	"-0.67\n"
	"0.78\n"
	"0.46\n"
	"0.15\n"
	"0.06\n";

	print_2nd_derivative();
	fflush(stdout);
	cr_assert_stdout_eq_str(buffer, "");
}
