/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:26:29 by hfalati           #+#    #+#             */
/*   Updated: 2025/02/25 11:08:57 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_char(char c, t_game *game, int i, int j)
{
	if (i >= game->map->height || j >= game->map->width)
		return (0);
	if (c == 'P')
	{
		game->player_count++;
		game->player_x = j;
		game->player_y = i;
	}
	else if (c == 'E')
		game->exit_count++;
	else if (c == 'C')
		game->total_collectibles++;
	else if (c != '0' && c != '1')
		return (0);
	return (1);
}

int	valid_chars(t_game *game)
{
	int	i;
	int	j;

	game->player_count = 0;
	game->exit_count = 0;
	game->total_collectibles = 0;
	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (!check_char(game->map->matrice[i][j], game, i, j))
				return (0);
			j++;
		}
		i++;
	}
	return (game->player_count == 1 && game->exit_count == 1
		&& game->total_collectibles > 0);
}
