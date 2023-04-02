/*
** EPITECH PROJECT, 2021
** draw_fogs.c
** File description:
** Hard coded :(
*/

#include "my_runner.h"

void hard_coded_fog_initializer(Game_State *game, int id)
{
    if (id == 0)
        game->fogs[id].x_speed = MOVESPEED_VALUES.FOREGROUND_SCROLL;
}

void hard_coded_fog_drawer(Game_State *game, int id)
{
    sfRenderWindow_drawSprite(game->window, game->fogs[id].sprite, NULL);
}

void draw_fogs(Game_State *game)
{
    sfVector2f pos = {0, 0};
    for (int id = 0; id < CONFIG.MAX_FOGS; id++) {
        game->fogs[id].x_offset += game->fogs[id].x_speed;
        pos.x = game->fogs[id].pos.x + game->fogs[id].x_offset;
        pos.y = game->fogs[id].pos.y;
        if (my_abs(pos.x) >= RESOLUTION.WIDTH) {
            pos.x = 0;
            game->fogs[id].x_offset = 0;
        }
        sfSprite_setTexture(game->fogs[id].sprite,
                            game->fogs[id].texture, sfFalse);
        sfSprite_setPosition(game->fogs[id].sprite, pos);
        hard_coded_fog_drawer(game, id);
    }
}
