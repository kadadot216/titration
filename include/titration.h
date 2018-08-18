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

typedef struct	titration_val_s {
	double	volume;
	double	ph;
	struct titration_val_s	*next;
}	titration_val_t;

typedef struct	eqpt_calculator_s {
	titration_val_t	*start;
}	eqpt_calculator_t;

void	parse_fd(eqpt_calculator_t *, FILE *fd);
void	print_titra_values(titration_val_t *start);
titration_val_t	*new_tval(titration_val_t *new);
void	print_titra_values(titration_val_t *start);
void	parse_fd(eqpt_calculator_t *eqpt, FILE *fd);
void	print_titra_values(titration_val_t *start);

#endif /* __TITRATION_H__ */
