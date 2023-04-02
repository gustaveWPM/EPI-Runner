/*
** EPITECH PROJECT, 2021
** game_initializers_funs_prototypes.h
** File description:
** Game Initializers Functions Prototypes
*/

#ifndef GAME_INITIALIZERS_FUNS_PROTOTYPES_H
#define GAME_INITIALIZERS_FUNS_PROTOTYPES_H
void initialize_walls(Game_State *game);
void initialize_parallaxes(Game_State *game);
void initialize_fogs(Game_State *game);
void initialize_tiles(Game_State *game, char *filepath);
void initialize_game_state(Game_State *game);
#endif
