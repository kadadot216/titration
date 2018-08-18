/*
** EPITECH PROJECT, 2018
** parsing.c
** File description:
** Parsing related functions
*/

#include <stdlib.h>
#include "titration.h"
#include "file.h"

static int	find_delim_i(char const *str, char const d)
{
	uint_t	i = 0;
	uint_t	delim_i = 0;

	while (str[i] != '\0' && str[i] != d) {
		i++;
	}
	delim_i = i;
	return (delim_i);
}

static void	parse_titra_vals(titration_val_t *tval, char *line)
{
	uint_t	delim_i = 0;

	delim_i = find_delim_i(line, DATA_SEP);
	line[delim_i] = '\0';
	tval->volume = atof(line);
	line[delim_i] = DATA_SEP;
	tval->ph = atof(&line[delim_i + 1]);
}

void	parse_fd(eqpt_calculator_t *eqpt, FILE *fd)
{
	char	*line = NULL;
	size_t	n = 0;
	titration_val_t	*cursor = NULL;
	titration_val_t	*prev = NULL;

	eqpt->start = new_tval(eqpt->start);
	cursor = eqpt->start;
	while (getline(&line, &n, fd) != -1) {
		parse_titra_vals(cursor, line);
		prev = cursor;
		cursor = cursor->next;
		cursor = new_tval(cursor);
		prev->next = cursor;
	}
	free(line);
}
