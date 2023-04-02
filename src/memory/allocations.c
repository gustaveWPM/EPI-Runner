/*
** EPITECH PROJECT, 2021
** allocations.c
** File description:
** Dynamic Memory Allocations
*/

#include "my_runner.h"

void allocate_player(Game_State *game)
{
    sfVector2f player_sprite_scale = {1, 1};
    sfVector2f player_sprite_size = {TILE.SIZE, TILE.SIZE};

    game->player.sprite = sfSprite_create();
    game->player.texture = sfTexture_createFromFile(
        "Assets/Graphics/Characters/player_walking.png", NULL);
    sfSprite_setTexture(game->player.sprite, game->player.texture, sfFalse);
    sfRenderWindow_drawSprite(game->window, game->player.sprite, NULL);
}

void allocate_walls(Game_State *game)
{
    game->walls = malloc(game->map.tiles_number * sizeof(Wall));
}

void allocate_parallaxes(Game_State *game)
{
    for (int id = 0; id < CONFIG.MAX_PARALLAXES; id++) {
        game->parallaxes[id].sprite = sfSprite_create();
        if (id == 0)
            game->parallaxes[id].texture = sfTexture_createFromFile(
                "Assets/Graphics/Parallaxes/background.png", NULL);
        if (id == 1)
            game->parallaxes[id].texture = sfTexture_createFromFile(
                "Assets/Graphics/Parallaxes/ground.png", NULL);
    }
}

void allocate_fogs(Game_State *game)
{
    for (int id = 0; id < CONFIG.MAX_PARALLAXES; id++) {
        game->fogs[id].sprite = sfSprite_create();
        if (id == 0)
            game->fogs[id].texture = sfTexture_createFromFile(
                "Assets/Graphics/Fogs/fog.png", NULL);
    }
}
