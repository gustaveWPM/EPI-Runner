/*
** EPITECH PROJECT, 2021
** draw_game_spriteset.c
** File description:
** Draw the game Spriteset
*/

#include "my_runner.h"

void initialize_game_spriteset(Game_State *game)
{
    allocate_parallaxes(game);
    allocate_player(game);
    allocate_fogs(game);
}

void update_game_spriteset(Game_State *game)
{
    draw_parallaxes(game);
    draw_map(game);
    draw_player(game);
    draw_fogs(game);
    draw_walls(game);
}
