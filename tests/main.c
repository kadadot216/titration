/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** GDB Testing main
*/

#include "file.h"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	FILE	*fd = NULL;
	
	file_open(&fd, "values.csv", "r");
	file_print_ctnt(fd);
	return (0);
}
