/*
** EPITECH PROJECT, 2021
** tiles_passabilities.c
** File description:
** Tiles passabilities
*/

#include "my_runner.h"

int is_tile(Game_State *game, int x, int y)
{
    if (game->map.tiles[y][x] != -1)
        return (1);
    return (0);
}

int tile_is_passable(Game_State *game, int x, int y)
{
    if (game->map.tiles[y][x] >= 0)
        return (0);
    return (1);
}
