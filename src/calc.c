/*
** EPITECH PROJECT, 2018
** calc.c
** File description:
** Calculation related functions
*/

double	dbg_calc_derivative(double *phs, double *volumes)
{
	return ((phs[2] - phs[0]) / (volumes[2] - volumes[0]));
}

double	dbg_calc_derivative_2(double *phs, double *volumes)
{
	double	(*f)(double *, double *) = &dbg_calc_derivative;

	return ((f(&phs[2], &volumes[2]) - f(&phs[0], &volumes[0])) / volumes[2] - volumes[0]);
}
