/*
** EPITECH PROJECT, 2018
** print_2nd_derivative.c
** File description:
** Prints the 2nd derivative from pre-existing data
*/

#include <stdio.h>
#include "calc.h"

void	print_2nd_derivative(void)
{
	int	size = 13;
	double	phs[] = {2.0, 3.0, 4.0, 4.4, 4.6, 6, 6.8, 8.0, 10.0, 11.3, 11.46, 11.6, 11.8};
	double	volumes[] = {1.0, 2.0, 3.0, 5.0, 6.0, 7.0, 7.5, 8.0, 9.0, 12.0, 14.0, 16.0, 20.0};
	double	derivative_2 = 0.0;
	int	i = 0;

	while (i < size - 4) {
		derivative_2 = dbg_calc_derivative_2(&phs[i], &volumes[i]);
		printf("%.2f\n", derivative_2);
		derivative_2 = 0.0;
		i++;
	}
}
