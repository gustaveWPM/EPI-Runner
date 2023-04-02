/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** Entry point
*/

#include "my_runner.h"

void run(Game_State *game)
{
    game_loop(game);
}

int display_help(char **argv)
{
    if (str_equals(argv[1], "-h") || str_equals(argv[1], "--help")) {
        my_putstr(VOCAB.USAGE);
        return (1);
    }
    return (0);
}

int invalid_arguments(int argc)
{
    if (argc != 2) {
        my_putstr("./my_runner: bad arguments: ");
        my_puterr_nb(argc - 1);
        my_putstr(" given but 1 is required\nretry with -h\n");
        return (1);
    }
    return (0);
}

int main(int argc, char **argv)
{
    Game_State game;

    if (invalid_arguments(argc))
        return (84);
    if (display_help(argv))
        return (0);
    if (!load_game(&game, argv))
        return (84);
    while (sfRenderWindow_isOpen(game.window))
        run(&game);
    terminate(&game);
    return (0);
}
