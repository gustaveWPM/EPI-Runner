/*
** EPITECH PROJECT, 2021
** memory_funs_prototypes.h
** File description:
** Memory Functions Prototypes
*/

#ifndef MEMORY_FUNCTIONS_PROTOTYPES_H
#define MEMORY_FUNCTIONS_PROTOTYPES_H
void allocate_player(Game_State *game);
void allocate_tiles(FILE *fp, char *line, int map_width, Game_State *game);
void allocate_enemies(Game_State *game);
void allocate_walls(Game_State *game);
void allocate_parallaxes(Game_State *game);
void allocate_fogs(Game_State *game);
void free_tiles(Game_State *game);
void free_enemies(Game_State *game);
void free_walls(Game_State *game);
void free_player(Game_State *game);
void free_parallaxes(Game_State *game);
void free_fogs(Game_State *game);
void free_tiles(Game_State *game);
void free_tileset(Game_State *game);
void terminate(Game_State *game);
#endif
