/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:33:12 by hfalati           #+#    #+#             */
/*   Updated: 2024/12/02 18:16:37 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddr(unsigned long addr)
{
	int		count;
	char	*base;

	base = "0123456789abcdef";
	count = 0;
	if (addr < 16)
		count += ft_putchar(base[addr]);
	else
	{
		count += ft_putaddr(addr / 16);
		count += ft_putaddr(addr % 16);
	}
	return (count);
}

int	ft_puthex(unsigned int nbr, char format)
{
	int		count;
	char	*base;

	count = 0;
	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nbr < 16)
		count += ft_putchar(base[nbr % 16]);
	else
	{
		count += ft_puthex(nbr / 16, format);
		count += ft_puthex(nbr % 16, format);
	}
	return (count);
}

int	ft_put_unsigned(unsigned int nb)
{
	char	x;
	int		count;

	count = 0;
	if (nb > 9)
	{
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	else
	{
		x = nb + 48;
		count += ft_putchar(x);
	}
	return (count);
}

int	ft_putnbr(int nb)
{
	char	x;
	int		count;

	count = 0;
	if (nb == -2147483648)
	{
		count += ft_putstr("-2147483648");
		return (count);
	}
	if (nb < 0)
	{
		count += write(1, "-", 1);
		nb = nb * -1;
	}
	if (nb > 9)
	{
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	else
	{
		x = nb + 48;
		count += ft_putchar(x);
	}
	return (count);
}

int	ft_putstr(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (!str)
	{
		count += ft_putstr("(null)");
		return (count);
	}
	while (str[i])
	{
		count += write(1, &str[i], 1);
		i++;
	}
	return (count);
}
