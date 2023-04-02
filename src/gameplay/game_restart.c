/*
** EPITECH PROJECT, 2021
** game_restart.c
** File description:
** Restarts game
*/

#include "my_runner.h"

void new_lap(Game_State *game) {
    int delta_x = RESOLUTION.WIDTH * -1;

    game->values.scroll_x = 0 - delta_x;
    game->player.pos.x = CONFIG.START_POS_X + delta_x;
    game->values.laps += 1;
    game->values.lap_transition = 1;
    game->player.lifes += 1;
    game->values.score += GAMEPLAY.LAP_BONUS;
}

void game_restart(Game_State *game) {
    game->values.scroll_x = 0;
    game->values.elapsed_frames = 0;
    game->values.playing_elapsed_frames = 0;
    game->player.pos.x = CONFIG.START_POS_X;
    game->player.pos.y = CONFIG.START_POS_Y;
    game->player.dy = 0;
    game->player.jumps = 0;
    game->player.lifes = 3;
    game->pause.elapsed_frames = 0;
    game->pause.paused = 0;
}
