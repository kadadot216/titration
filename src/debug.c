/*
** EPITECH PROJECT, 2018
** prnting.c
** File description:
** Debugging related functions
*/

#include "titration.h"
#include "file.h"

void	print_titra_values(titration_val_t *start)
{
	titration_val_t	*tmp = start;

	while ((tmp) && tmp->next != NULL) {
		printf("%g%c%g\n", tmp->volume, DATA_SEP, tmp->ph);
		tmp = tmp->next;
	}
}
