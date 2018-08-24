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
	char	*buffer = "1;2\n"
		"2;3\n"
		"3;4\n"
		"5;4.4\n"
		"6;4.6\n"
		"7;6\n"
		"7.5;6.8\n"
		"8;8\n"
		"9;10\n"
		"12;11.3\n"
		"14;11.46\n"
		"16;11.6\n"
		"20;11.8\n";
	FILE	*fd = NULL;

	if (file_open(&fd, "tests/values.csv", "r")) {
		file_print_ctnt(fd);
		fflush(stdout);
		cr_assert_stdout_eq_str(buffer, "");
		fclose(fd);
	} else {
		cr_assert_eq(1, 0);
	}
}

Test(string_print_csv_filename, t2, .init=redirect_all_std)
{
	char	*buffer = "1;2\n"
		"2;3\n"
		"3;4\n"
		"5;4.4\n"
		"6;4.6\n"
		"7;6\n"
		"7.5;6.8\n"
		"8;8\n"
		"9;10\n"
		"12;11.3\n"
		"1;11.46\n"
		"16;11.6\n"
		"20;11.8\n";
	FILE	*fd = NULL;

	if (file_open(&fd, "tests/values.csv", "r")) {
		file_print_ctnt(fd);
		fflush(stdout);
		cr_assert_stdout_neq_str(buffer, "");
		fclose(fd);
	} else {
		cr_assert_eq(1, 0, "Open failed\n");
	}
}

Test(print_titration_calclist, test1, .init=redirect_all_std)
{
	char	*buffer = "1;2\n"
		"2;3\n"
		"3;4\n"
		"5;4.4\n"
		"6;4.6\n"
		"7;6\n"
		"7.5;6.8\n"
		"8;8\n"
		"9;10\n"
		"12;11.3\n"
		"14;11.46\n"
		"16;11.6\n"
		"20;11.8\n\n";
	FILE	*fd = 0;
	eqpt_calculator_t	eqpt;

	if (file_open(&fd, "tests/values.csv", "r")) {
		fd_parse(&eqpt, fd);
		print_titr_vals(eqpt.start);
		fflush(stdout);
		cr_assert_stdout_eq_str(buffer, "");
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
