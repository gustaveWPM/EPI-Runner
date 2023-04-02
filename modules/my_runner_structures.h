/*
** EPITECH PROJECT, 2021
** my_runner_structures.h
** File description:
** My Runner Structures
*/

#ifndef MY_RUNNER_STRUCTURES_H
#define MY_RUNNER_STRUCTURES_H
typedef struct
{
    float x_offset;
    float x_speed;
    sfVector2f pos;
    sfSprite *sprite;
    sfTexture *texture;
} Parallax;

typedef struct
{
    float x_offset;
    float x_speed;
    sfVector2f pos;
    sfSprite *sprite;
    sfTexture *texture;
} Fog;

typedef struct
{
    sfVector2f pos;
    int width;
    int height;
} Wall;

typedef struct
{
    sfSprite *sprite;
    sfTexture *texture;
} Tileset;

typedef struct
{
    int elapsed_frames;
    int paused;
} Pause;

typedef struct
{
    sfVector2f pos;
    sfSprite *sprite;
    sfTexture *texture;
} Character;

typedef struct
{
    sfVector2f pos;
    sfTexture *texture;
    sfSprite *sprite;
    float dy;
    short lifes;
    short jumps;
    int frame;
    int anim_frame_amount;
    int spritesheet_index;
} Game_Actor;

typedef struct
{
    sfMusic *bgm;
    sfMusic *se;
} Game_Audio;

typedef struct
{
    int **tiles;
    int width;
    int height;
    int tiles_number;
} Map;

typedef struct {
    long long elapsed_frames;
    float scroll_x;
    long long score;
    int laps;
    int lap_transition;
    short playing_elapsed_frames;
} Values;

typedef struct
{
    Game_Actor player;
    Pause pause;
    Game_Audio audio;
    Map map;
    Tileset tileset;
    Parallax parallaxes[MAX_PARALLAXES_AMOUNT];
    Parallax fogs[MAX_FOGS_AMOUNT];
    Wall *walls;
    Values values;
    sfRenderWindow *window;
} Game_State;
#endif
