/*
** EPITECH PROJECT, 2018
** titration.h
** File description:
** Header file for 109titration
*/

#ifndef __TITRATION_H__
#define __TITRATION_H__

#include "file.h"
#include "types.h"

#define	MAX_DERIVATIVE	(2)
#define	VOL_STEP (0.10)

typedef struct	calcnode_s {
	double	vol;
	double	ph;
	struct calcnode_s	*n;
}	calcnode_t;

typedef struct	eqpt_calculator_s {
	calcnode_t	*start;
	calcnode_t	*deriv_head[MAX_DERIVATIVE];
	calcnode_t	*estimate;
}	eqpt_calculator_t;

void	calclist_delete(calcnode_t *start);
void	eqpt_destroy(eqpt_calculator_t *eqpt);
void	eqpt_get_derivatives(eqpt_calculator_t *eqpt);
void	eqpt_init(eqpt_calculator_t *eqpt);
void	eqpt_print_derivative(eqpt_calculator_t *eqpt);
void	eqpt_print_derivative_2(eqpt_calculator_t *eqpt);
void	eqpt_print_estimate(int n, calcnode_t *estimate);
void	eqpt_print_estpt(eqpt_calculator_t *eqpt);
void	eqpt_routine(eqpt_calculator_t *eqpt);
void	eqpt_sort_volumes(eqpt_calculator_t *eqpt);
double	eqpt_derivative(calcnode_t *node);
calcnode_t	*eqpt_calc_derivatives_run(int n, calcnode_t *node);
calcnode_t	*calcnode_get_nbh(int n, calcnode_t *val);
calcnode_t	*calcnode_new(calcnode_t *new);
int	exit_print_help(char **av, int status);
int	fd_parse(eqpt_calculator_t *eqpt, FILE *fd);
double	step_compute(calcnode_t *node, calcnode_t *next);

#endif /* __TITRATION_H__ */
