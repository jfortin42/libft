/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loadfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <jfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 17:55:25 by jfortin           #+#    #+#             */
/*   Updated: 2018/03/09 13:10:57 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_loadfile(const char *path_file)
{
	int		fd;
	char	*out;

	out = NULL;
	if ((fd = (open(path_file, O_RDONLY))) < 3)
	{
		ft_putstr_fd("error open ", 2);
		ft_putendl_fd(path_file, 2);
		perror(NULL);
		return (NULL);
	}
	if (ft_readfile(&out, fd) == -1)
	{
		ft_putstr_fd("error read ", 2);
		ft_putendl_fd(path_file, 2);
		perror(NULL);
	}
	close(fd);
	return (out);
}
