/*
** EPITECH PROJECT, 2018
** file.c
** File description:
** Filename
*/

#include "file.h"

FILE	*file_open(char const *filename, char const *mode)
{
	FILE	*fd = NULL;

	fd = fopen(filename, mode);
	if (fd == NULL)
		return (NULL);
	else
		return (fd);
}
