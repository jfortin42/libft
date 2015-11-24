/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:23:53 by jfortin           #+#    #+#             */
/*   Updated: 2015/11/24 11:50:28 by jfortin          ###   ########.fr       */
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

void		ft_putnbr_fd(int n, int fd)
{
	int		i;
	int		j;
	int		tmp;

	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	tmp = n;
	i = ft_nbrlen(n);
	while (i >= 0 && n != -2147483648)
	{
		tmp = n;
		j = 0;
		while (j++ < i)
			tmp = tmp / 10;
		ft_putchar_fd(tmp % 10 + '0', fd);
		i--;
	}
}
