/*
** EPITECH PROJECT, 2021
** map_infos.c
** File description:
** Returns map infos
*/

#include "my_runner.h"

int get_map_height(void)
{
    return ((RESOLUTION.HEIGHT - HUD.HEIGHT) / TILE.SIZE);
}

int get_map_width(char *filepath)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read = 0;
    int map_width = 0;
    int tmp_width = 0;

    fp = fopen(filepath, "r");
    while ((read = getline(&line, &len, fp)) != -1) {
        tmp_width = 0;
        for (int i = 0; line[i]; i++)
            if (is_digit(line[i]))
                tmp_width = i + 1;
        if (map_width < tmp_width)
            map_width = tmp_width;
    }
    if (line)
        free(line);
    fclose(fp);
    return (map_width);
}

void set_tiles(FILE *fp, char *line, ssize_t read, Game_State *game)
{
    size_t len = 0;

    for (int cur_y = 0; cur_y < game->map.height; cur_y++) {
        read = getline(&line, &len, fp);
        if (read == -1)
            break;
        for (int cur_x = 0; cur_x < (int) read; cur_x++) {
            if (is_digit(line[cur_x])) {
                game->map.tiles[cur_y][cur_x] = line[cur_x] - '0';
                game->map.tiles_number += 1;
            }
        }
    }
    if (line)
        free(line);
}

void allocate_tiles(FILE *fp, char *line, int map_width, Game_State *game)
{
    ssize_t read = 0;
    size_t len = 0;

    game->map.width = map_width;
    game->map.height = get_map_height();
    game->map.tiles = malloc(game->map.height * sizeof(int *));
    for (int cur_y = 0; cur_y < game->map.height; cur_y++) {
        game->map.tiles[cur_y] = malloc(game->map.width * sizeof(int));
        for (int cur_x = 0; cur_x < game->map.width; cur_x++)
            game->map.tiles[cur_y][cur_x] = -1;
    }
    set_tiles(fp, line, read, game);
}
