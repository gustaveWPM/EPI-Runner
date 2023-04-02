/*
** EPITECH PROJECT, 2021
** my_puterr_nb.c
** File description:
** Puts a number on stderr
*/

#include <unistd.h>

void my_puterr_nb(int nb)
{
    char num;
    char zero = '0';

    if (nb < 0)
        return;
    if (nb == 0) {
        write(2, &zero, 1);
        return;
    }
    if (nb / 10 != 0)
        my_puterr_nb(nb / 10);
    num = nb % 10 + '0';
    write(2, &num, 1);
}
