/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loadfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <jfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 17:55:25 by jfortin           #+#    #+#             */
/*   Updated: 2017/08/14 13:19:58 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_readfile(int const fd)
{
	char	*out;
	char	buf[BUFF_SIZE + 1];
	size_t	ret;

	if (read(fd, buf, 0) < 0)
		return (NULL);
	out = (char *)ft_memalloc(1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
		out = ft_strjoinfree(out, buf, 'L');
	return(out);
}

char		*ft_loadfile(const char *path_file)
{
	int	fd;

	if ((fd = (open(path_file, O_RDONLY))) < 3)
		return (NULL);
	return (ft_readfile(fd));
}