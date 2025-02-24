/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:37:39 by hfalati           #+#    #+#             */
/*   Updated: 2025/02/24 19:48:51 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
int	get_map_size(t_game *game, char *file);
int	load_map_size(t_game *game, char *file);

int	parse_map(t_game *game, char *file)
{
    game->map = malloc(sizeof(t_map));
    if (!game->map)
        return (0);
    if (!get_map_size(game, file) || game->map->height > 37 || game->map->width > 76)
    {
        free(game->map);
        return(0);
    }
    if (!load_map_size(game, file))
	{
		free(game->map);
		return (0);
	}
    if (!valid_walls(game) || !valid_chars(game)
		|| !valid_map(game))
	{
		free_matrice(game->map->matrice, game->map->height);
		free(game->map);
		return (0);
	}
	return (1);
}

int	valid_length(char *line, int width)
{
	int	len;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		len--;
	return (len == width);
}

int	get_map_size(t_game *game, char *file)
{
    int fd;
    char *line;

    fd = open(file, O_RDONLY);
    if (!fd)
        return (0);
    game->map->height = 0;
    line = get_next_line(fd);
    if (line == NULL)
        return (0);
    game->map->width = ft_strlen(line) - 1;
    while (line)
    {
        if (!valid_length(line, game->map->width))
        {
            free(line);
            close(fd);
            return (0);
        }
        game->map->height++;
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return (game->map->height > 0 && game->map->width > 0);
}

int	open_map(char *file, t_game *game, int height)
{
	int	fd;

	game->map->matrice = malloc(sizeof(char *) * height);
	if (!game->map->matrice)
		return (-1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free(game->map->matrice);
		return (-1);
	}
	return (fd);
}

int	load_map_size(t_game *game, char *file)
{
    int fd;

    fd = open_map(file, game, game->map->height);
    if (fd < 0 || !game->map->matrice)
        return (0);
    if (!map_matrice(fd, game))
        return (0);
    close(fd);
    return (1);
}