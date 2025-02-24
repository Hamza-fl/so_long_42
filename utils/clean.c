/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:37:50 by hfalati           #+#    #+#             */
/*   Updated: 2025/02/24 17:37:51 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	if (map->matrice)
	{
		while (i < map->height)
		{
			if (map->matrice[i])
				free(map->matrice[i]);
			i++;
		}
		free(map->matrice);
	}
	free(map);
}

void	clean_game(t_game *game)
{
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		free(game->mlx);
	if (game->map)
		free_map(game->map);
}

void	image_free(t_game *game)
{
	if (game->imgs.wall)
		mlx_destroy_image(game->mlx, game->imgs.wall);
	if (game->imgs.player)
		mlx_destroy_image(game->mlx, game->imgs.player);
	if (game->imgs.collectible)
		mlx_destroy_image(game->mlx, game->imgs.collectible);
	if (game->imgs.exit)
		mlx_destroy_image(game->mlx, game->imgs.exit);
	if (game->imgs.floor)
		mlx_destroy_image(game->mlx, game->imgs.floor);
}