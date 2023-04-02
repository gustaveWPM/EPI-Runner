/*
** EPITECH PROJECT, 2021
** game_loop.c
** File description:
** Game Loop
*/

#include "my_runner.h"

int process_game_over_events(Game_State *game)
{
    sfEvent event;

    if (sfRenderWindow_pollEvent(game->window, &event)) {
        if (wait_for_player_input(game))
            return (0);
        else
            game_restart(game);
    }
    return (1);
}

int process_game_events(Game_State *game)
{
    sfEvent event;

    if (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed)
            return (0);
        input_manager(game);
    }
    return (1);
}

int process_events(Game_State *game)
{
    if (game->player.lifes > 0)
        return (process_game_events(game));
    else
        return (process_game_over_events(game));
}

void game_loop(Game_State *game)
{
    while (process_events(game)) {
        if (!game->pause.paused && game->player.lifes > 0) {
            process_physics(game);
            process_collisions(game);
            update(game);
            game->values.scroll_x -= MOVESPEED_VALUES.SCROLL;
            character_move_right(&game->player);
            check_player_x(game);
        }
        game->values.elapsed_frames += 1;
        if (!game->pause.paused)
            game->values.playing_elapsed_frames += 1;
    }
    sfRenderWindow_close(game->window);
}
