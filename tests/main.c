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
	int	size = 13;
	double	volumes[] = {1.0, 2.0, 3.0, 5.0, 6.0, 7.0, 7.5, 8.0, 9.0, 12.0, 14.0, 16.0, 20.0};
	double	phs[] = {2.0, 3.0, 4.0, 4.4, 4.6, 6, 6.8, 8.0, 10.0, 11.3, 11.46, 11.6, 11.8};
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
