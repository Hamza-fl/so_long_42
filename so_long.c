/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:37:25 by hfalati           #+#    #+#             */
/*   Updated: 2025/02/24 17:37:25 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (handle_errors(ac, av[1]))
		exit(1);
	if (!setup_game(&game, av[1]))
		exit(1);
	setup_hooks(&game);
	mlx_loop(game.mlx);
	clean_game(&game);
	return (0);
}
