/*
** EPITECH PROJECT, 2018
** directory
** File description:
** try not to segfault, good luck :)
*/

#include "my_ls.h"

void directory(char *path)
{
    DIR *fs_dir = opendir(path);
    struct dirent *dir = readdir(fs_dir);
    char *content_name;

    for (; dir; dir = readdir(fs_dir)) {
        content_name = dir->d_name;
        put_str_n(content_name);
    }
}
