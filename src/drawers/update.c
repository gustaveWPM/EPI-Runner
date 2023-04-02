/*
** EPITECH PROJECT, 2021
** update.c
** File description:
** Update functions
*/

#include "my_runner.h"

void update_score(Game_State *game)
{
    game->values.playing_elapsed_frames %= GAMEPLAY.SCORE_DELAY_BONUS_DURATION;
    if (!game->values.playing_elapsed_frames) {
        game->values.score += GAMEPLAY.SCORE_DELAY_BONUS;
    }
}

void update(Game_State *game)
{
    update_game_spriteset(game);
    update_score(game);
    sfRenderWindow_display(game->window);
    sfRenderWindow_clear(game->window, sfBlack);
}
