/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:22:47 by hfalati           #+#    #+#             */
/*   Updated: 2024/12/03 10:11:12 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_printf_for(char format, va_list ar)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_putchar(va_arg(ar, int));
	else if (format == 's')
		count += ft_putstr(va_arg(ar, char *));
	else if (format == 'p')
	{
		count += ft_putstr("0x");
		count += ft_putaddr((unsigned long)va_arg(ar, void *));
	}
	else if (format == 'd' || format == 'i')
		count += ft_putnbr(va_arg(ar, int));
	else if (format == 'u')
		count += ft_put_unsigned(va_arg(ar, unsigned int));
	else if (format == 'x' || format == 'X')
		count += ft_puthex(va_arg(ar, unsigned int), format);
	else if (format == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	ar;
	int		count;

	i = 0;
	count = 0;
	va_start (ar, str);
	if (write (1, 0, 0) == -1)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_printf_for(str[i + 1], ar);
			i++;
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end (ar);
	return (count);
}
