/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <jfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:23:53 by jfortin           #+#    #+#             */
/*   Updated: 2017/05/13 18:12:19 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	int	power;
	int	tmp;

	if ((power = n < 0 ? -1 : 1) == -1)
		ft_putchar_fd('-', fd);
	tmp = n;
	while (tmp /= 10)
		power *= 10;
	while (power)
	{
		ft_putchar_fd((tmp = n / power) + '0', fd);
		n -= tmp * power;
		power /= 10;
	}
}