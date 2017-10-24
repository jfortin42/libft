/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <jfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:23:20 by jfortin           #+#    #+#             */
/*   Updated: 2017/10/24 12:43:50 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memcpy8(void *dest, const void *src, size_t n)
{
	while (n)
	{
		n -= sizeof(long);
		*((long *)(dest + n)) = *((long *)(src + n));
	}
	return (dest);
}

static void	*ft_memcpy4(void *dest, const void *src, size_t n)
{
	while (n)
	{
		n -= sizeof(int);
		*((int *)(dest + n)) = *((int *)(src + n));
	}
	return (dest);
}

static void	*ft_memcpy2(void *dest, const void *src, size_t n)
{
	while (n)
	{
		n -= sizeof(short);
		*((short *)(dest + n)) = *((short *)(src + n));
	}
	return (dest);
}

static void	*ft_memcpy1(void *dest, const void *src, size_t n)
{
	while (n)
	{
		n -= sizeof(char);
		*((char *)(dest + n)) = *((char *)(src + n));
	}
	return (dest);
}

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (n % sizeof(long) == 0)
		return (ft_memcpy8(dest, src, n));
	if (n % sizeof(int) == 0)
		return (ft_memcpy4(dest, src, n));
	if (n % sizeof(short) == 0)
		return (ft_memcpy2(dest, src, n));
	return (ft_memcpy1(dest, src, n));
}