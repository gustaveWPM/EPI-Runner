/*
** EPITECH PROJECT, 2020
** set_path.c
** File description:
** Dynamic path representation
*/

#include "my_runner.h"

void set_path(char *path, char *folder, char *filename)
{
    int i = 0;
    int j = 0;

    while (folder[i] != '\0') {
        path[i] = folder[i];
        i += 1;
    }
    while (filename[j] != '\0') {
        path[i] = filename[j];
        j += 1;
        i += 1;
    }
    path[i] = '\0';
}
