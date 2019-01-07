/*
** EPITECH PROJECT, 2018
** include/my_ls
** File description:
** try not to segfault, good luck :)
*/

#ifndef MY_LS_H
#define MY_LS_H

#include <dirent.h> /* for directory stuff */
#include <sys/stat.h> /* for stat structure and function */
#include "library.h" /* for the std lib */

#ifndef EXIT_OKAY
#define EXIT_OKAY (0)
#endif

#ifndef EXIT_ERROR
#define EXIT_ERROR (84)
#endif

/* directory.c */
void directory(char *path);

/* ls/no_flags.c */
int ls_no_flags(char *path);

/* ls/flag_l.c */
int ls_flag_l(char *path);

#endif
