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
#include <stdlib.h> /* for malloc, free */
#include <pwd.h> /* for password file entry */
#include <grp.h> /* for group file entry */
#include <time.h> /* for ctime */
#include "library.h" /* for the std lib */

#ifndef EXIT_OKAY
#define EXIT_OKAY (0)
#endif

#ifndef EXIT_ERROR
#define EXIT_ERROR (84)
#endif

/* ls/no_flags.c */
int ls_no_flags(struct stat st, char *path, char *flag);
int no_flags_directory(char *path, char *flag);

/* ls/flag_l.c */
int ls_flag_l(struct stat st);

#endif
