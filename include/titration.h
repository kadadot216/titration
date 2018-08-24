/*
** EPITECH PROJECT, 2018
** titration.h
** File description:
** Header file for 109titration
*/

#ifndef __TITRATION_H__
#define __TITRATION_H__

#include <stdio.h>
#include "types.h"

#define	MAX_DERIVATIVE	(2)

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

calcnode_t	*calcnode_new(void);
void	fd_parse(eqpt_calculator_t *eqpt, FILE *fd);
void	print_calcnode(calcnode_t *start);
void	print_titr_vals(calcnode_t *node);
void	calclist_delete(calcnode_t *start);
calcnode_t	*calcnode_get_nbh(int n, calcnode_t *val);
void	eqpt_print_derivative(eqpt_calculator_t *eqpt);
void	eqpt_print_derivative_2(eqpt_calculator_t *eqpt);
void	eqpt_get_derivatives(eqpt_calculator_t *eqpt);
void	eqpt_print_estpt(eqpt_calculator_t *eqpt);
void	eqpt_destroy(eqpt_calculator_t *eqpt);
void	eqpt_print_estimate(int n, calcnode_t *estimate);
void	eqpt_init(eqpt_calculator_t *eqpt);
void	eqpt_sort_volumes(eqpt_calculator_t *eqpt);

#endif /* __TITRATION_H__ */
