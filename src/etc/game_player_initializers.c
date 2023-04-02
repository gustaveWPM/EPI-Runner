/*
** EPITECH PROJECT, 2021
** game_player_initializers.c
** File description:
** Game Player Initializers
*/

#include "my_runner.h"

void set_player_jumping_anim(Game_State *game)
{
    if (game->player.spritesheet_index == 1) {
        game->player.frame = 0;
        return;
    }
    game->player.spritesheet_index = 1;
    game->player.anim_frame_amount = 4;
    game->player.frame = 0;
    sfTexture_destroy(game->player.texture);
    sfSprite_destroy(game->player.sprite);
    game->player.sprite = sfSprite_create();
    game->player.texture = sfTexture_createFromFile(
        "Assets/Graphics/Characters/player_jumping.png", NULL);
    sfSprite_setTexture(game->player.sprite, game->player.texture, sfFalse);
    sfRenderWindow_drawSprite(game->window, game->player.sprite, NULL);
    game->player.spritesheet_index = 1;
}

void set_player_walking_anim(Game_State *game)
{
    if (game->player.spritesheet_index == 0)
        return;
    game->player.spritesheet_index = 0;
    game->player.anim_frame_amount = 2;
    game->player.frame = 0;
    sfTexture_destroy(game->player.texture);
    sfSprite_destroy(game->player.sprite);
    game->player.sprite = sfSprite_create();
    game->player.texture = sfTexture_createFromFile(
        "Assets/Graphics/Characters/player_walking.png", NULL);
    sfSprite_setTexture(game->player.sprite, game->player.texture, sfFalse);
    sfRenderWindow_drawSprite(game->window, game->player.sprite, NULL);
    game->player.spritesheet_index = 0;
}

void initialize_game_player(Game_State *game)
{
    game->player.pos.x = CONFIG.START_POS_X;
    game->player.pos.y = CONFIG.START_POS_Y;
    game->player.dy = 0;
    game->player.jumps = 0;
    game->player.lifes = 3;
    game->player.sprite = NULL;
    game->player.texture = NULL;
    game->player.anim_frame_amount = 2;
    game->player.frame = 0;
    game->player.spritesheet_index = 0;
}
