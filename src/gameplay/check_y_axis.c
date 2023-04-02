/*
** EPITECH PROJECT, 2021
** check_y_axis.c
** File description:
** Y axis checking
*/

#include "my_runner.h"

void check_max_y(Game_State *game)
{
    if (game->player.pos.y > (GAMEPLAY.PLAYABLE_HEIGHT - TILE.SIZE)) {
        game->player.pos.y = GAMEPLAY.PLAYABLE_HEIGHT - TILE.SIZE;
        game->player.dy = 0;
        game->player.jumps = 0;
        set_player_walking_anim(game);
    }
}

void check_min_y(Game_State *game)
{
    if (game->player.pos.y < 0) {
        game->player.pos.y = 0;
    }
}
