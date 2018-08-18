/*
** EPITECH PROJECT, 2018
** titration.c
** File description:
** Titration related funcs
*/

#include <stdlib.h>
#include "types.h"
#include "titration.h"

static void	tval_init(titration_val_t *tval)
{
	tval->ph = 0.0;
	tval->volume = 0.0;
	tval->next = NULL;
}

titration_val_t	*new_tval(titration_val_t *new)
{
	new = malloc(sizeof(titration_val_t));
	
	if (!new) {
		return (NULL);
	}
	tval_init(new);
	return (new);
}
