/*
** EPITECH PROJECT, 2021
** gameplay_funs_prototypes.h
** File description:
** Gameplay Functions Prototypes
*/

#ifndef GAMEPLAY_FUNS_PROTOTYPES_H
#define GAMEPLAY_FUNS_PROTOTYPES_H
void character_move_left(Game_Actor *character);
void character_move_right(Game_Actor *character);
void character_move_down(Game_Actor *character);
void character_move_up(Game_Actor *character);
void check_max_y(Game_State *game);
void check_min_y(Game_State *game);
void check_player_death(Game_State *game, int player_screen_x);
void check_player_x(Game_State *game);
void game_loop(Game_State *game);
void game_restart(Game_State *game);
void input_manager(Game_State *game);
void new_lap(Game_State *game);
void process_physics(Game_State *game);
void process_collisions(Game_State *game);
#endif
