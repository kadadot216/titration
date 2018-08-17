/*
** EPITECH PROJECT, 2018
** titration.h
** File description:
** Header file for 109titration
*/

#ifndef __TITRATION_H__
#define __TITRATION_H__

#include "types.h"

typedef struct	titration_val_s {
	double	volume;
	double	ph;
	struct titration_val_s	*next;
}	titration_val_t;

typedef struct	eqpt_calculator_s {
	titration_val_t	*input;
}	eqpt_calculator_t;


#endif /* __TITRATION_H__ */
