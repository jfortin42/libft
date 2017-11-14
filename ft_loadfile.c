/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loadfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <jfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 17:55:25 by jfortin           #+#    #+#             */
/*   Updated: 2017/11/14 16:30:53 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_loadfile(const char *path_file)
{
	int		fd;
	char	*out;

	if ((fd = (open(path_file, O_RDONLY))) < 3)
		return (NULL);
	ft_readfile(&out, fd);
	close(fd);
	return (out);
}
