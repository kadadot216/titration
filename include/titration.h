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

#define	MAX_DERIVATIVE	(3)

typedef struct	llval_s {
	double	value;
	struct llval_s	*n;
}	llval_t;

typedef struct	eqpt_calculator_s {
	llval_t	*volumes;
	llval_t	*phs;
	llval_t	*deriv_head[MAX_DERIVATIVE];
	llval_t	*est;
}	eqpt_calculator_t;

llval_t	*new_llval(void);
void	fd_parse(eqpt_calculator_t *eqpt, FILE *fd);
void	print_llval(llval_t *start);
void	print_titr_vals(llval_t *volume, llval_t *ph);
void	delete_llist(llval_t *start);
llval_t	*llval_get_nbh(int n, llval_t *val);
void	eqpt_print_derivative(eqpt_calculator_t *eqpt);
void	eqpt_print_derivative_2(eqpt_calculator_t *eqpt);
void	eqpt_get_derivatives(eqpt_calculator_t *eqpt);
void	eqpt_destroy(eqpt_calculator_t *eqpt);

#endif /* __TITRATION_H__ */
