/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <jfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 19:02:17 by jfortin           #+#    #+#             */
/*   Updated: 2018/04/01 03:24:19 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_open(const char *path, int oflag)
{
	int	fd;

	if ((fd = open(path, oflag)) == -1)
	{
		ft_putstr_fd("error open ", 2);
		ft_putendl_fd(path, 2);
		perror(NULL);
	}
	return (fd);
}
