/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <jfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:23:32 by jfortin           #+#    #+#             */
/*   Updated: 2017/11/14 16:33:20 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memset8(void *s, int c, size_t n)
{
	int		i;
	long	value;

	value = (unsigned char)c;
	i = sizeof(long);
	while (--i)
	{
		value <<= 8;
		value += (unsigned char)c;
	}
	while (n)
	{
		n -= sizeof(long);
		*((long *)(s + n)) = value;
	}
	return (s);
}

static void	*ft_memset4(void *s, int c, size_t n)
{
	int		i;
	int		value;

	value = (unsigned char)c;
	i = sizeof(int);
	while (--i)
	{
		value <<= 8;
		value += (unsigned char)c;
	}
	while (n)
	{
		n -= sizeof(int);
		*((int *)(s + n)) = value;
	}
	return (s);
}

static void	*ft_memset2(void *s, int c, size_t n)
{
	int		i;
	short	value;

	value = (unsigned char)c;
	i = sizeof(short);
	while (--i)
	{
		value <<= 8;
		value += (unsigned char)c;
	}
	while (n)
	{
		n -= sizeof(short);
		*((short *)(s + n)) = value;
	}
	return (s);
}

static void	*ft_memset1(void *s, int c, size_t n)
{
	while (n--)
		*((unsigned char *)(s + n)) = (unsigned char)c;
	return (s);
}

void		*ft_memset(void *s, int c, size_t n)
{
	if (n % sizeof(long) == 0)
		return (ft_memset8(s, c, n));
	if (n % sizeof(int) == 0)
		return (ft_memset4(s, c, n));
	if (n % sizeof(short) == 0)
		return (ft_memset2(s, c, n));
	return (ft_memset1(s, c, n));
	return (NULL);
}
