/*
** EPITECH PROJECT, 2020
** my_lib.h
** File description:
** Prototypes
*/

#ifndef MY_LIB_H
#define MY_LIB_H
int my_strlen(char const *str);
void my_putchar(char c);
void my_putstr(char const *str);
void my_puterr(char const *err);
int str_include_char(char *str, char c);
int str_equals(char *str, char *value);
void my_puterr_nb(int nb);
int is_digit(char c);
long long my_abs(long long nb);
#endif
