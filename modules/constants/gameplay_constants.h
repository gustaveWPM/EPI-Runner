/*
** EPITECH PROJECT, 2021
** gameplay_constants.h
** File description:
** Gameplay Constants
*/

#ifndef GAMEPLAY_CONSTANTS_H
#define GAMEPLAY_CONSTANTS_H
#include "my_runner.h"
static const struct {
    float GRAVITY;
    int PAUSE_DELAY;
    int PLAYABLE_HEIGHT;
    int LAP_BONUS;
    int SCORE_DELAY_BONUS;
    int SCORE_DELAY_BONUS_DURATION;
    int ANIM_SPEED;
} GAMEPLAY = {
    0.24f,
    5,
    RESOLUTION.HEIGHT - HUD.HEIGHT,
    500,
    10,
    60,
    10
};
#endif
