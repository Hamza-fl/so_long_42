/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:37:43 by hfalati           #+#    #+#             */
/*   Updated: 2025/02/24 17:37:43 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_file(char *file)
{
	int	len;

	if (file == NULL)
		return (0);
	len = ft_strlen(file);
	if (len < 5)
		return (0);
	if (ft_strcmp(file + len - 4, ".ber") != 0)
		return (0);
	return (1);
}

int	handle_errors(int ac, char *file)
{
	if (ac != 2)
	{
		ft_printf("Error\nInvalid number of arguments!\n");
		return (1);
	}
	if (!check_file(file))
	{
		ft_printf("Invalid extension !!\n");
		return (1);
	}
	return (0);
}
