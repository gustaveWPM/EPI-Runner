/*
** EPITECH PROJECT, 2020
** sound_manager.c
** File description:
** Sound Manager
*/

#include "my_runner.h"

void play_bgm(Game_State *game, char *filename, int volume)
{
    sfMusic *bgm;
    char *path;
    char *bgm_folder = FILEPATHS.BGM_FOLDER;
    int filename_len = my_strlen(filename);
    int bgm_folder_len = my_strlen(FILEPATHS.BGM_FOLDER);

    if (game->audio.bgm)
        sfMusic_destroy(game->audio.bgm);
    path = malloc(sizeof(char) * (filename_len + bgm_folder_len) + 1);
    set_path(path, bgm_folder, filename);
    bgm = sfMusic_createFromFile(path);
    sfMusic_setLoop(bgm, sfTrue);
    sfMusic_setVolume(bgm, volume);
    sfMusic_play(bgm);
    free(path);
    game->audio.bgm = bgm;
}

void play_se(Game_State *game, char *filename, int volume)
{
    sfMusic *se;
    char *path;
    char *se_folder = FILEPATHS.SE_FOLDER;
    int filename_len = my_strlen(filename);
    int se_folder_len = my_strlen(FILEPATHS.SE_FOLDER);

    if (game->audio.se)
        sfMusic_destroy(game->audio.se);
    path = malloc(sizeof(char) * (filename_len + se_folder_len) + 1);
    set_path(path, se_folder, filename);
    se = sfMusic_createFromFile(path);
    sfMusic_setVolume(se, volume);
    sfMusic_play(se);
    free(path);
    game->audio.se = se;
}
