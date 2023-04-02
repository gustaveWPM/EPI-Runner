/*
** EPITECH PROJECT, 2021
** free.c
** File description:
** Dynamic Memory Freeing
*/

#include "my_runner.h"

void free_tiles(Game_State *game)
{
    int cur_y = 0;

    while (cur_y < game->map.height) {
        free(game->map.tiles[cur_y]);
        cur_y += 1;
    }
    free(game->map.tiles);
}

void free_parallaxes(Game_State *game)
{
    for (int id = 0; id < CONFIG.MAX_PARALLAXES; id++) {
        sfSprite_destroy(game->parallaxes[id].sprite);
        sfTexture_destroy(game->parallaxes[id].texture);
    }
}

void free_fogs(Game_State *game)
{
    for (int id = 0; id < CONFIG.MAX_FOGS; id++) {
        sfSprite_destroy(game->fogs[id].sprite);
        sfTexture_destroy(game->fogs[id].texture);
    }
}

void free_walls(Game_State *game)
{
    free(game->walls);
}

void free_player(Game_State *game)
{
    sfTexture_destroy(game->player.texture);
    sfSprite_destroy(game->player.sprite);
}
