/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <jfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 13:14:27 by jfortin           #+#    #+#             */
/*   Updated: 2017/11/14 16:32:41 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_readfile(char **out, int const fd)
{
	char	buf[BUFF_SIZE + 1];
	size_t	ret;
	size_t	count;

	count = 0;
	if (out == NULL || read(fd, buf, 0) < 0)
		return (-1);
	*out = (char *)ft_memalloc(1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		*out = ft_strjoinfree(*out, buf, 'L');
		count += ret;
	}
	return (count);
}
