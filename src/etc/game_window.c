/*
** EPITECH PROJECT, 2020
** game_window.c
** File description:
** Build Game Window
*/

#include "my_runner.h"

sfRenderWindow *game_window(int width, int height)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;
    char *title = "my_runner";

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 72;
    window = sfRenderWindow_create(video_mode, title, sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}
