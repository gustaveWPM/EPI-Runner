/*
** EPITECH PROJECT, 2021
** draw_parallaxes.c
** File description:
** Hard coded :(
*/

#include "my_runner.h"

void hard_coded_parallax_initializer(Game_State *game, int id)
{
    if (id == 0)
        game->parallaxes[0].x_speed = MOVESPEED_VALUES.BACKGROUND_SCROLL;
    if (id == 1)
        game->parallaxes[1].x_speed = -MOVESPEED_VALUES.SCROLL;
}

void hard_coded_parallax_drawer(Game_State *game, int id)
{
    sfRenderWindow_drawSprite(game->window, game->parallaxes[id].sprite, NULL);
}

void draw_parallaxes(Game_State *game)
{
    sfVector2f pos = {0, 0};
    for (int id = 0; id < CONFIG.MAX_PARALLAXES; id++) {
        game->parallaxes[id].x_offset += game->parallaxes[id].x_speed;
        pos.x = game->parallaxes[id].pos.x + game->parallaxes[id].x_offset;
        pos.y = game->parallaxes[id].pos.y;
        if (my_abs(pos.x) >= RESOLUTION.WIDTH) {
            pos.x = 0;
            game->parallaxes[id].x_offset = 0;
        }
        sfSprite_setTexture(game->parallaxes[id].sprite,
                            game->parallaxes[id].texture, sfFalse);
        sfSprite_setPosition(game->parallaxes[id].sprite, pos);
        hard_coded_parallax_drawer(game, id);
    }
}
