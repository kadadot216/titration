/*
** EPITECH PROJECT, 2018
** t_sort.c
** File description:
** Sort linked lists
*/

#include "unit_testing.h"

Test(bubble_sort, unordered_volumes, .init=redirect_all_std)
{
	FILE	*fd = 0;
	eqpt_calculator_t	eqpt;

	if ((fd = file_open("tests/values_unordered.csv", "r"))) {
		fd_parse(&eqpt, fd);
		fclose(fd);
		eqpt_sort_volumes(&eqpt);
		print_titr_vals(eqpt.start);
		fflush(stdout);
		cr_assert_stdout_eq_str(T_FILEBUFF, "");
		calclist_delete(eqpt.start);
	} else {
		cr_assert_eq(1, 0, "Open failed\n");
	}
}
