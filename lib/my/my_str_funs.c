/*
** EPITECH PROJECT, 2020
** my_str_funs.c
** File description:
** String Functions
*/

#include <unistd.h>

int my_strlen(char const *str)
{
    int len = 0;
    if (str == NULL)
        return (0);
    while (str[len] != '\0')
        len += 1;
    return (len);
}

void my_putstr(char const *str)
{
    if (str == NULL)
        return;
    write(1, str, my_strlen(str));
}

void my_puterr(char const *err)
{
    if (err == NULL)
        return;
    write(2, err, my_strlen(err));
}

int str_equals(char *str, char *value)
{
    int str_len = my_strlen(str);
    int value_len = my_strlen(value);
    int i = 0;

    if (str_len != value_len)
        return (0);
    while (str[i] != '\0') {
        if (str[i] != value[i])
            return (0);
        i += 1;
    }
    return (1);
}

int is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}
