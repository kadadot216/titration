/*
** EPITECH PROJECT, 2018
** file.c
** File description:
** Filename
*/

#include "file.h"

void	file_print_ctnt(FILE *fd)
{
	char	*str = NULL;
	size_t	n = 0;

	while (getline(&str, &n, fd) != -1) {
		printf("%s", str);
	}
	free(str);
}

int	file_open(FILE **fd, char const *filename, char const *mode)
{
	*fd = fopen(filename, mode);

	if (fd == NULL)
		return (0);
	else
		return (1);
}

int	file_has_extension(char const *filename, char const *ext)
{
	uint_t	csor = 0;

	while (filename[csor] != '\0' && filename[csor] != '.') {
		csor++;
	}
	if (filename[csor] == '\0') {
		return (0);
	}
	csor++;
	if (strcmp(&filename[csor], ext) == 0) {
		return (1);
	}
	return (0);
}
