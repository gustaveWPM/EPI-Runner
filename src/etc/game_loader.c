/*
** EPITECH PROJECT, 2021
** game_loader.c
** File description:
** Game Loader
*/

#include "my_runner.h"

int wait_for_player_input(Game_State *game)
{
    sfEvent inputs;

    while (1) {
        if (sfRenderWindow_pollEvent(game->window, &inputs)) {
            if (inputs.type == sfEvtKeyPressed)
                return (0);
            if (inputs.type == sfEvtClosed)
                return (1);
        }
    }
}

int wait_for_player_input_screen(Game_State *game)
{
    sfTexture *texture;
    sfSprite *sprite;
    int terminate = 0;

    sprite = sfSprite_create();
    texture = sfTexture_createFromFile(
        "Assets/Graphics/Pictures/press_any_key.png", NULL);
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfRenderWindow_drawSprite(game->window, sprite, NULL);
    sfRenderWindow_display(game->window);
    terminate = wait_for_player_input(game);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
    if (terminate) {
        sfRenderWindow_destroy(game->window);
        return (0);
    }
    return (1);
}

int load_game(Game_State *game, char **map)
{
    if (invalid_mapfile(map[1]))
        return (0);
    initialize_game_state(game);
    if (!wait_for_player_input_screen(game))
        return (0);
    play_bgm(game, "my_runner.ogg", 85);
    load_map(game, map);
    initialize_game_spriteset(game);
    return (1);
}
