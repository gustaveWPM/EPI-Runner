/*
** EPITECH PROJECT, 2021
** etc_funs_prototypes.h
** File description:
** Etc functions prototypes
*/

#ifndef ETC_PROTOTYPES_H
#define ETC_PROTOTYPES_H
sfRenderWindow *game_window(int width, int height);
void initialize_tiles(Game_State *game, char *filepath);
void initialize_game_player(Game_State *game);
void initialize_fogs(Game_State *game);
void initialize_parallaxes(Game_State *game);
void initialize_walls(Game_State *game);
int load_game(Game_State *game, char **argv);
void load_map(Game_State *game, char **map);
void set_path(char *path, char *folder, char *filename);
void set_player_jumping_anim(Game_State *game);
void set_player_walking_anim(Game_State *game);
int wait_for_player_input(Game_State *game);
#endif
