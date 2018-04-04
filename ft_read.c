/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <jfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 19:15:38 by jfortin           #+#    #+#             */
/*   Updated: 2018/04/01 03:24:41 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_read(int fd, void *buf, size_t nbyte)
{
	ssize_t	ret;

	if ((ret = read(fd, buf, nbyte)) == -1)
	{
		ft_putstr_fd("error read fd: ", 2);
		ft_putnbr_fd(fd, 2);
		ft_putchar('\n');
		perror(NULL);
	}
	return (ret);
}
