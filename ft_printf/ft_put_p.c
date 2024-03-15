/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpassin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:25:16 by tpassin           #+#    #+#             */
/*   Updated: 2023/12/08 11:25:08 by tpassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_base16(unsigned long nb, char *base)
{
	int	count;

	count = 0;
	if (nb < 16)
		count += ft_putchar(base[nb]);
	else
	{
		count += ft_base16(nb / 16, base);
		count += ft_base16(nb % 16, base);
	}
	if (count < 0)
		return (-1);
	return (count);
}

int	ft_put_p(void *nbr)
{
	int				count;
	char			*base;
	unsigned long	nb;

	count = 0;
	if (nbr == 0)
		return (count += ft_putstr("(nil)"));
	nb = (unsigned long)nbr;
	base = "0123456789abcdef";
	count += ft_putstr("0x");
	count += ft_base16(nb, base);
	if (count < 0)
		return (-1);
	return (count);
}
