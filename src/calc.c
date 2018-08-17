/*
** EPITECH PROJECT, 2018
** calc.c
** File description:
** Calculation related functions
*/

double	dbg_calc_derivative(double *volumes, double *phs)
{
	return ((volumes[2] - volumes[0]) / (phs[2] - phs[0]));
}

double	dbg_calc_derivative_2(double *volumes, double *phs)
{
	double	(*f)(double *, double *) = &dbg_calc_derivative;

	return (f(&volumes[3], &phs[2]) - f(&volumes[0], &phs[0]) / phs[2] - phs[0]);
}
