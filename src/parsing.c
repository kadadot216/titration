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

static void	get_llval(llval_t *llval, double value)
{
	llval->value = value;
}

static void	get_llvalstr(llval_t *llval, char *line)
{
	get_llval(llval, (atof(line)));
}

void	fd_parse(eqpt_calculator_t *eqpt, FILE *fd)
{
	char	*line = NULL;
	size_t	n = 0;
	llval_t	*volume = NULL;
	llval_t	*ph = NULL;
	llval_t	*prev = NULL;
	int	delim_i = 0;

	eqpt->volumes = new_llval();
	eqpt->phs = new_llval();
	volume = eqpt->volumes;
	ph = eqpt->phs;
	while (getline(&line, &n, fd) != -1) {
		delim_i = find_delim_i(line, DATA_SEP);
		get_llvalstr(volume, line);
		prev = volume;
		volume = volume->n;
		volume = new_llval();
		prev->n = volume;
		get_llvalstr(ph, &line[delim_i + 1]);
		prev = ph;
		ph = ph->n;
		ph = new_llval();
		prev->n = ph;
	}
	free(line);
	prev = NULL;
	ph = NULL;
	volume = NULL;
}
