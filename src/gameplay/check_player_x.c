/*
** EPITECH PROJECT, 2021
** check_player_x.c
** File description:
** Check Player X
*/

#include "my_runner.h"

void respawn_player(Game_State *game)
{
    float pos_x = CONFIG.START_POS_X - game->values.scroll_x;
    int ipos_x = 0;
    int ipos_y = CONFIG.START_POS_Y / TILE.SIZE;

    game->player.pos.x = pos_x;
    ipos_x = (int) (pos_x / 32);
    while (1) {
        if (ipos_x >= game->map.width) {
            ipos_y = 13;
            break;
        }
        if (tile_is_passable(game, ipos_x, ipos_y - 1))
            break;
        ipos_y -= 1;
    }
    game->player.pos.y = (ipos_y * TILE.SIZE) - TILE.SIZE;
}

void process_player_hurt(Game_State *game)
{
    game->player.lifes -= 1;
    if (game->player.lifes <= 0) {
        play_se(game, "death.wav", 100);
        return;
    }
    play_se(game, "hurt.wav", 100);
    respawn_player(game);
}

void check_player_death(Game_State *game, int player_screen_x)
{
    if (player_screen_x < (TILE.SIZE * -1) && !game->values.lap_transition)
        process_player_hurt(game);
}

void check_new_lap(Game_State *game) {
    int pos_x = game->player.pos.x;

    if (pos_x > ((game->map.width * TILE.SIZE) + RESOLUTION.WIDTH)) {
        play_se(game, "lap.wav", 80);
        new_lap(game);
    }
}

void check_player_x(Game_State *game)
{
    int player_screen_x = game->player.pos.x + game->values.scroll_x;

    check_player_death(game, player_screen_x);
    check_new_lap(game);
    if (game->player.pos.x > 0 && game->values.lap_transition)
        game->values.lap_transition = 0;
}
