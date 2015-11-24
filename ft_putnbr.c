/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:23:50 by jfortin           #+#    #+#             */
/*   Updated: 2015/11/24 11:41:46 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int nbr)
{
	int	i;

	i = 0;
	if (nbr < 0)
		return (-1);
	while (nbr >= 10)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

void		ft_putnbr(int n)
{
	int		i;
	int		j;
	int		tmp;

	if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	tmp = n;
	i = ft_nbrlen(n);
	while (i >= 0 && n != -2147483648)
	{
		j = 0;
		tmp = n;
		while (j++ < i)
			tmp = tmp / 10;
		ft_putchar(tmp % 10 + '0');
		i--;
	}
}
