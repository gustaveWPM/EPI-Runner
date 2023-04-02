/*
** EPITECH PROJECT, 2021
** movements.c
** File description:
** Characters movement
*/

#include "my_runner.h"

void character_move_left(Game_Actor *character)
{
    character->pos.x -= TILE.SIZE / TILE.SECTIONS;
}

void character_move_right(Game_Actor *character)
{
    character->pos.x += TILE.SIZE / TILE.SECTIONS;
}

void character_move_up(Game_Actor *character)
{
    character->pos.y -= TILE.SIZE / TILE.SECTIONS;
}

void character_move_down(Game_Actor *character)
{
    character->pos.y += TILE.SIZE / TILE.SECTIONS;
}
