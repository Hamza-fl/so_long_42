/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_matrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:56:49 by hfalati           #+#    #+#             */
/*   Updated: 2025/02/24 19:48:01 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_matrice(char **matrice, int height)
{
	int	i;

	if (!matrice)
		return ;
	i = 0;
	while (i < height)
	{
		if (matrice[i])
			free(matrice[i]);
		i++;
	}
	free(matrice);
}

int	alloc_row(t_game *game, char *line, int i)
{
	game->map->matrice[i] = malloc(sizeof(char) * (game->map->width + 1));
	if (!game->map->matrice[i])
	{
		free_matrice(game->map->matrice, i);
		return (0);
	}
	ft_strlcpy(game->map->matrice[i], line, game->map->width + 1);
	return (1);
}

int	map_matrice(int fd, t_game *game)
{
    int i;
    char *line;

    i = 0;
    while (i < game->map->height)
    {
        line = get_next_line(fd);
        if (!line || !alloc_row(game, line, i))
        {
            free_matrice(game->map->matrice, i);
            free(line);
            close(fd);
            return (0);
        }
        free(line);
        i++;
    }
    return (1);
}
