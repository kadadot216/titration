/*
** EPITECH PROJECT, 2018
** t_print_file.c
** File description:
** UT for printing file
*/

#include "file.h"
#include "unit_testing.h"

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

	if (file_open(&fd, "values.csv", "r")) {
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

	if (file_open(&fd, "values.csv", "r")) {
		file_print_ctnt(fd);
		fflush(stdout);
		cr_assert_stdout_neq_str(buffer, "");
		fclose(fd);
	} else {
		cr_assert_eq(1, 0);
	}
}
