/*
** EPITECH PROJECT, 2018
** src/ls/no_flags.c
** File description:
** try not to segfault, good luck :)
*/

#include "my_ls.h"

void no_flags_directory(char *path)
{
    DIR *fs_dir = opendir(path);
    struct dirent *dir = readdir(fs_dir);
    char *content_name;

    for (; dir; dir = readdir(fs_dir)) {
        content_name = dir->d_name;
        (content_name[0] != '.') ? put_str_n(content_name) : 0;
    }
    closedir(fs_dir);
}

int ls_no_flags(struct stat st, char *path)
{
    if (!(S_ISDIR(st.st_mode)))
        put_str_n(path);
    else
        no_flags_directory(path);
    return EXIT_OKAY;
}
