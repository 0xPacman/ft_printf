/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:38:20 by ahjadani          #+#    #+#             */
/*   Updated: 2021/12/11 13:01:45 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
		ft_putchar(str[i++]);
	return (i);
}

int	ft_putnbr(int nbr)
{
	int	i;

	i = 0;
	if (nbr == -2147483648)
	{
		ft_putstr("-2147483648");
		i = 11;
	}
	else if (nbr < 0)
	{
		i += ft_putchar('-');
		i += ft_putnbr(-nbr);
	}
	else if (nbr >= 10)
	{
		i += ft_putnbr(nbr / 10);
		i += ft_putchar(nbr % 10 + 48);
	}
	else
		i += ft_putchar(nbr + 48);
	return (i);
}

int	ft_putunnbr(unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	if (nbr >= 10)
	{
		i += ft_putunnbr(nbr / 10);
		i += ft_putchar(nbr % 10 + 48);
	}
	else
		i += ft_putchar(nbr + 48);
	return (i);
}

int	ft_puthex(unsigned int nbr, char flag)
{
	int	i;

	i = 0;
	if (nbr >= 16)
		i += ft_puthex(nbr / 16, flag);
	if (flag == 'X')
		i += ft_putchar("0123456789ABCDEF"[nbr % 16]);
	else
		i += ft_putchar("0123456789abcdef"[nbr % 16]);
	return (i);
}
