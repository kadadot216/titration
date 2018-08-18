/*
** EPITECH PROJECT, 2018
** calc.c
** File description:
** Calculation related functions
*/

#include <stdio.h>

double	dbg_calc_derivative(double *phs, double *volumes)
{
	return ((phs[2] - phs[0]) / (volumes[2] - volumes[0]));
}

double	dbg_calc_derivative_2(double *phs, double *volumes)
{
	double	(*f)(double *, double *) = &dbg_calc_derivative;

	double	y2 = f(&phs[2], &volumes[2]);
	double	y1 = f(&phs[0], &volumes[0]);
	double	derivative_2 = ((y2 - y1) / (volumes[3] - volumes[1]));
	return (derivative_2);
}
