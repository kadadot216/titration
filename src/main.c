/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main file for 109titration
*/

#include "file.h"
#include "titration.h"

int	main(int ac, char **av)
{
	FILE	*fd = NULL;
	eqpt_calculator_t	eqpt;

	if ((ac != 2) || (!file_open(&fd, av[1], OPEN_MODE))) {
		return (exit_print_help(av, 84));
	}
	if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
		return (exit_print_help(av, 0));
	}
	eqpt_init(&eqpt);
	fd_parse(&eqpt, fd);
	fclose(fd);
	eqpt_routine(&eqpt);
	eqpt_destroy(&eqpt);
	return (0);
}
