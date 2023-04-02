/*
** EPITECH PROJECT, 2021
** game_initializers.c
** File description:
** Game Initializers
*/

#include "my_runner.h"

void initialize_walls(Game_State *game)
{
    int id = 0;

    allocate_walls(game);
    for (int id = 0; id < game->map.tiles_number; id++) {
        game->walls[id].width = TILE.SIZE;
        game->walls[id].height = TILE.SIZE;
        game->walls[id].pos.x = RESOLUTION.WIDTH * -1;
        game->walls[id].pos.y = RESOLUTION.HEIGHT * -1;
    }
    for (int y = 0; y < game->map.height; y++)
        for (int x = 0; x < game->map.width; x++) {
            if (!tile_is_passable(game, x, y)) {
                id += 1;
                game->walls[id].pos.x = x * 32.0;
                game->walls[id].pos.y = y * 32.0;
            }
        }
}

void initialize_parallaxes(Game_State *game)
{
    for (int id = 0; id < CONFIG.MAX_PARALLAXES; id++) {
        game->parallaxes[id].texture = NULL;
        game->parallaxes[id].sprite = NULL;
        game->parallaxes[id].pos.x = 0;
        game->parallaxes[id].pos.y = 0;
        hard_coded_parallax_initializer(game, id);
        game->parallaxes[id].x_offset = 0;
    }
}

void initialize_fogs(Game_State *game)
{
    for (int id = 0; id < CONFIG.MAX_FOGS; id++) {
        game->fogs[id].texture = NULL;
        game->fogs[id].sprite = NULL;
        game->fogs[id].pos.x = 0;
        game->fogs[id].pos.y = 0;
        hard_coded_fog_initializer(game, id);
        game->fogs[id].x_offset = 0;
    }
}

void initialize_tiles(Game_State *game, char *filepath)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    int map_width = get_map_width(filepath);

    fp = fopen(filepath, "r");
    allocate_tiles(fp, line, map_width, game);
    fclose(fp);
}

void initialize_game_state(Game_State *game)
{
    game->values.scroll_x = 0;
    game->values.elapsed_frames = 0;
    game->values.score = 0;
    game->values.laps = 0;
    game->values.lap_transition = 0;
    game->values.playing_elapsed_frames = 0;
    game->map.tiles_number = 0;
    game->pause.elapsed_frames = 0;
    game->pause.paused = 0;
    game->audio.bgm = NULL;
    game->audio.se = NULL;
    game->window = game_window(RESOLUTION.WIDTH, RESOLUTION.HEIGHT);
    initialize_game_player(game);
}
