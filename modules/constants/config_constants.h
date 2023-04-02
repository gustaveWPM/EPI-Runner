/*
** EPITECH PROJECT, 2021
** config_constants.h
** File description:
** Config constants. Some are recurrent with macros
** because they are used in array declarations
*/

#ifndef CONFIG_CONSTANTS_H
#define CONFIG_CONSTANTS_H
#define MAX_PARALLAXES_AMOUNT 2
#define MAX_FOGS_AMOUNT 2
#include "tiles_constants.h"
static const struct {
    int TILE_PLAYABLE_HEIGHT;
    int MAX_PARALLAXES;
    int MAX_FOGS;
    int START_POS_X;
    int START_POS_Y;
} CONFIG = {
    13,
    MAX_PARALLAXES_AMOUNT,
    MAX_FOGS_AMOUNT,
    3 * TILE.SIZE,
    13 * TILE.SIZE
};
#endif
