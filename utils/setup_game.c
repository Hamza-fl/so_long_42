#include "../include/so_long.h"

int	setup_game(t_game *game, char *file)
{
    if (!parse_map(game, file))
    {
        ft_printf("Error\nInvalid map\n");
        return (0);
    }
}   