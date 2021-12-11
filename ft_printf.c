/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:32:15 by ahjadani          #+#    #+#             */
/*   Updated: 2021/12/11 12:56:47 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flag_hundler(va_list argp, char flag)
{
	int	count;

	count = 0;
	if (flag == 'c')
		count += ft_putchar(va_arg(argp, int));
	else if (flag == 's')
		count += ft_putstr(va_arg(argp, char *));
	else if (flag == 'd' || flag == 'i')
		count += ft_putnbr(va_arg(argp, int));
	else if (flag == 'u')
		count += ft_putunnbr(va_arg(argp, unsigned int));
	else if (flag == 'x' || flag == 'X')
		count += ft_puthex(va_arg(argp, unsigned int), flag);
	else if (flag == 'p')
	{
		count += ft_putstr("0x");
		count += ft_putaddr(va_arg(argp, unsigned long));
	}
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	argp;
	int		i;
	int		x;

	x = 0;
	i = 0;
	if (!s)
		return (0);
	va_start(argp, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (s[++i] != '%')
				x += ft_flag_hundler(argp, s[i]);
			else
				x += ft_putchar(s[i]);
		}
		else
			x += ft_putchar(s[i]);
		i++;
	}
	va_end(argp);
	return (x);
}
