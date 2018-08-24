/*
** EPITECH PROJECT, 2018
** unit_testing.h
** File description:
** Header file for Unit testing functions
*/

#ifndef __UNIT_TESTING_H__
#define __UNIT_TESTING_H__

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "titration.h"

#define	T_DERIV1BUFF ("Derivative:\n"		\
"volume: 2 ml -> 1.00\n"	\
"volume: 3 ml -> 0.47\n"	\
"volume: 5 ml -> 0.20\n"	\
"volume: 6 ml -> 0.80\n"	\
"volume: 7 ml -> 1.47\n"	\
"volume: 7.5 ml -> 2.00\n"	\
"volume: 8 ml -> 2.13\n"	\
"volume: 9 ml -> 0.83\n"	\
"volume: 12 ml -> 0.29\n"	\
"volume: 14 ml -> 0.07\n"	\
"volume: 16 ml -> 0.06\n")

#define	T_DERIV2BUFF ("\nSecond derivative:\n"	\
"volume: 3 ml -> -0.27\n"	\
"volume: 5 ml -> 0.11\n"	\
"volume: 6 ml -> 0.63\n"	\
"volume: 7 ml -> 0.80\n"	\
"volume: 7.5 ml -> 0.67\n"	\
"volume: 8 ml -> -0.78\n"	\
"volume: 9 ml -> -0.46\n"	\
"volume: 12 ml -> -0.15\n"	\
"volume: 14 ml -> -0.06\n")

#define	T_FILEBUFF ("1;2\n"	\
"2;3\n"		\
"3;4\n"		\
"5;4.4\n"	\
"6;4.6\n"	\
"7;6\n"		\
"7.5;6.8\n"	\
"8;8\n"		\
"9;10\n"	\
"12;11.3\n"	\
"14;11.46\n"	\
"16;11.6\n"	\
"20;11.8\n\n")

void	redirect_all_std(void);
void	print_2nd_derivative(void);
void	print_calcnode(calcnode_t *start);
void	print_titr_vals(calcnode_t *node);
double	eqpt_derivative_old(int counter, double *phs, double *volumes);

#endif /* __UNIT_TESTING_H__ */
