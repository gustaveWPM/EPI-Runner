/*
** EPITECH PROJECT, 2021
** map_checker.c
** File description:
** Checks the map
*/

#include "my_runner.h"

int file_is_empty(FILE *fp, char *filepath)
{
    FILE *fp_checker;
    char *line_checker;
    size_t len_checker;
    ssize_t read = 0;

    fp_checker = fopen(filepath, "r");
    read = getline(&line_checker, &len_checker, fp_checker);
    fclose(fp_checker);
    if (line_checker)
        free(line_checker);
    if (read == -1) {
        fclose(fp);
        my_puterr(ERRORS_VOCAB.EMPTY_MAP_FILE);
        return (1);
    }
    return (0);
}

int file_is_unreadable(FILE *fp, char *filepath)
{
    if (fp == NULL) {
        my_puterr(ERRORS_VOCAB.FILE_IS_UNREADABLE);
        return (1);
    }
    return (0);
}

int allowed_map_chars(char *line, int len)
{
    int i = 0;

    while (i < len) {
        if ((line[i] != ' ') && (line[i] != '\n') && (!is_digit(line[i])))
            return (0);
        i++;
    }
    return (1);
}

int map_checker(FILE *fp, char *line, size_t len, ssize_t read)
{
    int cur_line = 0;
    int failed = 0;

    while ((read = getline(&line, &len, fp)) != -1) {
        cur_line += 1;
        if (!allowed_map_chars(line, (int) read)) {
            my_puterr(ERRORS_VOCAB.FORBIDDEN_MAP_CHARS);
            failed = 1;
            break;
        }
    }
    if (!failed && cur_line > CONFIG.TILE_PLAYABLE_HEIGHT) {
        my_puterr(ERRORS_VOCAB.INVALID_HEIGHT);
        failed = 1;
    }
    if (line)
        free(line);
    return (failed);
}

int invalid_mapfile(char *filepath)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read = 0;
    int return_value = 0;

    fp = fopen(filepath, "r");
    if (file_is_unreadable(fp, filepath) || file_is_empty(fp, filepath))
        return (1);
    return_value = map_checker(fp, line, len, read);
    fclose(fp);
    return (return_value);
}
