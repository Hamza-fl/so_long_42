/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:45:03 by hfalati           #+#    #+#             */
/*   Updated: 2025/02/24 18:57:54 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	flood_fill(char **matrice, int x, int y, t_game *game)
{
	if (x < 0 || y < 0 || x >= game->map->height || y >= game->map->width)
		return ;
	if (matrice[x][y] == '1' || matrice[x][y] == 'X')
		return ;
	if (matrice[x][y] == 'C')
		game->collectibles++;
	if (matrice[x][y] == 'E')
		game->won = 1;
	matrice[x][y] = 'X';
	flood_fill(matrice, x + 1, y, game);
	flood_fill(matrice, x - 1, y, game);
	flood_fill(matrice, x, y + 1, game);
	flood_fill(matrice, x, y - 1, game);
}

int	valid_map(t_game *game)
{
    char **tmp_matrice;
    int i;

    tmp_matrice = malloc(sizeof(char *) * game->map->height);
    if (!tmp_matrice)
        return (0);
    i = 0;
    while (i < game->map->height)
    {
        tmp_matrice[i] = ft_strdup(game->map->matrice[i]);
        if (!tmp_matrice[i])
        {
            free_matrice(tmp_matrice, i);
            return(0);
        }
        i++;
    }
    game->collectibles = 0;
    game->won = 0;
    flood_fill(tmp_matrice, game->player_x, game->player_y, game);
    free_matrice(tmp_matrice, game->map->height);
    return (game->collectibles == game->total_collectibles && game->won);
}
