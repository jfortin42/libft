/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <jfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:23:50 by jfortin           #+#    #+#             */
/*   Updated: 2017/05/13 17:49:23 by jfortin          ###   ########.fr       */
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
		ft_putchar((tmp = nb / power) + '0');
		nb -= tmp * power;
		power /= 10;
	}
}