/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <jfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:23:50 by jfortin           #+#    #+#             */
/*   Updated: 2017/11/29 17:08:47 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	int	power;
	int	tmp;

	if ((power = nb < 0 ? -1 : 1) == -1)
		ft_putchar('-');
	tmp = nb;
	while (tmp /= 10)
		power *= 10;
	while (power)
	{
		ft_putchar(nb / power + '0');
		nb -= (nb / power) * power;
		power /= 10;
	}
}
