/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 15:23:10 by jfortin           #+#    #+#             */
/*   Updated: 2016/02/08 16:43:49 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_findfd(t_list **begin, int fd)
{
	t_list	*tmp;

	tmp = *begin;
	if (tmp)
	{
		while (tmp)
		{
			if (fd == (int)tmp->content_size)
				return (tmp);
			tmp = tmp->next;
		}
	}
	tmp = ft_lstnew("\0", 1);
	tmp->content_size = fd;
	ft_lstadd(begin, tmp);
	return (tmp);
}

static char		*ft_freejoin(char *tmp, char *buf, int ret)
{
	char	*copy;

	copy = tmp;
	tmp = ft_strnjoin(tmp, buf, ret);
	free(copy);
	return (tmp);
}

int				get_next_line(int const fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				ret;
	static t_list	*list = NULL;
	t_list			*begin;
	char			*copy;

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	begin = list;
	list = ft_findfd(&begin, fd);
	while (!ft_strchr(list->content, '\n') && (ret = read(fd, buf, BUFF_SIZE)))
		list->content = ft_freejoin(list->content, buf, ret);
	ret = 0;
	while (((char*)list->content)[ret] && ((char*)list->content)[ret] != '\n')
		++ret;
	*line = ft_strndup(list->content, ret);
	if (((char*)list->content)[ret] == '\n')
		++ret;
	copy = list->content;
	list->content = ft_strdup(list->content + ret);
	free(copy);
	list = begin;
	return (ret ? 1 : 0);
}
