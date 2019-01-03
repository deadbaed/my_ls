/*
** EPITECH PROJECT, 2018
** len_str
** File description:
** gets the length of a string (including '\0')
*/

int len_str(const char *str)
{
    int i = 0;

    for (; str[i]; i++);
    return i + 1;
}
