/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_funcs2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:45:01 by ahjadani          #+#    #+#             */
/*   Updated: 2021/12/12 11:12:36 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddr(unsigned long nbr)
{
	int	i;

	i = 0;
	if (nbr >= 16)
		i += ft_putaddr(nbr / 16);
	i += ft_putchar("0123456789abcdef"[nbr % 16]);
	return (i);
}
