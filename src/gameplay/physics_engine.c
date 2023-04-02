/*
** EPITECH PROJECT, 2021
** physics_engine.c
** File description:
** Physics Engine functions
*/

#include "my_runner.h"

void check_head_bump(Game_State *game, int i)
{
    float mw = TILE.SIZE;
    float mh = TILE.SIZE;
    float mx = game->player.pos.x;
    float my = game->player.pos.y;
    float bx = game->walls[i].pos.x;
    float by = game->walls[i].pos.y;
    float bw = game->walls[i].width;
    float bh = game->walls[i].height;
    int ts = TILE.SECTIONS;

    if (((mx + (mw / ts)) > bx) && (mx + (mw / ts) < (bx + bw))) {
        if (((my < (by + bh)) && (my > by))) {
            game->player.pos.y = by + bh;
            my = by + bh;
            game->player.dy = 0;
            game->player.jumps = 0;
        }
    }
}

void check_wall_meeting(Game_State *game, int i)
{
    float mw = TILE.SIZE;
    float mh = TILE.SIZE;
    float mx = game->player.pos.x;
    float my = game->player.pos.y;
    float bx = game->walls[i].pos.x;
    float by = game->walls[i].pos.y;
    float bw = game->walls[i].width;
    float bh = game->walls[i].height;

    if ((bx < (mx + mw)) && (mx < (bx + bw))) {
        if (((my + mh) > by) && (my < by) && (game->player.dy > 0)) {
            game->player.pos.y = by - mh;
            my = by - mh;
            game->player.dy = 0;
            game->player.jumps = 0;
            set_player_walking_anim(game);
        }
    }
}

void check_rubbing_edges(Game_State *game, int i)
{
    float mw = TILE.SIZE;
    float mh = TILE.SIZE;
    float mx = game->player.pos.x;
    float my = game->player.pos.y;
    float bx = game->walls[i].pos.x;
    float by = game->walls[i].pos.y;
    float bw = game->walls[i].width;
    float bh = game->walls[i].height;

    if (((my + mh) > by) && (my < (by + bh))) {
        if ((mx < (bx + bw)) && ((mx + mw) > (bx + bw))) {
            game->player.pos.x = bx - bw;
            mx = bx - bw;
        }
        if (((mx + mw) > bx) && (mx < bx)) {
            game->player.pos.x = bx - mw;
            mx = bx - mw;
        }
    }
}

void process_collisions(Game_State *game)
{
    float wall_x = 0;

    check_min_y(game);
    for (int id = 0; id < game->map.tiles_number; id++) {
        wall_x = game->walls[id].pos.x + game->values.scroll_x;
        if (wall_x >= (TILE.SIZE * -1)
            && wall_x <= (RESOLUTION.WIDTH + TILE.SIZE)) {
            check_head_bump(game, id);
            check_wall_meeting(game, id);
            check_rubbing_edges(game, id);
        }
    }
}

void process_physics(Game_State *game)
{
    Game_Actor *player = &game->player;
    player->pos.y += player->dy;
    player->dy += GAMEPLAY.GRAVITY;
    if ((player->pos.x + game->values.scroll_x) < CONFIG.START_POS_X)
        player->pos.x += 1.0f;
    check_max_y(game);
}
