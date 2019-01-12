/*
** EPITECH PROJECT, 2018
** library/str_dup_cat_path
** File description:
** try not to segfault, good luck :)
*/

#include <stdlib.h> /* for malloc */
#include "library.h" /* for len_str */

char *str_dup_cat_path(const char *path, const char *name)
{
    int i = 0;
    char *str = malloc(sizeof(char) * (len_str(path) + len_str(name)));

    if (!str)
        return NULL;
    for (; path[i]; i++)
        str[i] = path[i];
    str[i] = '/';
    i++;
    for (int j = 0; name[j]; i++, j++)
        str[i] = name[j];
    str[i] = '\0';
    return str;
}
