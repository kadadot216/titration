/*
** EPITECH PROJECT, 2018
** file.h
** File description:
** Header file for file related functions
*/

#ifndef __FILE_H__
#define __FILE_H__

#include "types.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define	DATA_EXT	("csv")
#define	OPEN_MODE	("r")
#define	DATA_SEP	(';')

void	file_print_ctnt(FILE *fd);
int	file_has_extension(char const *filename, char const *ext);
int	file_open(FILE **fd, char const *filename, char const *mode);

#endif /* __FILE_H__ */
