/*
** EPITECH PROJECT, 2021
** drawers.c
** File description:
** Dynamic Drawers
*/

#include "my_runner.h"

void draw_map(Game_State *game)
{
    int x = 0;
    int y = 0;
    sfVector2f pos = {0, 0};
    sfIntRect mask = {0, 0, TILE.SIZE, TILE.SIZE};

    for (y = 0; y < game->map.height; y++) {
        for (x = 0; x < game->map.width; x++) {
            if (is_tile(game, x, y)) {
                pos.x = (x * TILE.SIZE) + game->values.scroll_x;
                pos.y = (y * TILE.SIZE);
                mask.left = TILE.SIZE * game->map.tiles[y][x];
                sfSprite_setTextureRect(game->tileset.sprite, mask);
                sfSprite_setPosition(game->tileset.sprite, pos);
                sfRenderWindow_drawSprite(game->window,
                                          game->tileset.sprite, NULL);
            }
        }
    }
}

void draw_walls(Game_State *game)
{
    sfVector2f pos = {0, 0};

    for (int id = 0; id < game->map.tiles_number; id++) {
        pos.x = game->walls[id].pos.x;
        pos.y = game->walls[id].pos.y;
        pos.x += game->values.scroll_x;
    }
}

void draw_player(Game_State *game)
{
    sfSprite *player_sprite = game->player.sprite;
    sfVector2f player_pos = game->player.pos;
    sfIntRect mask = {0, 0, TILE.SIZE, TILE.SIZE};

    if (game->values.playing_elapsed_frames % GAMEPLAY.ANIM_SPEED == 0) {
        game->player.frame += 1;
        game->player.frame %= game->player.anim_frame_amount;
    }
    mask.left = TILE.SIZE * game->player.frame;
    sfSprite_setTextureRect(game->player.sprite, mask);
    player_pos.x += game->values.scroll_x;
    sfSprite_setPosition(player_sprite, player_pos);
    sfRenderWindow_drawSprite(game->window, player_sprite, NULL);
}
