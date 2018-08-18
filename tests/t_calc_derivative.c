/*
** EPITECH PROJECT, 2018
** t_calc_derivative.c
** File description:
** UT Derivative calc
*/

#include "unit_testing.h"
#include "../include/calc.h"

Test(derivative_calc, test1)
{
	double	volumes[] = {1.0, 2.0, 3.0};
	double	phs[] = {2.0, 3.0, 4.0};
	double	res = 1.00;
	double	derivative = 0.0;

	derivative = dbg_calc_derivative(volumes, phs);
	cr_assert_eq(derivative, res);
}

Test(print_derivative_2, test1, .init=redirect_all_std)
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

Test(derivative_2_calc, test2)
{
	int	size = 9;
	double	phs[] = {2.0, 3.0, 4.0, 4.4, 4.6, 6, 6.8, 8.0, 10.0, 11.3, 11.46, 11.6, 11.8};
	double	volumes[] = {1.0, 2.0, 3.0, 5.0, 6.0, 7.0, 7.5, 8.0, 9.0, 12.0, 14.0, 16.0, 20.0};
	double	results[] = {0.266667, -0.111111, -0.633333, -0.8, -0.666667, 0.783333, 0.460333, 0.15, 0.0588333};
	double	derivative_2 = 0.0;
	int	i = 0;

	while (i < size) {
		derivative_2 = dbg_calc_derivative_2(&phs[i], &volumes[i]);
		cr_assert_eq((int) derivative_2, (int)results[i], "%g <=> %g\n", derivative_2, results[i]);
		derivative_2 = 0.0;
		i++;
	}
}
