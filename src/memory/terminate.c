/*
** EPITECH PROJECT, 2020
** terminate.c
** File description:
** Terminate the program
*/

#include "my_runner.h"

void terminate(Game_State *game)
{
    sfRenderWindow_destroy(game->window);
    if (game->audio.bgm)
        sfMusic_destroy(game->audio.bgm);
    if (game->audio.se)
        sfMusic_destroy(game->audio.se);
    free_fogs(game);
    free_player(game);
    free_parallaxes(game);
    free_tiles(game);
    free_walls(game);
    free_tileset(game);
}
