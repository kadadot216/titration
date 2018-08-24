/*
** EPITECH PROJECT, 2018
** t_calc_derivative.c
** File description:
** UT Derivative calc
*/

#include "unit_testing.h"
#include "../include/calc.h"
#include "../include/file.h"
#include "../include/titration.h"

Test(derivative_calc, test1)
{
	double	volumes[] = {1.0, 2.0, 3.0};
	double	phs[] = {2.0, 3.0, 4.0};
	double	res = 1.00;
	double	derivative = 0.0;

	derivative = eqpt_derivative_old(1, volumes, phs);
	cr_assert_eq(derivative, res);
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
		derivative_2 = eqpt_derivative_old(2, &phs[i], &volumes[i]);
		cr_assert_eq((int) derivative_2, (int)results[i], "%g <=> %g\n", derivative_2, results[i]);
		derivative_2 = 0.0;
		i++;
	}
}

Test(calc_first_derivative_ll, test1)
{
	FILE	*fd = NULL;
	double	results[] = {1.0, 0.47, 0.20, 0.8, 1.47, 2.0, 2.13, 0.83, 0.29, 0.07, 0.06};
	int	size = 11;
	int	i = 0;
	eqpt_calculator_t	eqpt;
		
	file_open(&fd, "tests/values.csv", OPEN_MODE);
	fd_parse(&eqpt, fd);
	eqpt.deriv_head[0] = eqpt_calc_derivatives_run(1, eqpt.start);
	while(eqpt.deriv_head[0]->n->n != NULL) {
		cr_assert_eq((int) eqpt.deriv_head[0]->ph, (int) results[i]);
		eqpt.deriv_head[0] = eqpt.deriv_head[0]->n;
		i++;
	}
	cr_assert_eq(i, size, "i = %d\n", i);
}

Test(calc_sec_derivative_ll, test1)
{
	FILE	*fd = NULL;
	double	results[] = {0.266667, -0.111111, -0.633333, -0.8, -0.666667, 0.783333, 0.460333, 0.15, 0.0588333};
	int	size = 9;
	int	i = 0;
	eqpt_calculator_t	eqpt;
		
	file_open(&fd, "tests/values.csv", OPEN_MODE);
	fd_parse(&eqpt, fd);
	eqpt.deriv_head[0] = eqpt_calc_derivatives_run(1, eqpt.start);
	eqpt.deriv_head[1] = eqpt_calc_derivatives_run(2, eqpt.deriv_head[0]);
	while(eqpt.deriv_head[1]->n->n != NULL) {
		cr_assert_eq((int) eqpt.deriv_head[1]->ph, (int) results[i], "got %g", eqpt.deriv_head[1]->vol);
		eqpt.deriv_head[1] = eqpt.deriv_head[1]->n;
		i++;
	}
	calclist_delete(eqpt.deriv_head[0]);
	calclist_delete(eqpt.deriv_head[1]);
	cr_assert_eq(i, size, "i = %d\n", i);
}
