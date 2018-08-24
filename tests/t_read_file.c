/*
** EPITECH PROJECT, 2018
** t_read_file.c
** File description:
** Header file for UT reading .csv file
*/

#include "file.h"
#include "unit_testing.h"

Test(string_is_not_csv_filename, test1)
{
	char	*fname = "vols.txt";

	cr_assert_eq(file_has_extension(fname, DATA_EXT), 0);
}

Test(string_is_not_csv_filename, test2)
{
	char	*fname = "vols";

	cr_assert_eq(file_has_extension(fname, DATA_EXT), 0);
}

Test(string_is_csv_filename, test1)
{
	char	*fname = "values.csv";

	cr_assert_eq(file_has_extension(fname, DATA_EXT), 1);
}
