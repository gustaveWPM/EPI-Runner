/*
** EPITECH PROJECT, 2021
** load_map.c
** File description:
** Map Loader
*/

#include "my_runner.h"

void allocate_tileset(Game_State *game)
{
    game->tileset.sprite = sfSprite_create();
    game->tileset.texture = sfTexture_createFromFile(
        "Assets/Graphics/Tilesets/tileset.png", NULL);
    sfSprite_setTexture(game->tileset.sprite,
                        game->tileset.texture, sfFalse);
}

void initialize_tileset(Game_State *game)
{
    sfVector2f pos = {0, 0};
    sfTexture *texture;
    sfSprite *sprite;

    allocate_tileset(game);
}

void load_map(Game_State *game, char **map)
{
    initialize_tiles(game, map[1]);
    initialize_walls(game);
    initialize_parallaxes(game);
    initialize_fogs(game);
    initialize_tileset(game);
}
