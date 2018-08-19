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
double	eqpt_derivative(int n, llval_t *lph, llval_t *lvolume);
llval_t	*eqpt_calc_derivatives_run(int n, llval_t *llv_a, llval_t *llv_b);

#endif /* __CALC_H__ */
