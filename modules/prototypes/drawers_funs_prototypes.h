/*
** EPITECH PROJECT, 2021
** drawers_funs_prototypes.h
** File description:
** Drawers functions prototypes
*/

#ifndef DRAWERS_FUNS_PROTOTYPES_H
#define DRAWERS_FUNS_PROTOTYPES_H
void draw_walls(Game_State *game);
void draw_tiles(Game_State *game);
void draw_enemies(Game_State *game);
void draw_map(Game_State *game);
void draw_player(Game_State *game);
void draw_parallaxes(Game_State *game);
void draw_fogs(Game_State *game);
void hard_coded_parallax_initializer(Game_State *game, int id);
void hard_coded_fog_initializer(Game_State *game, int id);
void initialize_game_spriteset(Game_State *game);
void update(Game_State *game);
void update_game_spriteset(Game_State *game);
#endif
