/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** GDB Testing main
*/

#include <stdio.h>
#include "calc.h"

int	print_2nd_derivative(void)
{
	int	size = 13;
	double	phs[] = {2.0, 3.0, 4.0, 4.4, 4.6, 6, 6.8, 8.0, 10.0, 11.3, 11.46, 11.6, 11.8};
	double	phs_derived[] = {0.0, 1.0, 0.47, 0.20, 0.8, 1.47, 2.0, 2.13, 0.83, 0.29, 0.07, 0.06, 0.0};
	double	volumes[] = {1.0, 2.0, 3.0, 5.0, 6.0, 7.0, 7.5, 8.0, 9.0, 12.0, 14.0, 16.0, 20.0};
	double	derivative = 0.0;
	double	derivative_2 = 0.0;
	int	i = 0;

	while (i < size - 4) {
		derivative = dbg_calc_derivative(&phs_derived[i], &volumes[i]);
		derivative_2 = dbg_calc_derivative_2(&phs[i], &volumes[i]);
		printf("%.2f\n", derivative);
		printf("%.2f\n", derivative_2);
		derivative = 0.0;
		derivative_2 = 0.0;
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

	print_2nd_derivative();
	return (0);
}
