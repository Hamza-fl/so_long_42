/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:37:17 by hfalati           #+#    #+#             */
/*   Updated: 2025/02/24 17:37:17 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
int	game_init(t_game *game);
int	load_image(t_game *game);

int	setup_game(t_game *game, char *file)
{
    if (!parse_map(game, file))
    {
        ft_printf("Error\nInvalid map\n");
        return (0);
    }
    if (!game_init(game))
	{
		clean_game(game);
		return (0);
	}
    if (!load_image(game))
	{
		ft_printf("can't load images");
		return (0);
	}
    return (1);
}
int	game_init(t_game *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
        return(0);
    game->win = mlx_new_window(game->mlx, game->map->width * 32, game->map->height * 32, "So_long");
    if (!game->win)
    {
        free(game->mlx);
        return (0);
    }
    game->moves = 0;
    game->collectibles = 0;
    return (1);
}

int	load_image(t_game *game)
{
    int width;
    int height;

    width = TILE_SIZE;
    height = TILE_SIZE;
    game->imgs.player = mlx_xpm_file_to_image(game->mlx, CHAR_PATH, &width, &height);
    game->imgs.wall = mlx_xpm_file_to_image(game->mlx, WALL_PATH, &width, &height);
    game->imgs.floor = mlx_xpm_file_to_image(game->mlx, FLOOR_PATH, &width, &height);
    game->imgs.collectible = mlx_xpm_file_to_image(game->mlx, COLLECT_PATH, &width, &height);
    game->imgs.exit = mlx_xpm_file_to_image(game->mlx, PORTAL_PATH, &width, &height);
    if (!game->imgs.player || !game->imgs.wall || !game->imgs.floor || !game->imgs.collectible || !game->imgs.exit)
    {
		image_free(game);
		return (0);
	}
	return (1);
}