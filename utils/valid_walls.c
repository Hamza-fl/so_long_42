/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:15:51 by hfalati           #+#    #+#             */
/*   Updated: 2025/02/25 11:09:27 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_horizontal(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map->width)
	{
		if (game->map->matrice[0][i] != '1' ||
			game->map->matrice[game->map->height - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_vertical(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map->height)
	{
		if (game->map->matrice[i][0] != '1' ||
			game->map->matrice[i][game->map->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	valid_walls(t_game *game)
{
	return (check_horizontal(game) && check_vertical(game));
}
