/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:18:11 by hfalati           #+#    #+#             */
/*   Updated: 2025/02/25 10:56:03 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_valid_position(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->map->width || y < 0 || y >= game->map->height)
		return (0);
	if (game->map->matrice[y][x] == '1')
		return (0);
	return (1);
}

void	collect_item(t_game *game, int x, int y)
{
	game->collectibles++;
	game->map->matrice[y][x] = '0';
}

int	check_win_condition(t_game *game, int x, int y)
{
	if (game->map->matrice[y][x] != 'E')
		return (0);
	if (game->collectibles == game->total_collectibles)
	{
		ft_printf("You won in %d moves!\n", game->moves + 1);
		game->won = 1;
		return (1);
	}
	return (0);
}

int	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (!is_valid_position(game, new_x, new_y))
		return (0);
	if (game->map->matrice[new_y][new_x] == 'C')
		collect_item(game, new_x, new_y);
	else if (check_win_condition(game, new_x, new_y) == 1)
		exit(0);
	game->player_x = new_x;
	game->player_y = new_y;
	return (1);
}
