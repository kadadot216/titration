/*
** EPITECH PROJECT, 2018
** t_sort.c
** File description:
** Sort linked lists
*/

#include "unit_testing.h"
#include "file.h"
#include "titration.h"

Test(bubble_sort, unordered_volumes, .init=redirect_all_std)
{
	FILE	*fd = 0;
	eqpt_calculator_t	eqpt;
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

	if (file_open(&fd, "tests/values_unordered.csv", "r")) {
		fd_parse(&eqpt, fd);
		eqpt_sort_volumes(&eqpt);
		print_titr_vals(eqpt.start);
		eqpt_destroy(&eqpt);
		fflush(stdout);
		cr_assert_stdout_eq_str(buffer, "");
		fclose(fd);
	} else {
		cr_assert_eq(1, 0, "Open failed\n");
	}
}
