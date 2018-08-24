/*
** EPITECH PROJECT, 2018
** file.c
** File description:
** Filename
*/

#include "file.h"

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

FILE	*file_open(char const *filename, char const *mode)
{
	FILE	*fd = NULL;

	if (!file_has_extension(filename, DATA_EXT)) {
		return (NULL);
	}
	fd = fopen(filename, mode);
	if (fd == NULL)
		return (NULL);
	else
		return (fd);
}
