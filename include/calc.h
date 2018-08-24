/*
** EPITECH PROJECT, 2018
** calc.h
** File description:
** Header file for Calculation functions
*/

#ifndef __CALC_H__
#define __CALC_H__

#include "titration.h"

double	eqpt_derivative_old(int counter, double *volumes, double *phs);
double	eqpt_derivative(int n, calcnode_t *node);
calcnode_t	*eqpt_calc_derivatives_run(int n, calcnode_t *node);

#endif /* __CALC_H__ */
