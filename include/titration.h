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

typedef struct	llval_s {
	double	value;
	struct llval_s	*n;
}	llval_t;

typedef struct	eqpt_calculator_s {
	llval_t		*volumes;
	llval_t		*phs;
	llval_t		*deriv_head[MAX_DERIVATIVE];
}	eqpt_calculator_t;

llval_t	*new_llval(llval_t *new);
void	fd_parse(eqpt_calculator_t *eqpt, FILE *fd);
void	print_llval(llval_t *start);
void	print_titr_vals(llval_t *volume, llval_t *ph);

#endif /* __TITRATION_H__ */
