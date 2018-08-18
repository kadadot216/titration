/*
** EPITECH PROJECT, 2018
** prnting.c
** File description:
** Debugging related functions
*/

#include "titration.h"
#include "file.h"

void	print_titr_vals(llval_t *volume, llval_t *ph)
{
	llval_t	*phcs = ph;
	llval_t	*volcs = volume;

	while (phcs->n != NULL && volcs->n != NULL) {
		printf("%g%c%g\n", volcs->value, DATA_SEP, phcs->value);
		volcs = volcs->n;
		phcs = phcs->n;
	}
}
