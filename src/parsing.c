/*
** EPITECH PROJECT, 2018
** parsing.c
** File description:
** Parsing related functions
*/

#include "titration.h"

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

static void	set_calcnode(calcnode_t *calcnode, double vol, double ph)
{
	calcnode->vol = vol;
	calcnode->ph = ph;
}

static void	set_calcnodestimater(calcnode_t *calcnode, char *line)
{
	int	delim_i = 0;

	delim_i = find_delim_i(line, DATA_SEP);
	set_calcnode(calcnode, (atof(line)), (atof(&line[delim_i + 1])));
	delim_i = 0;
}

void	fd_parse(eqpt_calculator_t *eqpt, FILE *fd)
{
	char	*line = NULL;
	size_t	n = 0;
	calcnode_t	*csor = NULL;
	calcnode_t	*prev = NULL;

	eqpt->start = calcnode_new(eqpt->start);
	csor = eqpt->start;
	while (getline(&line, &n, fd) != -1) {
		set_calcnodestimater(csor, line);
		prev = csor;
		csor = csor->n;
		csor = calcnode_new(csor);
		prev->n = csor;
	}
	free(line);
	prev = NULL;
	csor = NULL;
}
