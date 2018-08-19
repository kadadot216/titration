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
void	eqpt_calc_derivatives_run(eqpt_calculator_t *);

#endif /* __CALC_H__ */
