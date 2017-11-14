/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <jfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 11:00:21 by jfortin           #+#    #+#             */
/*   Updated: 2017/11/14 16:30:15 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_atof(const char *nptr)
{
	float	power;
	float	nbr;
	float	after_point;
	float	sign;

	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n'
		|| *nptr == '\r' || *nptr == '\v' || *nptr == '\f')
		nptr++;
	sign = 1.0f;
	if (*nptr == '+' || *nptr == '-')
		*nptr++ == '-' ? sign = -1.0f : 0;
	nbr = 0.0f;
	while (*nptr >= '0' && *nptr <= '9')
		nbr = nbr * 10 + *nptr++ - '0';
	*nptr == '.' ? nptr++ : 0;
	power = 1;
	after_point = 0.0f;
	while (*(nptr) >= '0' && *(nptr) <= '9')
	{
		after_point = after_point * 10 + *nptr++ - '0';
		power *= 10;
	}
	nbr += (after_point / power);
	return (nbr * sign);
}
