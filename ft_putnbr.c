/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:23:50 by jfortin           #+#    #+#             */
/*   Updated: 2015/11/26 14:41:41 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr(int n)
{
	int	i;
	int	j;
	int	tmp;
	int	signe;

	i = 1;
	signe = 1;
	if (n < 0)
		signe = -1;
	if (n < 0)
		ft_putchar('-');
	tmp = n;
	while (tmp < -9 || tmp > 9)
	{
		tmp = tmp / 10;
		i++;
	}
	while (i-- >= 1)
	{
		j = 0;
		tmp = n;
		while (j++ < i)
			tmp = tmp / 10;
		ft_putchar(signe * (tmp % 10) + '0');
	}
}
