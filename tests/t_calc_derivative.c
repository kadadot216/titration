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

Test(derivative_2_calc, test1)
{
	double	volumes[] = {1.0, 2.0, 3.0, 5.0, 6.0};
	double	phs[] = {2.0, 3.0, 4.0, 4.4, 4.6};
	double	hi = -0.27;
	double	low = -0.28;
	double	derivative = 0.0;

	derivative = dbg_calc_derivative_2(volumes, phs);
	cr_assert(derivative >= low);
	cr_assert(derivative <= hi, "Got %g", derivative);
}
