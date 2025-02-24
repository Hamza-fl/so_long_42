#include "./include/so_long.h"

int main (int ac, char **av)
{
    t_game game;

    if (handle_error(ac,av[1]))
        exit(1);
    if (!setup_game(&game, av[1]))
        exit(1);
}
