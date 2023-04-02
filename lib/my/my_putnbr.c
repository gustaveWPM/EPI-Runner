/*
** EPITECH PROJECT, 2021
** my_putnbr.c
** File description:
** Puts a number on stdout
*/

#include <unistd.h>

void my_putnbr(int nb)
{
    char num;
    char zero = '0';

    if (nb < 0)
        return;
    if (nb == 0) {
        write(1, &zero, 1);
        return;
    }
    if (nb / 10 != 0)
        my_putnbr(nb / 10);
    num = nb % 10 + '0';
    write(1, &num, 1);
}
