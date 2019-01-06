/*
** EPITECH PROJECT, 2018
** str_compare.c
** File description:
** compare 2 strings
*/

int str_compare(const char *s1, const char *s2)
{
    for (; *s1 && *s2 && *s1 == *s2; s1++, s2++);
    return (unsigned char)(*s1) - (unsigned char)(*s2);
}
