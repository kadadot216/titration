/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** GDB Testing main
*/

#include <stdio.h>
#include "calc.h"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	int	size = 11;
	double	phs[] = {1.0, 0.47, 0.20, 0.8, 1.47, 2.0, 2.13, 0.83, 0.29, 0.07, 0.06};
	double	volumes[] = {2.0, 3.0, 5.0, 6.0, 7.0, 7.5, 8.0, 9.0, 12.0, 14.0, 16.0};
	double	derivative = 0.0;
	int	i = 0;

	while (i < size - 2) {
		derivative = dbg_calc_derivative(&phs[i], &volumes[i]);
		printf("%g\n", derivative);
		derivative = 0.0;
		i++;
	}
	return (0);
}
