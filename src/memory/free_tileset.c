/*
** EPITECH PROJECT, 2021
** free_tileset.c
** File description:
** Free Tileset
*/

#include "my_runner.h"

void free_tileset(Game_State *game)
{
    sfSprite_destroy(game->tileset.sprite);
    sfTexture_destroy(game->tileset.texture);
}
