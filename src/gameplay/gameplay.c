/*
** EPITECH PROJECT, 2021
** gameplay.c
** File description:
** Gameplay functions
*/

#include "my_runner.h"

void player_actions_handler(sfEvent input, Game_State *game)
{
    if (input.type == sfEvtKeyPressed) {
        switch (input.key.code) {
        case (sfKeySpace):
            if (game->player.dy >= 0 && game->player.jumps < 2) {
                game->player.dy = -5;
                game->player.jumps += 1;
                set_player_jumping_anim(game);
                play_se(game, "jump.wav", 100);
            }
            break;
        case (sfKeyF12):
            game_restart(game);
            break;
        }
    }
}

void player_movements_handler(sfEvent input, Game_Actor *player)
{
    return;
    if (input.type == sfEvtKeyPressed) {
        switch (input.key.code) {
        case (sfKeyUp):
            character_move_up(player);
            break;
        case (sfKeyDown):
            character_move_down(player);
            break;
        case (sfKeyLeft):
            character_move_left(player);
            break;
        case (sfKeyRight):
            character_move_right(player);
            break;
        }
    }
}

void toggle_pause(Game_State *game)
{
    long long pause_delta = game->values.elapsed_frames;
    long long elapsed_frames = game->pause.elapsed_frames;

    if (game->player.lifes <= 0)
        return;
    if (game->pause.paused) {
        game->pause.paused = 0;
    } else {
        if (my_abs(elapsed_frames - pause_delta) < GAMEPLAY.PAUSE_DELAY)
            return;
        game->pause.paused = 1;
        play_se(game, "pause.wav", 100);
    }
    game->pause.elapsed_frames = game->values.elapsed_frames;
}

void pause_handler(sfEvent input, Game_State *game)
{
    if (input.type == sfEvtKeyPressed) {
        switch (input.key.code) {
        case (sfKeyEscape):
            if (!game->pause.paused)
                toggle_pause(game);
            break;
        }
    }
    if (input.type == sfEvtMouseButtonPressed && game->pause.paused) {
        toggle_pause(game);
    }
}

void input_manager(Game_State *game)
{
    sfEvent ev;

    pause_handler(ev, game);
    if (!game->pause.paused) {
        player_movements_handler(ev, &game->player);
        player_actions_handler(ev, game);
    }
}
